#!/usr/bin/env bash
# Auto-create co-located `_approach.md` notes for NEW problem solution files.
#
# Wired as a UserPromptSubmit hook (see .claude/settings.json). Full workflow
# spec lives in APPROACH_REVIEW.md at the repo root.
#
# What counts as "new" (and therefore gets a note):
#   * a git-UNTRACKED solution file under src/ named pNN_*.rs or pNN_*.cpp
#   * AND no variant of that same problem (pNN_<name>.rs / .cpp) is already
#     git-tracked. If any variant is committed, the problem is treated as
#     COMPLETED/FROZEN and skipped — this respects the "don't touch completed
#     problems" rule even when an extra untracked stub exists (e.g. a p31.rs
#     stub sitting next to an already-committed p31.cpp).
#
# Never writes to stdout (UserPromptSubmit stdout is injected into model
# context — we keep it clean). Progress goes to stderr. Always exits 0 so it
# can never block a prompt.

ROOT="${CLAUDE_PROJECT_DIR:-$(git rev-parse --show-toplevel 2>/dev/null)}"
[ -n "$ROOT" ] || exit 0
cd "$ROOT" 2>/dev/null || exit 0
git rev-parse --is-inside-work-tree >/dev/null 2>&1 || exit 0

while IFS= read -r f; do
  [ -n "$f" ] || continue
  bn="$(basename "$f")"

  # Skip module files and the approach notes themselves.
  case "$bn" in
    mod.rs) continue ;;
    *_approach.md) continue ;;
  esac
  # Only pNN_*.rs / pNN_*.cpp solution files.
  case "$bn" in
    p[0-9]*.rs|p[0-9]*.cpp) : ;;
    *) continue ;;
  esac

  base="${f%.*}"                       # strip extension -> src/.../pNN_name
  approach="${base}_approach.md"
  [ -e "$approach" ] && continue       # note already exists

  # Freeze guard: if any solution variant of this problem is tracked, it is a
  # completed problem — leave it alone.
  tracked="$(git ls-files -- "${base}.rs" "${base}.cpp" 2>/dev/null)"
  [ -n "$tracked" ] && continue

  # Derive header fields from the filename.
  fname="$(basename "$base")"          # pNN_name
  num="${fname%%_*}"                   # pNN
  rest="${fname#*_}"                   # name
  title="$(printf '%s' "$rest" | tr '_' ' ')"
  ext="${f##*.}"
  case "$ext" in
    rs)  lang="rust" ;;
    cpp) lang="cpp" ;;
    *)   lang="$ext" ;;
  esac

  # If both languages exist for this problem, list both files.
  sol_list="$f"
  if [ "$ext" = "rs" ] && [ -e "${base}.cpp" ]; then sol_list="$f, ${base}.cpp"; lang="rust, cpp"; fi
  if [ "$ext" = "cpp" ] && [ -e "${base}.rs" ]; then sol_list="$f, ${base}.rs"; lang="rust, cpp"; fi

  cat > "$approach" <<EOF
# ${num} — ${title}

- Solution file(s): ${sol_list}
- Language: ${lang}
- Status: [ ] approach written   [ ] reviewed

## My Approach
<!-- USER writes here: idea, steps, intuition, the complexity you *think* it is.
     Claude never edits this section. -->


<!-- ==================================================================== -->
<!-- ===============  Below is filled by Claude on review  =============== -->
<!-- ==================================================================== -->

## Review
<!-- correctness, edge cases, bugs, style notes -->

## Comparison — my approach vs. standard/optimal
<!-- same/better/worse, trade-offs -->

## Improvements & Suggestions
<!-- concrete changes; and what already worked well -->

## Proof / Correctness & Complexity
<!-- invariant or reasoning for correctness; time & space; trace/test evidence -->
EOF
  printf 'gen_approach_notes: created %s\n' "$approach" >&2
done < <(git ls-files --others --exclude-standard -- src 2>/dev/null)

exit 0

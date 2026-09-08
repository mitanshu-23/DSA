# Approach Review Workflow

This file is the **persistent instruction set** for the approach-review process.
Claude: read this in full before doing any approach review. The user should not
have to re-explain the process in a new conversation.

---

## Purpose

For each **new** problem going forward, the user first writes their **own approach**
(their idea, steps, intuition) in a co-located note. Then they ask Claude to
**review** it. Claude writes the review **into the same file**, and compares the
user's approach against the standard/optimal one.

---

## Cutoff — do NOT touch already-completed problems

- This workflow applies **only to problems solved after 2026-08-12**.
- All solutions already present in the repo as of that date are **completed and
  frozen** for this purpose. Do **not** create `_approach.md` files or reviews for
  them, and do not modify their code, unless the user explicitly asks.

---

## File convention (co-located, one note per problem)

For a solution at:

```
src/<topic>/<group>/<level>/pNN_<name>.rs      (or .cpp)
```

create a sibling approach note next to it:

```
src/<topic>/<group>/<level>/pNN_<name>_approach.md
```

Use the template at the bottom of this file. If a problem has both `.rs` and `.cpp`,
a single shared `_approach.md` is fine (note which language(s) the approach targets).

### Create the approach note up-front (do NOT wait for a review request)

As soon as a **new problem template** is created — i.e. a new
`src/<topic>/<group>/<level>/pNN_<name>.rs|.cpp` solution file appears (even if it's
still just a `// TODO: implement` stub) — Claude should **immediately create the
sibling `pNN_<name>_approach.md`** from the template, with `## My Approach` left
empty for the user to fill in. Do this proactively whenever Claude becomes aware of
such a new file (the user says they created one, or an opened/new solution file with
no existing approach note shows up), so the note is ready before the user starts
writing. Only skip problems frozen by the cutoff below.

**Automated by a hook.** A `UserPromptSubmit` hook (`.claude/settings.json` →
`.claude/hooks/gen_approach_notes.sh`) runs on every message and auto-creates the
note for any genuinely new problem. "New" = a git-untracked `pNN_*.rs|.cpp` under
`src/` with **no** committed solution variant, so completed problems (whose solutions
are already committed) are never touched — even if an extra untracked stub sits next
to them. Claude should still create a note manually if the hook hasn't run yet (e.g.
right after the file appears mid-conversation).

---

## Who writes what

- **User** writes only the `## My Approach` section.
- **Claude**, on a review request, fills in every section below the divider:
  `Review`, `Comparison`, `Improvements & Suggestions`, `Proof / Correctness & Complexity`.
- **Claude must NOT edit the user's `## My Approach` text.** Add findings in the
  Claude-owned sections only.

---

## Claude's review checklist (do all of these)

1. Read the user's `## My Approach` **and** the actual solution code for that problem.
2. **Correctness:** trace edge cases, look for bugs / off-by-one / overflow / UB.
3. **Proof:** give a short justification (loop invariant or reasoning) for *why* the
   approach is correct, plus **time & space complexity**. Where useful, include a
   concrete trace or test evidence as "proof".
4. **Comparison:** compare the user's approach to the standard/optimal approach —
   what's the same, what's better/worse, trade-offs.
5. **Improvements:** concrete, actionable suggestions; also explicitly call out
   **what already worked well** so it's reinforced.
6. Write all of the above into the same `_approach.md` file under the designated
   headings. Keep the user's section intact.

---

## How the user triggers a review

Any of these means "run the review checklist above on this problem":
- "Review my approach for pNN"
- "Review my approach" while the relevant file (solution or `_approach.md`) is open
- Pointing Claude at a specific `_approach.md`

If the `_approach.md` doesn't exist yet for a new problem, Claude may scaffold it
from the template and ask the user to fill in `## My Approach` (or fill it if the
user has described their approach in chat).

---

## Template for `pNN_<name>_approach.md`

```markdown
# pNN — <Problem Name>

- Solution file(s): src/<topic>/<group>/<level>/pNN_<name>.rs
- Language: <rust | cpp>
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
```

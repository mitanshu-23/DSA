# DSA Sheet — Rust Solutions

My solutions to [Striver's A2Z DSA Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/) implemented in **Rust**.

## Structure

Each topic is a module tree of `group_N/{easy,medium,hard}/pNN_*.{rs,cpp}`. Every
problem file couples the statement, approach notes, and (for Rust) tests.

```
src/
├── arrays/            (Step 3 · 40 problems · groups 01–11)
│   ├── group_01/      (each group has easy/ medium/ hard/)
│   ├── group_02/
│   ├── …
│   └── group_11/
├── binary_search/     (Step 4 · 32 problems · groups 1–3)
│   ├── group_1/       (each group has easy/ medium/ hard/)
│   ├── group_2/
│   └── group_3/
└── strings/           (Step 5 · 15 problems · groups 01–06)
    ├── group_01/      (each group has easy/ medium/ hard/)
    ├── group_02/
    ├── …
    └── group_06/
```

### Conventions

- **One place per problem.** Every solution lives at a deterministic path —
  `src/<topic>/group_<N>/<difficulty>/pNN_<name>.<ext>`. There is no separate
  `solutions/` tree and no guessing whether a problem is solved in Rust or C++.
- **Language rule.** Rust when the exact problem is solvable for free on LeetCode;
  C++ when the problem is GFG-only or LeetCode-Premium (GFG has no Rust judge). When
  both languages exist for a problem they sit side by side in the same folder. cargo
  only compiles `.rs` reachable from the `mod.rs` chain, so co-located `.cpp` files are
  ignored by the build.
- **Neutral group names (no spoilers).** Group folders are plain numbers and each
  problem header shows only `Group: <N>`, so opening a problem never reveals the
  technique. The pattern behind each group lives in the study guides below and in each
  file's gated "Solution Notes" — look there deliberately when you want the hint.

## Tooling

A CLI tool (`dsa_tool.sh`) is included. It is **multi-topic** — pick Arrays, Binary
Search, or Strings and each keeps its own module tree and its own progress file;
the last-used topic is remembered.

- Switch topic from the menu, or pass it as the first argument
- Browse problems by **group/cluster** or **difficulty**
- Auto-generate Rust solution templates with correct function signatures
- Track progress (`next`, `dashboard`) per topic
- Show a topic-specific pattern cheatsheet

```bash
./dsa_tool.sh                    # Menu for the last-used topic (default: binary search)
./dsa_tool.sh arrays next        # Start next unsolved Arrays problem
./dsa_tool.sh arrays dashboard   # Arrays progress
./dsa_tool.sh bs next            # Continue Binary Search
./dsa_tool.sh strings next       # Continue Strings
./dsa_tool.sh dashboard          # View progress (current topic)
./dsa_tool.sh group              # Browse by group / cluster
./dsa_tool.sh cheatsheet         # Pattern reference for the current topic
```

## Topics Covered

| Step | Topic | Problems | Guide | Status |
|------|-------|----------|-------|--------|
| 3 | Arrays | 40 | [ArraysReadme.md](ArraysReadme.md) | 🚧 Scaffolded & CLI-tracked — solving in progress |
| 4 | Binary Search | 32 | [BSReadme.md](BSReadme.md) | ✅ Solved in Rust — CLI-tracked |
| 5 | Strings | 15 | [StringsReadme.md](StringsReadme.md) | 🚧 Scaffolded & CLI-tracked — solving in progress (Step 18 deferred until after Tries/DP) |

> Each guide is a self-contained study companion: per-problem core ideas, LeetCode/GFG links, pattern cheatsheets, and a recommended solve order. All topics have a live `src/` module tree and per-topic progress tracking via `dsa_tool.sh` — generate each problem's Rust template on demand as you start it.

## Build & Run

```bash
cargo build
cargo run
```

## License

[MIT](LICENSE)

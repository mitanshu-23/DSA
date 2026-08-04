# DSA Sheet — Rust Solutions

My solutions to [Striver's A2Z DSA Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/) implemented in **Rust**.

## Structure

Each topic is its own module tree of `group_*/{easy,medium,hard}/pNN_*.rs`, and each
problem file holds the solution plus comments explaining the approach.

```
src/
├── arrays/                       (Step 3 · 40 problems · 11 correlation clusters)
│   ├── group_01_basic_traversal/ (Easy / Medium / Hard)
│   ├── group_02_two_sorted_arrays/
│   ├── … group_03 … group_10 …
│   └── group_11_merge_sort/
└── binary_search/                (Step 4 · 32 problems · 3 groups)
    ├── group_1_1d_arrays/        (Easy / Medium / Hard)
    ├── group_2_answer_space/
    └── group_3_2d_arrays/
```

## Tooling

A CLI tool (`dsa_tool.sh`) is included. It is **multi-topic** — pick Arrays or Binary
Search and each keeps its own module tree and its own progress file; the last-used
topic is remembered.

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
./dsa_tool.sh dashboard          # View progress (current topic)
./dsa_tool.sh group              # Browse by group / cluster
./dsa_tool.sh cheatsheet         # Pattern reference for the current topic
```

## Topics Covered

| Step | Topic | Problems | Guide | Status |
|------|-------|----------|-------|--------|
| 3 | Arrays | 40 | [ArraysReadme.md](ArraysReadme.md) | 🚧 Scaffolded & CLI-tracked — solving in progress |
| 4 | Binary Search | 32 | [BSReadme.md](BSReadme.md) | ✅ Solved in Rust — CLI-tracked |

> Each guide is a self-contained study companion: per-problem core ideas, LeetCode/GFG links, pattern cheatsheets, and a recommended solve order. Both topics have a live `src/` module tree and per-topic progress tracking via `dsa_tool.sh` — generate each problem's Rust template on demand as you start it.

## Build & Run

```bash
cargo build
cargo run
```

## License

[MIT](LICENSE)

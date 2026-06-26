# DSA Sheet — Rust Solutions

My solutions to [Striver's A2Z DSA Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/) implemented in **Rust**.

## Structure

```
src/
└── binary_search/
    ├── group_1_1d_arrays/   (Easy / Medium / Hard)
    ├── group_2_answer_space/ (Easy / Medium / Hard)
    └── group_3_2d_arrays/   (Easy / Medium / Hard)
```

Each problem file contains the solution along with comments explaining the approach.

## Tooling

A CLI tool (`dsa_tool.sh`) is included to:
- Browse problems by **group** or **difficulty**
- Auto-generate Rust solution templates with correct function signatures
- Track progress (`next`, `dashboard`)
- Show a pattern cheatsheet

```bash
./dsa_tool.sh next        # Start next unsolved problem
./dsa_tool.sh dashboard   # View progress
./dsa_tool.sh group       # Browse by group
./dsa_tool.sh difficulty  # Browse by difficulty
./dsa_tool.sh cheatsheet  # Binary Search pattern reference
```

## Topics Covered

| Step | Topic | Problems | Details |
|------|-------|----------|---------|
| 4 | Binary Search | 32 | [BSReadme.md](BSReadme.md) |

## Build & Run

```bash
cargo build
cargo run
```

## License

[MIT](LICENSE)

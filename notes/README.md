# notes/ — Concepts, Techniques & Patterns

A personal knowledge base for **conceptual notes** about algorithms, techniques,
patterns, and gotchas discovered while solving problems. This is the "why/how it
works" layer — kept separate from the solution code and from per-problem reviews.

## How this fits with the rest of the repo

| Where | What it holds |
|-------|---------------|
| `src/**/pNN_*.rs \| .cpp` | The actual solutions (co-located per problem). |
| `src/**/pNN_*_approach.md` | Per-problem approach notes + my reviews (see `APPROACH_REVIEW.md`). |
| `Algorithms.txt` | Flat index of which named algorithm each *solved* problem uses. |
| **`notes/` (here)** | Standalone write-ups of a technique/pattern/concept, reusable across many problems. |

So: a one-off "how I solved p17" goes in that problem's `_approach.md`; a general
technique like "the non-shrinking sliding window" that applies to a *whole class*
of problems goes here.

## Conventions

- One topic per file: `notes/<topic>.md` (e.g. `sliding_window.md`, `two_pointers.md`).
- Inside a topic file, use a `##` section per variant/pattern.
- For each technique, aim to capture: **the idea**, **why it works** (invariant/proof),
  a **template**, at least one **worked example**, and **when to use / when not to**.
- List related problems by name and (if solved) link to the solution file.

## Index

- [Sliding Window](sliding_window.md)
  - Non-Shrinking (fixed-width) Sliding Window — for max-length "at most" problems

<!-- Add new topics above as you write them. -->

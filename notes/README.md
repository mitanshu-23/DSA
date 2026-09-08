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
- [Next Permutation](next_permutation.md)
  - Lexicographic successor in place — pivot, swap, reverse suffix (`O(n)`)
- [Intervals](intervals.md)
  - Sort by start + single sweep — merge overlapping intervals and its family
- [Matrix (2D Array) In-Place Manipulation](matrix.md)
  - First row/column as markers · rotation as disjoint 4-cycles · spiral by four
    shrinking boundaries · using an "impossible sentinel" safely
- [Hashing (Sets & Maps as Lookup Structures)](hashing.md)
  - Complement lookup · endpoint-anchored chain scan and its amortized `Θ(n)` proof ·
    the "dedup into a set, then loop the array anyway" trap that costs you the bound
- [Pascal's Triangle & Binomial Coefficients](pascals_triangle.md)
  - Row-from-previous vs. the `C(r,k+1) = C(r,k)·(r-k)/(k+1)` running product ·
    why the integer division is exact · where `int` and `int64` actually overflow
- [Divide & Conquer: Counting Cross-Pairs During Merge Sort](divide_and_conquer_counting.md)
  - Count during the merge comparison vs. a separate prescan · why either sort
    direction works as long as the counting logic matches it · the `size() - 1`
    empty-container underflow trap

- [Two Pointers / Multi-Cursor Scans](two_pointers.md)
  - Scatter vs. gather (put the cursors on the array you *write*) · why a nested
    `while` is still linear when cursors are monotonic and never reset · `k` cursors
    need `k` complementary predicates · in-place slot filling, and why `O(1)` space
    and order-preservation can't both be linear

<!-- Add new topics above as you write them. -->

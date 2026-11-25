# Striver's A2Z DSA Sheet — Steps 7 + 16: Recursion & Dynamic Programming

> **Source:** [takeuforward.org — Striver's A2Z DSA Sheet](https://takeuforward.org/prep-hub/strivers-a2z-dsa-sheet)
> **YouTube:** [takeUforward Channel](https://www.youtube.com/@takeUforward)
> **Total Problems:** 73 — Part 1 Recursion: 21 (+ 1 theory lesson) · Part 2 DP: 52 (+ 1 theory lesson)
> **Part 1 clusters (1–5):** Implementation Problems (5) · Subsequence Pattern Problems (3 + theory) · FAQs Medium (5) · Hard (1) · FAQs Hard (7)
> **Part 2 clusters (6–13):** 1D DP (5) · 2D DP (1) · Grids (6) · Stocks (6) · Subsequences (11) · LIS (6) · Strings (11) · Partition DP / MCM (6)
>
> **One topic, two parts:** DP is recursion + memoization, so Recursion (Step 7) and DP (Step 16) share this guide, `src/recursion_dp/`, and one tracker: `./dsa_tool.sh rec …` or `./dsa_tool.sh dp …`. [Jump to Part 2 — DP](#part-2--dynamic-programming-step-16--problems-2273).

> **Data source note:** this guide's problem list, links, and difficulty tiers were extracted directly from a saved snapshot of the live takeuforward sheet (its embedded page data), not from memory — so titles, LeetCode links, and tiers below are verified against the actual current sheet. The **Core Idea**, worked examples, and "why revise" commentary are my own added explanations, not sourced from the site.
>
> **Ordering note:** on the *current* live sheet, Recursion's module actually comes **before** Linked List in the sidebar order. This repo built out Linked List first under an older step-numbering assumption (Arrays → Binary Search → Strings → Linked List → Recursion). That's just a historical quirk of when each guide was written — Recursion is still the right next topic either way.
>
> **Difficulty tiers:** the live sheet uses a two-tier system — **Core** (essential) and **Pro** (valuable, more advanced) — not the old Easy/Medium/Hard split. Used throughout this guide.
>
> **No GFG column in the source anymore:** the live sheet's data no longer carries GeeksforGeeks links at all (only LeetCode + takeuforward's own article/video). For the 5 problems below with no LeetCode link either, no GFG link is supplied — add one yourself if you find a good match.

---

## Revision Tier Legend

| Tag | Meaning | When to revisit |
|---|---|---|
| 🔴 Core | Foundational recursion pattern. Interview staple. | Every revision cycle. |
| 🟡 Pro | Harder / more advanced application of the same patterns. | Before interviews / contests. |
| ⚪ Untiered | No tier in the source sheet (only DP problem 33). | Treat as Core — it's a short, common grid-DP question. |

**Quick 🔴 revision list (Core tier):** 1–9, 10–13 (i.e. all of Implementation Problems, Subsequence Pattern Problems, and FAQs Medium except Combination Sum III)
That's 12 out of 21 — recursion's "core" is mastering the decision-tree shape; the "pro" tier is mostly the same shape applied to harder constraint-satisfaction problems.

---

# Part 1 — Recursion (Step 7 · problems 1–21)

## What Is New in Recursion vs Everything Before?

Every topic so far (Arrays, Binary Search, Strings, Linked List) worked with a single pass or a bounded loop over a known structure. Recursion introduces a fundamentally different mental model: **a function that explores a branching decision tree by calling itself**, with the "loop" replaced by the call stack.

| Mental model | Iterative topics so far | Recursion |
|---|---|---|
| Control flow | Loops with explicit counters/pointers | Function calls; the stack frame *is* the loop state |
| State across steps | Variables you update in place | Parameters passed to the next call; state "undoes itself" on return |
| Exploring possibilities | Usually not needed (one path through the data) | Core feature — explore every choice at a decision point, then backtrack |
| Termination | Loop condition on an index/pointer | An explicit **base case** — forget it and you get infinite recursion / a stack overflow |

**New things this step introduces:**
- **Base case** — the condition that stops the recursion; every recursive function needs at least one.
- **Choice / decision tree** — at each call, you either "pick" or "don't pick" the current element (or try every option in a loop), recursing into each branch.
- **Backtracking** — after a recursive call returns, undo whatever you mutated (pop from the current path, flip a visited flag back) so the next branch starts clean. This is what turns plain recursion into *backtracking*.
- **Pruning** — stop exploring a branch early once you know it can't lead to a valid answer (e.g. a partial sum already exceeds the target), which is what keeps exponential-looking problems tractable in practice.

These four ideas cover essentially every problem in this step, from `Pow(x,n)` (simple divide-and-conquer recursion, no backtracking) all the way to Sudoku Solver (backtracking + pruning at every cell).

---

## Smart Solve Order — Correlation Clusters

```
CLUSTER 1 — Implementation Problems (warm-up: recursion without backtracking)
  Pow(x,n)                                    🔴  ← divide-and-conquer recursion anchor
  Generate Parentheses                        🔴  ← first "build a path, recurse, undo" problem
  Power Set                                   🔴  ← pick/don't-pick anchor — reused everywhere after this
  Count Good Numbers                          🔴  ← recursion + modular exponentiation
  Reverse a Stack                             🔴  ← recursion as a replacement for an explicit stack

CLUSTER 2 — Subsequence Pattern Problems (the pick/don't-pick template, formalized)
  (theory) Learn All Patterns of Subsequences 🔴  ← watch/read this before the three below
  Check if a subsequence with sum K exists    🔴  ← pick/don't-pick returning early on success
  Count all subsequences with sum K           🔴  ← same template, counting instead of early-exit
  Generate Binary Strings w/o Consecutive 1s  🔴  ← pick/don't-pick with a validity constraint

CLUSTER 3 — FAQs (Medium) — combination/subset family (do together — same skeleton, different pruning rules)
  Combination Sum                             🔴  ← unbounded pick (can reuse the same element)
  Combination Sum II                          🔴  ← bounded pick + duplicate-skipping at each level
  Subsets I                                   🔴  ← power set again, framed as the "combination" family
  Subsets II                                  🔴  ← Subsets I + duplicate-skipping (same trick as Comb. Sum II)
  Combination Sum III                         🟡  ← Combination Sum + a fixed-count constraint

CLUSTER 4 — Hard
  Letter Combinations of a Phone Number       🟡  ← decision tree branches per digit, not per element

CLUSTER 5 — FAQs (Hard) — backtracking with real pruning (the payoff for everything above)
  Palindrome Partitioning                     🟡  ← partition + a palindrome check as the validity rule
  Word Search                                 🟡  ← backtracking on a grid, with a visited/undo step
  N Queens                                    🟡  ← classic constraint-satisfaction backtracking
  Rat in a Maze                               🟡  ← grid backtracking, same shape as Word Search
  M-Coloring Problem                          🟡  ← constraint-satisfaction on a graph instead of a grid
  Sudoku Solver                               🟡  ← constraint-satisfaction with the most pruning rules at once
  Expression Add Operators                    🟡  ← backtracking over operator choices, with overflow care
```

### Why this order

- **Implementation Problems** come first because none of them *need* backtracking — they establish "a function calls itself and something useful happens on the way back up" without the extra complexity of undoing state.
- **Subsequence Pattern Problems** introduce the pick/don't-pick template in its purest form (include the current element in the recursive call, or don't) — this exact template is reused, with small variations, in every single cluster after it.
- **FAQs (Medium)** is the pick/don't-pick template applied to the classic "find all combinations/subsets" family, where the variation is entirely about *what's allowed to repeat* and *how duplicates are skipped*.
- **Hard** (Letter Combinations) is placed alone because its branching factor is per-digit (up to 4 choices per level) rather than per-element (2 choices per level) — a different shape worth isolating before the grid/graph backtracking cluster.
- **FAQs (Hard)** is last because this is where backtracking's *undo* step and *pruning* actually matter for performance, not just correctness — these problems would time out without them.

---

## 7.1 — Implementation Problems

---

### 1. Pow(x, n) 🔴

**Core Idea:** `x^n = (x^(n/2))^2`, halved each recursive call — this is recursion used as divide-and-conquer, turning an O(n) repeated-multiplication loop into O(log n). Handle odd `n` by peeling off one extra factor of `x`, and handle negative `n` by recursing on `-n` and inverting the result at the end.

**Revise?** Yes — this is the anchor pattern for "recursion that halves the problem size," which reappears directly in Count Good Numbers below.

| Platform | Link |
|---|---|
| LeetCode | [LC — Pow(x, n)](https://leetcode.com/problems/powx-n/) |
| Video | [takeUforward](https://youtu.be/l0YC3876qxg) |

---

### 2. Generate Parentheses 🔴

**Core Idea:** Build a string path one character at a time; at each step you may add `(` if you still have opens remaining, or `)` if you have more opens placed than closes so far. When the path reaches `2n` characters, it's a valid combination — record it and backtrack (remove the last character) to try the other branch.

**Why revise:** First problem in the sheet where "build a path, recurse deeper, then undo the last step before trying the next branch" is the entire algorithm — this exact shape (a mutable path + recurse + pop) is the backbone of every backtracking problem later in this step.

| Platform | Link |
|---|---|
| LeetCode | [LC 22 — Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) |

---

### 3. Power Set 🔴

**Core Idea:** For each element, recurse twice — once including it in the current subset, once excluding it. At the base case (no elements left to decide on), the current subset is one member of the power set.

**Why revise:** THE pick/don't-pick anchor. Nearly every later problem in this step (Subsets I/II, Combination Sum family, even Palindrome Partitioning) is a variation of "for each position, choose to include/split here or not."

```
powerSet(index, current, arr):
    if index == len(arr):
        record current
        return
    # don't pick arr[index]
    powerSet(index+1, current, arr)
    # pick arr[index]
    current.append(arr[index])
    powerSet(index+1, current, arr)
    current.pop()   # backtrack
```

| Platform | Link |
|---|---|
| LeetCode | [LC 78 — Subsets](https://leetcode.com/problems/subsets/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=b7AYbpM5YrE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=67) |

---

### 4. Count Good Numbers 🔴

**Core Idea:** A "good number" has even indices filled with one of 5 even digits and odd indices filled with one of 4 prime digits, so the total count is `5^(ceil(n/2)) * 4^(floor(n/2))`. The recursion is in computing that power efficiently: reuse Pow(x,n)'s halving trick (`binExp`) under a modulus, since `n` can be astronomically large.

**Revise?** No — a direct, small application of problem 1's technique; worth doing once right after Pow(x,n) to see the halving trick reused immediately.

| Platform | Link |
|---|---|
| LeetCode | [LC 1922 — Count Good Numbers](https://leetcode.com/problems/count-good-numbers/) |
| Article | [takeUforward](https://takeuforward.org/blogs/data-structure-and-algorithm/count-good-numbers) |

---

### 5. Reverse a Stack (using recursion) 🔴

**Core Idea:** Pop the top element off, recursively reverse what remains, then insert the popped element at the *bottom* of the now-reversed remainder (itself a second small recursive helper: pop everything off, recurse to the base case, push the held element, then push everything back on the way up). No loop, no second stack — only the call stack is used as auxiliary storage.

**Why revise:** Clean demonstration that recursion *is* an implicit stack — useful to internalize before Sudoku/N-Queens, where you'll reason about "what's still on the call stack" constantly.

| Platform | Link |
|---|---|
| (No LeetCode/GFG link in the current sheet data — classic GFG-style problem; implement against your own stack type.) | |

---

## 7.2 — Subsequence Pattern Problems

> Watch/read **"Learn All Patterns of Subsequences"** (the sheet's theory lesson for this cluster) before attempting the three problems below — it lays out the pick/don't-pick recursion tree explicitly, which these three problems then apply with small variations (early-exit, counting, and an extra validity constraint).

---

### 6. Check if There Exists a Subsequence with Sum K 🔴

**Core Idea:** Same pick/don't-pick recursion as Power Set, but instead of recording every subset, return `true` the moment a recursive branch reaches `sum == K`, and `false` once you run out of elements without hitting it. The first branch (include the current element) is checked first so a match short-circuits the second branch.

**Revise?** No — this is the "early exit" variant of the subsequence template; quick once Power Set is solid.

| Platform | Link |
|---|---|
| (No LeetCode/GFG link in the current sheet data.) | |

---

### 7. Count All Subsequences with Sum K 🔴

**Core Idea:** Identical recursion tree to problem 6, except every branch that reaches `sum == K` at the base case contributes `1` to a running count instead of short-circuiting — `return leftBranchCount + rightBranchCount` instead of `return leftBranchFound || rightBranchFound`.

**Revise?** No — side-by-side with problem 6, this is the clearest illustration of "early-exit boolean vs. full count" as two faces of the same recursion.

| Platform | Link |
|---|---|
| (No LeetCode/GFG link in the current sheet data.) | |

---

### 8. Generate Binary Strings Without Consecutive 1s 🔴

**Core Idea:** Build a string one bit at a time; you may always place a `0`, but may only place a `1` if the previous character placed wasn't also `1`. Track "last character placed" as recursion state (or just inspect the last character of the path built so far) to enforce this constraint at each branch.

**Why revise:** First problem where the pick/don't-pick template gets an extra **validity check** gating one of the branches — exactly the shape that becomes "pruning" in the harder backtracking problems later.

| Platform | Link |
|---|---|
| (No LeetCode/GFG link in the current sheet data.) | |

---

## 7.3 — FAQs (Medium)

---

### 9. Combination Sum 🔴

**Core Idea:** Pick/don't-pick on the current candidate, but picking it **doesn't advance the index** (the same number can be reused unlimited times), while not-picking does advance. Prune a branch the moment the running sum exceeds the target.

**Revise?** No, but note the "reuse by not advancing the index" trick carefully — it's exactly what changes in Combination Sum II.

| Platform | Link |
|---|---|
| LeetCode | [LC 39 — Combination Sum](https://leetcode.com/problems/combination-sum/) |
| Article | [takeUforward](https://takeuforward.org/blogs/data-structure-and-algorithm/combination-sum) |
| Video | [takeUforward](https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=49) |

---

### 10. Combination Sum II 🔴

**Core Idea:** Each element can now be used **at most once** (so picking always advances the index), and the input may contain duplicates — sort first, then at each recursion level, skip over a candidate if it's the same value as the one tried immediately before it *at that same level* (not skipping within a single branch's own path, only across sibling branches), to avoid generating the same combination twice.

**Why revise:** The duplicate-skip-at-the-same-level trick here is the single most commonly forgotten detail in this whole step — it reappears verbatim in Subsets II.

| Platform | Link |
|---|---|
| LeetCode | [LC 40 — Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=50) |

---

### 11. Subsets I 🔴

**Core Idea:** The exact same algorithm as Power Set (problem 3) — included again here under the "combination family" framing since Subsets II right after it needs Subsets I as a baseline for comparison.

**Revise?** No — if Power Set (problem 3) is solid, this is free.

| Platform | Link |
|---|---|
| LeetCode | [LC 78 — Subsets](https://leetcode.com/problems/subsets/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=52) |

---

### 12. Subsets II 🔴

**Core Idea:** Subsets I plus the same duplicate-skip-at-the-same-level trick from Combination Sum II: sort the input, then at each recursion level skip a candidate if it equals the previous sibling candidate at that level.

**Why revise:** Direct proof that the duplicate-skip trick is reusable across both the "sum" family and the "subset" family — worth doing right after Combination Sum II to cement that it's one trick, not two.

| Platform | Link |
|---|---|
| LeetCode | [LC 90 — Subsets II](https://leetcode.com/problems/subsets-ii/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=53) |

---

### 13. Combination Sum III 🟡

**Core Idea:** Combination Sum's "unlimited reuse, hit the target sum" shape, with two extra constraints layered on: each number 1–9 may be used **at most once**, and a valid combination must use **exactly k** numbers, not any number of them. Prune on sum exceeding target *and* on running out of remaining picks before reaching k.

**Why revise:** First "pro" problem — same skeleton as problem 9, but two independent pruning conditions instead of one is where bugs start creeping in if the base case isn't precise.

| Platform | Link |
|---|---|
| LeetCode | [LC 216 — Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) |

---

## 7.4 — Hard

---

### 14. Letter Combinations of a Phone Number 🟡

**Core Idea:** Recurse one digit at a time (not one element at a time); at each level, branch once per letter mapped to the current digit (2–4 branches depending on the digit, e.g. `7` → `pqrs`), appending the chosen letter to the path and recursing to the next digit. Base case: path length equals the number of digits.

**Why revise:** The branching factor is *per digit from a lookup table*, not *per array element* like every problem before it — a different flavor of the same decision-tree idea, and a good bridge to the grid/graph backtracking in the next cluster.

| Platform | Link |
|---|---|
| LeetCode | [LC 17 — Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) |

---

## 7.5 — FAQs (Hard)

---

### 15. Palindrome Partitioning 🟡

**Core Idea:** At each position, try every possible "next cut" from the current index to the end of the string; recurse only into cuts where the substring between the current index and the cut is itself a palindrome. A full partition is found when the current index reaches the end of the string.

**Why revise:** First problem where the *validity check gating a branch* (problem 8's idea) is itself a nontrivial function (a palindrome check) rather than an O(1) comparison — a preview of how much more expensive "pruning" can get.

| Platform | Link |
|---|---|
| LeetCode | [LC 131 — Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) |
| Article | [takeUforward](https://takeuforward.org/blogs/data-structure-and-algorithm/palindromic-partitioning) |
| Video | [takeUforward](https://youtu.be/_H8V5hJUGd0) |

---

### 16. Word Search 🟡

**Core Idea:** From each grid cell, recurse into the 4 neighbors looking for the next character of the target word, marking the current cell visited before recursing and **un**marking it (backtrack) after — so a path can't reuse a cell, but a *different* path starting elsewhere can still use it.

**Why revise:** Canonical grid backtracking: the "mark visited → recurse → unmark" pattern here is reused directly in Rat in a Maze.

| Platform | Link |
|---|---|
| LeetCode | [LC 79 — Word Search](https://leetcode.com/problems/word-search/) |

---

### 17. N Queens 🟡

**Core Idea:** Place one queen per row; at each row, try every column, and only recurse into the next row if the placement doesn't share a column, or either diagonal, with any queen already placed. Record a full board when all rows have a queen.

**Why revise:** The textbook constraint-satisfaction backtracking problem — three independent "is this safe" checks (column, and both diagonals) gating every branch, which is exactly the shape M-Coloring and Sudoku scale up further.

| Platform | Link |
|---|---|
| LeetCode | [LC 51 — N-Queens](https://leetcode.com/problems/n-queens/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=57) |

---

### 18. Rat in a Maze 🟡

**Core Idea:** Same grid-backtracking shape as Word Search — from the current cell, try each direction (commonly in a fixed order, e.g. Down, Left, Right, Up, to produce lexicographically-sorted paths), recurse if the next cell is in-bounds, unblocked, and unvisited, mark it visited before recursing and unmark it after. A path is complete when the rat reaches the bottom-right cell.

**Revise?** No, once Word Search's visited/unvisited pattern is solid — this is the same idea with a different goal condition.

| Platform | Link |
|---|---|
| Article | [takeUforward](https://takeuforward.org/blogs/data-structure-and-algorithm/rat-in-a-maze) |
| Video | [takeUforward](https://www.youtube.com/watch?v=bLGZhJlt4y0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=60) |

---

### 19. M-Coloring Problem 🟡

**Core Idea:** Assign a color (1..M) to each vertex in turn; at each vertex, try every color and only recurse into the next vertex if no already-colored *adjacent* vertex shares that color. If every vertex gets colored, a valid M-coloring exists.

**Why revise:** Same constraint-satisfaction shape as N-Queens, but the "is this safe" check is against **graph adjacency** instead of a grid's geometry — a good checkpoint for whether the pattern has generalized in your head beyond "grids."

| Platform | Link |
|---|---|
| Video | [takeUforward](https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=59) |

---

### 20. Sudoku Solver 🟡

**Core Idea:** Find the next empty cell; try digits 1–9 in it, recursing to solve the rest of the board only if that digit doesn't already appear in the current row, column, or 3×3 box. If a full recursive attempt fails, backtrack by resetting the cell to empty and trying the next digit.

**Why revise:** The most pruning conditions combined in one problem in this entire step (row + column + box, re-checked at every single cell) — the natural "final exam" for the backtracking skeleton built up across this whole cluster.

| Platform | Link |
|---|---|
| LeetCode | [LC 37 — Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=FWAIf_EVUKE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=58) |

---

### 21. Expression Add Operators 🟡

**Core Idea:** Recurse through the digit string deciding, at each position, how many digits to take as the next operand and which operator (`+`, `-`, `*`, or none yet, for the very first operand) to place before it. Track the running evaluated value *and* the value of the last operand separately, since undoing the precedence of a just-applied `*` requires subtracting out the previous operand's contribution before redoing the multiplication. Skip operand choices with a leading zero (other than the single digit `"0"` itself) — they aren't valid number literals.

**Why revise:** The hardest problem in this step — backtracking over operator choices *and* operand-length choices simultaneously, with the one genuinely fiddly piece of bookkeeping in this entire guide (undoing multiplication precedence). Save for last.

| Platform | Link |
|---|---|
| LeetCode | [LC 282 — Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) |

---

## Full Problem Table

| # | Problem | Cluster | Tier | Pattern | LeetCode |
|---|---|---|---|---|---|
| 1 | Pow(x, n) | Implementation | 🔴 Core | Halving recursion | [LC](https://leetcode.com/problems/powx-n/) |
| 2 | Generate Parentheses | Implementation | 🔴 Core | Build-path + backtrack | [LC 22](https://leetcode.com/problems/generate-parentheses/) |
| 3 | Power Set | Implementation | 🔴 Core | Pick/don't-pick anchor | [LC 78](https://leetcode.com/problems/subsets/) |
| 4 | Count Good Numbers | Implementation | 🔴 Core | Modular halving recursion | [LC 1922](https://leetcode.com/problems/count-good-numbers/) |
| 5 | Reverse a Stack | Implementation | 🔴 Core | Recursion as implicit stack | — |
| — | *Learn All Patterns of Subsequences (theory)* | Subsequence | 🔴 Core | — | — |
| 6 | Check Subsequence Sum K Exists | Subsequence | 🔴 Core | Pick/don't-pick, early exit | — |
| 7 | Count Subsequences Sum K | Subsequence | 🔴 Core | Pick/don't-pick, counting | — |
| 8 | Generate Binary Strings w/o Consecutive 1s | Subsequence | 🔴 Core | Pick/don't-pick + validity gate | — |
| 9 | Combination Sum | FAQs Medium | 🔴 Core | Unbounded pick + sum prune | [LC 39](https://leetcode.com/problems/combination-sum/) |
| 10 | Combination Sum II | FAQs Medium | 🔴 Core | Bounded pick + dup-skip | [LC 40](https://leetcode.com/problems/combination-sum-ii/) |
| 11 | Subsets I | FAQs Medium | 🔴 Core | Pick/don't-pick anchor | [LC 78](https://leetcode.com/problems/subsets/) |
| 12 | Subsets II | FAQs Medium | 🔴 Core | Pick/don't-pick + dup-skip | [LC 90](https://leetcode.com/problems/subsets-ii/) |
| 13 | Combination Sum III | FAQs Medium | 🟡 Pro | Unbounded pick + count + sum prune | [LC 216](https://leetcode.com/problems/combination-sum-iii/) |
| 14 | Letter Combinations of a Phone Number | Hard | 🟡 Pro | Per-digit branching | [LC 17](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) |
| 15 | Palindrome Partitioning | FAQs Hard | 🟡 Pro | Cut + palindrome validity gate | [LC 131](https://leetcode.com/problems/palindrome-partitioning/) |
| 16 | Word Search | FAQs Hard | 🟡 Pro | Grid backtracking (visited/unvisited) | [LC 79](https://leetcode.com/problems/word-search/) |
| 17 | N Queens | FAQs Hard | 🟡 Pro | Constraint satisfaction (grid) | [LC 51](https://leetcode.com/problems/n-queens/) |
| 18 | Rat in a Maze | FAQs Hard | 🟡 Pro | Grid backtracking (visited/unvisited) | — |
| 19 | M-Coloring Problem | FAQs Hard | 🟡 Pro | Constraint satisfaction (graph) | — |
| 20 | Sudoku Solver | FAQs Hard | 🟡 Pro | Constraint satisfaction (grid, 3 rules) | [LC 37](https://leetcode.com/problems/sudoku-solver/) |
| 21 | Expression Add Operators | FAQs Hard | 🟡 Pro | Backtracking + operand/operator choice | [LC 282](https://leetcode.com/problems/expression-add-operators/) |

---

## Pattern Quick Reference

### Pick / Don't-Pick (the core template)
```
solve(index, current, arr):
    if index == len(arr):
        process(current)
        return
    solve(index + 1, current, arr)              # don't pick
    current.append(arr[index])
    solve(index + 1, current, arr)              # pick
    current.pop()                                # backtrack
```

### Backtracking with a Validity Gate
```
solve(index, current, arr):
    if index == len(arr):
        if isValid(current): process(current)
        return
    for choice in choicesAt(index):
        if not allowed(choice, current):         # the "gate" / pruning condition
            continue
        current.append(choice)
        solve(index + 1, current, arr)
        current.pop()                             # backtrack
```

### Grid Backtracking (visited/unvisited)
```
dfs(r, c, ...):
    if outOfBounds(r, c) or visited[r][c] or not matches(r, c): return False
    if goalReached(...): return True
    visited[r][c] = True
    found = dfs(r+1,c,...) or dfs(r-1,c,...) or dfs(r,c+1,...) or dfs(r,c-1,...)
    visited[r][c] = False                         # backtrack
    return found
```

### Constraint Satisfaction (N-Queens / M-Coloring / Sudoku shape)
```
solve(position):
    if allPositionsFilled(): recordSolution(); return True   # or keep searching for all solutions
    for candidate in candidatesFor(position):
        if isSafe(candidate, position):            # check all constraints at once
            place(candidate, position)
            if solve(position + 1): return True     # or just recurse without early return, to find all
            unplace(candidate, position)             # backtrack
    return False
```

---

# Part 2 — Dynamic Programming (Step 16 · problems 22–73)

> **Why it lives here:** DP is recursion + memoization. Every problem below starts as a Part 1 recursion (usually pick / don't-pick), so the two steps share one guide, one `src/recursion_dp/` tree and one progress file. Numbering continues from Part 1.
>
> **Source:** the same saved sheet snapshot as Part 1 — 52 problems + 1 theory lesson + 1 contest (the contest is not tracked). Two link quirks in the source: *Evaluate Boolean Expression to True* (73) is linked to LeetCode 1106, which is a different problem, so no link is stored; *Count Palindromic Subsequences* (67) is linked to LeetCode 2484, the length-5 variant, and is described as that problem. *Count Square Submatrices* (33) has no tier in the source (⚪).

---

## What Is New in DP vs Recursion?

Part 1's recursion trees revisit the same sub-problem many times (Fibonacci-style overlap). DP removes that waste in four standard steps — practise **all four for every problem**, since interviewers often ask for the next one:

| Step | What you write | Typical cost |
|---|---|---|
| 1. Recursion | `f(state)` with base cases, exactly as in Part 1 | exponential |
| 2. Memoization (top-down) | same function + `dp[state]` cache, initialised to -1 | O(#states × work per state) time, + recursion stack |
| 3. Tabulation (bottom-up) | loops over states in dependency order, base cases written first | same time, no recursion stack |
| 4. Space optimisation | keep only the previous row/values the recurrence reads | usually O(n·m) → O(m) |

**How to find the recurrence:** (1) express the problem in terms of an index (or two, or a range `i..j`); (2) try every choice at that index; (3) combine with `min`, `max`, `+` (count) or `||` (exists); (4) the base case is where the index runs out.

---

## Smart Solve Order — DP Clusters

```

CLUSTER 6 — 1D DP
  22 Climbing Stairs                                      🔴  ← f(i) = f(i-1) + f(i-2)
  23 Frog Jump                                            🔴  ← min over last 2 moves
  24 Frog Jump with K Distances                           🔴  ← min over last k moves
  25 Maximum Sum of Non-Adjacent Elements (House Robber)  🔴  ← pick / not-pick
  26 House Robber II                                      🔴  ← pick / not-pick (circular)

CLUSTER 7 — 2D DP
  27 Ninja's Training                                     🔴  ← state = (day, last task)

CLUSTER 8 — DP on Grids
  28 Grid Unique Paths                                    🔴  ← grid paths (right/down)
  29 Unique Paths II                                      🟡  ← grid paths + obstacles
  30 Minimum Falling Path Sum                             🔴  ← grid, variable start/end
  31 Triangle                                             🔴  ← grid, fixed start, variable end
  32 Cherry Pickup II                                     🟡  ← 3D DP — two walkers
  33 Count Square Submatrices with All Ones               ⚪  ← square-ending-here DP

CLUSTER 9 — DP on Stocks
  34 Best Time to Buy and Sell Stock                      🔴  ← running min
  35 Best Time to Buy and Sell Stock II                   🔴  ← state = (day, holding?)
  36 Best Time to Buy and Sell Stock III                  🟡  ← state = (day, holding?, txns left)
  37 Best Time to Buy and Sell Stock IV                   🟡  ← state = (day, holding?, txns left)
  38 Best Time to Buy and Sell Stock with Transaction Fee 🔴  ← state = (day, holding?)
  39 Best Time to Buy and Sell Stock with Cooldown        🔴  ← state = (day, holding?)

CLUSTER 10 — DP on Subsequences
  40 Subset Sum Equal to Target                           🔴  ← pick / not-pick on (index, target)
  41 Partition Equal Subset Sum                           🔴  ← subset sum
  42 Partition a Set into Two Subsets with Minimum Absolute Sum Difference 🟡  ← subset sum (whole last row)
  43 Count Subsets with Sum K                             🔴  ← counting subset sum
  44 Count Partitions with Given Difference               🔴  ← counting subset sum
  45 0/1 Knapsack                                         🔴  ← pick / not-pick on (index, capacity)
  46 Minimum Coins (Coin Change)                          🔴  ← unbounded pick
  47 Target Sum                                           🔴  ← counting subset sum
  48 Coin Change II                                       🟡  ← unbounded counting
  49 Unbounded Knapsack                                   🔴  ← unbounded pick
  50 Rod Cutting                                          🟡  ← unbounded knapsack

CLUSTER 11 — Longest Increasing Subsequence
  51 Longest Increasing Subsequence                       🔴  ← LIS
  52 Print Longest Increasing Subsequence                 🟡  ← LIS + parent array
  53 Largest Divisible Subset                             🔴  ← LIS on a custom relation
  54 Longest String Chain                                 🔴  ← LIS on a custom relation
  55 Longest Bitonic Subsequence                          🔴  ← LIS from both ends
  56 Number of Longest Increasing Subsequences            🔴  ← LIS + count array

CLUSTER 12 — DP on Strings
  57 Longest Common Subsequence                           🔴  ← two-string DP (match / skip)
  58 Longest Common Substring                             🔴  ← two-string DP (contiguous)
  59 Longest Palindromic Subsequence                      🔴  ← LCS(s, reverse(s))
  60 Minimum Insertions to Make a String Palindrome       🟡  ← n - LPS
  61 Minimum Insertions/Deletions to Convert String A to B 🔴  ← n + m - 2·LCS
  62 Shortest Common Supersequence                        🟡  ← LCS table + backtrack
  63 Distinct Subsequences                                🟡  ← two-string counting DP
  64 Edit Distance                                        🟡  ← two-string DP (3 operations)
  65 Wildcard Matching                                    🟡  ← two-string DP (pattern)
  66 Word Break                                           🔴  ← prefix DP
  67 Count Palindromic Subsequences (length 5)            🟡  ← prefix/suffix pair counts

CLUSTER 13 — Partition DP (MCM)
  68 Matrix Chain Multiplication                          🟡  ← partition DP f(i, j)
  69 Burst Balloons                                       🟡  ← partition DP (last action)
  70 Palindrome Partitioning II                           🟡  ← front partition
  71 Partition Array for Maximum Sum                      🟡  ← front partition
  72 Minimum Cost to Cut a Stick                          🟡  ← partition DP f(i, j)
  73 Evaluate Boolean Expression to True                  🟡  ← partition DP with a true/false flag
```

### Why this order

- **1D → 2D → Grids** grow the state one dimension at a time: an index, then (index, last choice), then (row, col), then (row, col1, col2).
- **Stocks** is one state machine `(day, canBuy[, transactions left])`; each variant changes a single transition.
- **Subsequences** is Part 1's pick / don't-pick memoized on `(index, target)`. Subset Sum → Knapsack → Unbounded Knapsack in order, because each reuses the last table.
- **LIS** shows a different 1D shape (`dp[i]` = best ending at `i`) plus how to rebuild an answer from parent pointers.
- **Strings** run two indices over two strings; LCS is the anchor and most of the group is LCS reused.
- **Partition DP** (`f(i, j)` over every split point) is the hardest shape, so it comes last.

---

## 16.1 — 1D DP

---

### 22. Climbing Stairs 🔴

**Core Idea:** ways(i) = ways(i-1) + ways(i-2) — Fibonacci; memoize, then tabulate, then keep just two variables.

**Pattern:** f(i) = f(i-1) + f(i-2) · **LeetCode difficulty / used for folder:** Easy

| Platform | Link |
|---|---|
| LeetCode | [LC — climbing-stairs](https://leetcode.com/problems/climbing-stairs/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/climbing-stairs) |
| Video | [takeUforward](https://youtu.be/mLfjzJsN8us) |

---

### 23. Frog Jump 🔴

**Core Idea:** dp[i] = min(dp[i-1] + ORh[i]-h[i-1]OR, dp[i-2] + ORh[i]-h[i-2]OR); the greedy cheapest-next-step choice is wrong, which is why DP is needed.

**Pattern:** min over last 2 moves · **LeetCode difficulty / used for folder:** Easy

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/frog-jump-minimum-energy) |
| Video | [takeUforward](https://www.youtube.com/watch?v=EgG3jsGoPvQ) |

---

### 24. Frog Jump with K Distances 🔴

**Core Idea:** Frog Jump generalised: dp[i] = min over j in 1..=k of dp[i-j] + ORh[i]-h[i-j]OR — O(n·k).

**Pattern:** min over last k moves · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/frog-jump-with-k-distances) |
| Video | [takeUforward](https://www.youtube.com/watch?v=Kmh3rhyEtB8) |

---

### 25. Maximum Sum of Non-Adjacent Elements (House Robber) 🔴

**Core Idea:** dp[i] = max(nums[i] + dp[i-2], dp[i-1]) — the recursion-step pick/don't-pick tree, memoized.

**Pattern:** pick / not-pick · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — house-robber](https://leetcode.com/problems/house-robber/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/maximum-sum-of-non-adjacent-elements) |
| Video | [takeUforward](https://www.youtube.com/watch?v=GrMBfJNk_NY) |

---

### 26. House Robber II 🔴

**Core Idea:** Houses are in a circle, so first and last can't both be robbed: answer = max(rob(nums[0..n-1]), rob(nums[1..n])); n == 1 is a special case.

**Pattern:** pick / not-pick (circular) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — house-robber-ii](https://leetcode.com/problems/house-robber-ii/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/house-robber-ii) |
| Video | [takeUforward](https://www.youtube.com/watch?v=3WaxQMELSkw) |

---

## 16.2 — 2D DP

---

### 27. Ninja's Training 🔴

**Core Idea:** dp[day][last] = max over task != last of points[day][task] + dp[day-1][task]; the extra 'last task' dimension is what makes it 2D.

**Pattern:** state = (day, last task) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/ninjas-training) |
| Video | [takeUforward](https://www.youtube.com/watch?v=AE39gJYuRog) |

---

## 16.3 — DP on Grids

---

### 28. Grid Unique Paths 🔴

**Core Idea:** dp[i][j] = dp[i-1][j] + dp[i][j-1] with the first row/column = 1; space-optimise to one row.

**Pattern:** grid paths (right/down) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — unique-paths](https://leetcode.com/problems/unique-paths/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/grid-unique-paths) |
| Video | [takeUforward](https://www.youtube.com/watch?v=sdE0A2Oxofw) |

---

### 29. Unique Paths II 🟡

**Core Idea:** Unique Paths, but a cell with an obstacle contributes 0 paths; careful: an obstacle in the first row/column blocks everything after it.

**Pattern:** grid paths + obstacles · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — unique-paths-ii](https://leetcode.com/problems/unique-paths-ii/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/unique-paths-ii-obstacles) |
| Video | [takeUforward](https://www.youtube.com/watch?v=TmhpgXScLyY) |

---

### 30. Minimum Falling Path Sum 🔴

**Core Idea:** dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]); answer is the min of the last row (any start, any end).

**Pattern:** grid, variable start/end · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — minimum-falling-path-sum](https://leetcode.com/problems/minimum-falling-path-sum/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/minimum-falling-path-sum) |
| Video | [takeUforward](https://youtu.be/_rgTlyky1uQ) |

---

### 31. Triangle 🔴

**Core Idea:** Go bottom-up: dp[i][j] = tri[i][j] + min(dp[i+1][j], dp[i+1][j+1]); the answer lands in dp[0][0] with no min-over-last-row needed.

**Pattern:** grid, fixed start, variable end · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — triangle](https://leetcode.com/problems/triangle/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/triangle-minimum-path-sum) |
| Video | [takeUforward](https://www.youtube.com/watch?v=SrP-PiLSYC0) |

---

### 32. Cherry Pickup II 🟡

**Core Idea:** Move both robots one row at a time: state (row, c1, c2), 9 move combinations per step; if c1 == c2 count the cell once — 3D DP.

**Pattern:** 3D DP — two walkers · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — cherry-pickup-ii](https://leetcode.com/problems/cherry-pickup-ii/) |

---

### 33. Count Square Submatrices with All Ones ⚪

**Core Idea:** dp[i][j] = largest all-ones square with bottom-right corner (i,j) = 1 + min(top, left, top-left) when the cell is 1; sum every dp[i][j].

**Pattern:** square-ending-here DP · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — count-square-submatrices-with-all-ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/count-square-submatrices-with-all-ones) |
| Video | [takeUforward](https://youtu.be/auS1fynpnjo) |

---

## 16.4 — DP on Stocks

---

### 34. Best Time to Buy and Sell Stock 🔴

**Core Idea:** One transaction: track the minimum price so far and the best price - min_so_far — the 'DP' is just remembering one value from the past.

**Pattern:** running min · **LeetCode difficulty / used for folder:** Easy

| Platform | Link |
|---|---|
| LeetCode | [LC — best-time-to-buy-and-sell-stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/best-time-to-buy-and-sell-stock) |
| Video | [takeUforward](https://youtu.be/excAOvwF_Wk) |

---

### 35. Best Time to Buy and Sell Stock II 🔴

**Core Idea:** Unlimited transactions: dp[i][buy] — if allowed to buy, max(-p + dp[i+1][0], dp[i+1][1]); if holding, max(p + dp[i+1][1], dp[i+1][0]). This (day, canBuy) template powers the rest of the group.

**Pattern:** state = (day, holding?) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — best-time-to-buy-and-sell-stock-ii](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/best-time-to-buy-and-sell-stock-ii) |
| Video | [takeUforward](https://youtu.be/nGJmxkUJQGs) |

---

### 36. Best Time to Buy and Sell Stock III 🟡

**Core Idea:** Stock II with a third dimension: transactions remaining (cap 2); a sale decrements it. Equivalent compact form: 4 states buy1/sell1/buy2/sell2.

**Pattern:** state = (day, holding?, txns left) · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — best-time-to-buy-and-sell-stock-iii](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/best-time-to-buy-and-sell-stock-iii) |
| Video | [takeUforward](https://youtu.be/-uQGzhYj8BQ) |

---

### 37. Best Time to Buy and Sell Stock IV 🟡

**Core Idea:** Stock III with the cap 2 replaced by k — same 3D DP, O(n·k).

**Pattern:** state = (day, holding?, txns left) · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — best-time-to-buy-and-sell-stock-iv](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/best-time-to-buy-and-sell-stock-iv) |
| Video | [takeUforward](https://youtu.be/IV1dHbk5CDc) |

---

### 38. Best Time to Buy and Sell Stock with Transaction Fee 🔴

**Core Idea:** Stock II, subtracting fee once per completed transaction (on the sell).

**Pattern:** state = (day, holding?) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — best-time-to-buy-and-sell-stock-with-transaction-fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/best-time-to-buy-and-sell-stock-with-transaction-fee) |
| Video | [takeUforward](https://youtu.be/k4eK-vEmnKg) |

---

### 39. Best Time to Buy and Sell Stock with Cooldown 🔴

**Core Idea:** Stock II, except a sale on day i jumps to day i+2 (the cooldown) instead of i+1.

**Pattern:** state = (day, holding?) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — best-time-to-buy-and-sell-stock-with-cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/best-time-to-buy-and-sell-stock-with-cooldown) |
| Video | [takeUforward](https://youtu.be/IGIe46xw3YY) |

---

## 16.5 — DP on Subsequences

---

### 40. Subset Sum Equal to Target 🔴

**Core Idea:** Recursion's 'subsequence with sum K exists', memoized on (index, remaining target): dp[i][t] = dp[i-1][t] OROR dp[i-1][t-arr[i]].

**Pattern:** pick / not-pick on (index, target) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/subset-sum-equal-to-target) |
| Video | [takeUforward](https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=52) |

---

### 41. Partition Equal Subset Sum 🔴

**Core Idea:** Odd total → false; otherwise run Subset Sum with target = total / 2.

**Pattern:** subset sum · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — partition-equal-subset-sum](https://leetcode.com/problems/partition-equal-subset-sum/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/partition-equal-subset-sum) |
| Video | [takeUforward](https://www.youtube.com/watch?v=7win3dcgo3k) |

---

### 42. Partition a Set into Two Subsets with Minimum Absolute Sum Difference 🟡

**Core Idea:** Fill the Subset Sum table for target = total; every reachable s1 gives diff ORtotal - 2·s1OR; take the minimum. (LC 1049 is the same problem: smashing stones = giving each a + or - sign).

**Pattern:** subset sum (whole last row) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — last-stone-weight-ii](https://leetcode.com/problems/last-stone-weight-ii/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=GS_OqZb2CWc) |

---

### 43. Count Subsets with Sum K 🔴

**Core Idea:** Recursion's 'count subsequences with sum K', memoized: dp[i][t] = dp[i-1][t] + dp[i-1][t-arr[i]]. Zeros matter — the base case at index 0 must count both picking and skipping a 0.

**Pattern:** counting subset sum · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/count-subsets-with-sum-k) |
| Video | [takeUforward](https://www.youtube.com/watch?v=ZHyb-A2Mte4) |

---

### 44. Count Partitions with Given Difference 🔴

**Core Idea:** s1 - s2 = d and s1 + s2 = total ⇒ s2 = (total - d) / 2; reject if negative or odd, otherwise it's Count Subsets with Sum K.

**Pattern:** counting subset sum · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/count-partitions-with-a-given-difference) |
| Video | [takeUforward](https://www.youtube.com/watch?v=zoilQD1kYSg) |

---

### 45. 0/1 Knapsack 🔴

**Core Idea:** dp[i][cap] = max(dp[i-1][cap], val[i] + dp[i-1][cap-wt[i]]) — THE template for this whole group; space-optimise to one row iterating capacity right-to-left.

**Pattern:** pick / not-pick on (index, capacity) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/01-knapsack) |
| Video | [takeUforward](https://youtu.be/GqOmJHQZivw) |

---

### 46. Minimum Coins (Coin Change) 🔴

**Core Idea:** Unbounded pick: taking a coin stays on the same index. dp[i][amt] = min(dp[i-1][amt], 1 + dp[i][amt-coin[i]]); unreachable → -1.

**Pattern:** unbounded pick · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — coin-change](https://leetcode.com/problems/coin-change/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/minimum-coins) |
| Video | [takeUforward](https://www.youtube.com/watch?v=myPeWb3Y68A) |

---

### 47. Target Sum 🔴

**Core Idea:** Assigning +/- splits nums into P and N with P - N = target — exactly Count Partitions with Given Difference.

**Pattern:** counting subset sum · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — target-sum](https://leetcode.com/problems/target-sum/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=b3GD8263-PQ) |

---

### 48. Coin Change II 🟡

**Core Idea:** Counting version of Minimum Coins: dp[i][amt] = dp[i-1][amt] + dp[i][amt-coin[i]] — iterating coins in the outer loop counts combinations, not permutations.

**Pattern:** unbounded counting · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — coin-change-ii](https://leetcode.com/problems/coin-change-ii/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/coin-change-ii-combinations) |
| Video | [takeUforward](https://www.youtube.com/watch?v=HgyouUi11zk) |

---

### 49. Unbounded Knapsack 🔴

**Core Idea:** 0/1 Knapsack, but taking an item stays on the same index: dp[i][cap] = max(dp[i-1][cap], val[i] + dp[i][cap-wt[i]]); one-row version iterates capacity left-to-right.

**Pattern:** unbounded pick · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/unbounded-knapsack) |
| Video | [takeUforward](https://youtu.be/OgvOZ6OrJoY) |

---

### 50. Rod Cutting 🟡

**Core Idea:** Unbounded Knapsack with piece length i+1 as the weight, price[i] as the value, and n as the capacity.

**Pattern:** unbounded knapsack · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/rod-cutting-problem) |
| Video | [takeUforward](https://youtu.be/mO8XpGoJwuo) |

---

## 16.6 — Longest Increasing Subsequence

---

### 51. Longest Increasing Subsequence 🔴

**Core Idea:** dp[i] = 1 + max dp[j] over j < i with nums[j] < nums[i] (O(n²)); the optimal O(n log n) keeps a 'tails' array updated by lower_bound.

**Pattern:** LIS · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — longest-increasing-subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/longest-increasing-subsequence) |
| Video | [takeUforward](https://youtu.be/on2hvxBXJH4) |

---

### 52. Print Longest Increasing Subsequence 🟡

**Core Idea:** O(n²) LIS while storing parent[i] = the j that gave dp[i]; walk parent pointers back from the best index and reverse.

**Pattern:** LIS + parent array · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/print-longest-increasing-subsequence) |
| Video | [takeUforward](https://youtu.be/IFfYfonAFGc) |

---

### 53. Largest Divisible Subset 🔴

**Core Idea:** Sort, then Print-LIS with 'nums[i] % nums[j] == 0' in place of 'nums[j] < nums[i]' — divisibility chains are transitive once sorted.

**Pattern:** LIS on a custom relation · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — largest-divisible-subset](https://leetcode.com/problems/largest-divisible-subset/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/largest-divisible-subset) |
| Video | [takeUforward](https://youtu.be/gDuZwBW9VvM) |

---

### 54. Longest String Chain 🔴

**Core Idea:** Sort words by length, then LIS where 'j precedes i' means words[i] is words[j] with exactly one letter inserted (two-pointer check).

**Pattern:** LIS on a custom relation · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — longest-string-chain](https://leetcode.com/problems/longest-string-chain/) |
| Video | [takeUforward](https://youtu.be/YY8iBaYcc4g) |

---

### 55. Longest Bitonic Subsequence 🔴

**Core Idea:** LIS ending at i (left-to-right) + LIS starting at i (right-to-left) - 1, maximised over i.

**Pattern:** LIS from both ends · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Video | [takeUforward](https://youtu.be/y4vN0WNdrlg) |

---

### 56. Number of Longest Increasing Subsequences 🔴

**Core Idea:** Alongside dp[i] (LIS length ending at i) keep cnt[i]: a strictly longer extension copies cnt[j], an equal-length one adds cnt[j].

**Pattern:** LIS + count array · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — number-of-longest-increasing-subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) |
| Video | [takeUforward](https://youtu.be/cKVl1TFdNXg) |

---

## 16.7 — DP on Strings

---

### 57. Longest Common Subsequence 🔴

**Core Idea:** dp[i][j] = 1 + dp[i-1][j-1] on a match, else max(dp[i-1][j], dp[i][j-1]) — THE anchor for this whole group (use 1-based indices so the base row/column is 0).

**Pattern:** two-string DP (match / skip) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — longest-common-subsequence](https://leetcode.com/problems/longest-common-subsequence/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/longest-common-subsequence) |
| Video | [takeUforward](https://youtu.be/-zI4mrF2Pb4) |

---

### 58. Longest Common Substring 🔴

**Core Idea:** LCS, but a mismatch resets dp[i][j] to 0 (contiguity breaks); the answer is the max over all cells, not dp[n][m].

**Pattern:** two-string DP (contiguous) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Video | [takeUforward](https://youtu.be/_wP9mWNPL5w) |

---

### 59. Longest Palindromic Subsequence 🔴

**Core Idea:** A palindromic subsequence is a common subsequence of s and its reverse — answer = LCS(s, rev(s)).

**Pattern:** LCS(s, reverse(s)) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — longest-palindromic-subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/longest-palindromic-subsequence) |
| Video | [takeUforward](https://youtu.be/6i_T5kkfv4A) |

---

### 60. Minimum Insertions to Make a String Palindrome 🟡

**Core Idea:** Keep the longest palindromic subsequence untouched and mirror every other character: answer = n - LPS(s).

**Pattern:** n - LPS · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — minimum-insertion-steps-to-make-a-string-palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=xPBLEj41rFU) |

---

### 61. Minimum Insertions/Deletions to Convert String A to B 🔴

**Core Idea:** Keep the LCS, delete the rest of A, insert the rest of B: (n - LCS) + (m - LCS). LC 583 (delete from both strings) has the same answer.

**Pattern:** n + m - 2·LCS · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — delete-operation-for-two-strings](https://leetcode.com/problems/delete-operation-for-two-strings/) |
| Video | [takeUforward](https://www.youtube.com/watch?v=yMnH0jrir0Q) |

---

### 62. Shortest Common Supersequence 🟡

**Core Idea:** Length = n + m - LCS; to build the string, walk the LCS table back from (n,m): emit a matched char once, otherwise emit the char from the side you move away from, then reverse.

**Pattern:** LCS table + backtrack · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — shortest-common-supersequence](https://leetcode.com/problems/shortest-common-supersequence/) |
| Video | [takeUforward](https://youtu.be/xElxAuBcvsU) |

---

### 63. Distinct Subsequences 🟡

**Core Idea:** dp[i][j] = ways to form t[..j] from s[..i]: on a match dp[i-1][j-1] + dp[i-1][j] (use it or skip it), else dp[i-1][j]; dp[i][0] = 1.

**Pattern:** two-string counting DP · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — distinct-subsequences](https://leetcode.com/problems/distinct-subsequences/) |
| Video | [takeUforward](https://youtu.be/nVG7eTiD2bY) |

---

### 64. Edit Distance 🟡

**Core Idea:** Match → dp[i-1][j-1]; else 1 + min(insert dp[i][j-1], delete dp[i-1][j], replace dp[i-1][j-1]); base rows are i and j.

**Pattern:** two-string DP (3 operations) · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — edit-distance](https://leetcode.com/problems/edit-distance/) |
| Video | [takeUforward](https://youtu.be/fJaKO8FbDdo) |

---

### 65. Wildcard Matching 🟡

**Core Idea:** '?' or equal char → dp[i-1][j-1]; '*' → dp[i][j-1] (matches empty) OROR dp[i-1][j] (eats one more char); base case: an all-'*' pattern prefix matches the empty string.

**Pattern:** two-string DP (pattern) · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — wildcard-matching](https://leetcode.com/problems/wildcard-matching/) |
| Video | [takeUforward](https://youtu.be/ZmlQ3vgAOMo) |

---

### 66. Word Break 🔴

**Core Idea:** dp[i] = true if some dictionary word w ends at i with dp[i - ORwOR] true; dp[0] = true — a 1D DP over string prefixes.

**Pattern:** prefix DP · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — word-break](https://leetcode.com/problems/word-break/) |

---

### 67. Count Palindromic Subsequences (length 5) 🟡

**Core Idea:** Fix the middle character; a length-5 palindrome is pair (a,b) on the left + mirrored (b,a) on the right. Precompute prefix counts of each digit-pair and suffix counts, then sum over 100 pairs per middle.

**Pattern:** prefix/suffix pair counts · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — count-palindromic-subsequences](https://leetcode.com/problems/count-palindromic-subsequences/) |

---

## 16.8 — Partition DP (MCM)

---

### 68. Matrix Chain Multiplication 🟡

**Core Idea:** f(i,j) = min over k in i..j of f(i,k) + f(k+1,j) + arr[i-1]·arr[k]·arr[j] — the partition-DP template: try every split point of a range.

**Pattern:** partition DP f(i, j) · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Video | [takeUforward](https://youtu.be/vRVfmbCFW7Y) |

---

### 69. Burst Balloons 🟡

**Core Idea:** Pad with 1 at both ends and think of the LAST balloon k burst in (i,j): f(i,j) = max over k of nums[i-1]·nums[k]·nums[j+1] + f(i,k-1) + f(k+1,j).

**Pattern:** partition DP (last action) · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — burst-balloons](https://leetcode.com/problems/burst-balloons/) |
| Video | [takeUforward](https://youtu.be/Yz4LlDSlkns) |

---

### 70. Palindrome Partitioning II 🟡

**Core Idea:** Front partition: f(i) = min over j >= i with s[i..=j] a palindrome of 1 + f(j+1); answer is f(0) - 1 (the last 'cut' is past the end).

**Pattern:** front partition · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — palindrome-partitioning-ii](https://leetcode.com/problems/palindrome-partitioning-ii/) |
| Article | [takeuforward](https://takeuforward.org/blogs/data-structure-and-algorithm/palindrome-partitioning-ii-minimum-cuts) |
| Video | [takeUforward](https://youtu.be/_H8V5hJUGd0) |

---

### 71. Partition Array for Maximum Sum 🟡

**Core Idea:** Front partition: f(i) = max over len in 1..=k of max(arr[i..i+len])·len + f(i+len).

**Pattern:** front partition · **LeetCode difficulty / used for folder:** Medium

| Platform | Link |
|---|---|
| LeetCode | [LC — partition-array-for-maximum-sum](https://leetcode.com/problems/partition-array-for-maximum-sum/) |
| Video | [takeUforward](https://youtu.be/PhWWJmaKfMc) |

---

### 72. Minimum Cost to Cut a Stick 🟡

**Core Idea:** Sort cuts and add 0 and n as ends; f(i,j) = min over k in i..=j of (cuts[j+1] - cuts[i-1]) + f(i,k-1) + f(k+1,j) — MCM shape again.

**Pattern:** partition DP f(i, j) · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | [LC — minimum-cost-to-cut-a-stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/) |
| Video | [takeUforward](https://youtu.be/xwomavsC86c) |

---

### 73. Evaluate Boolean Expression to True 🟡

**Core Idea:** f(i, j, wantTrue): split at every operator k and combine the (true, false) counts of the two sides according to &, OR or ^.

**Pattern:** partition DP with a true/false flag · **LeetCode difficulty / used for folder:** Hard

| Platform | Link |
|---|---|
| LeetCode | — (no LeetCode link in the source; solve in C++ on GFG or test locally) |
| Video | [takeUforward](https://youtu.be/MM7fXopgyjw) |

---

## DP Problem Table

| # | Problem | Cluster | Tier | Pattern | LeetCode |
|---|---|---|---|---|---|
| — | *Introduction to DP (theory)* | — | — | Memoization vs tabulation | — |
| 22 | Climbing Stairs | 1D DP | 🔴 Core | f(i) = f(i-1) + f(i-2) | [LC](https://leetcode.com/problems/climbing-stairs/) |
| 23 | Frog Jump | 1D DP | 🔴 Core | min over last 2 moves | — |
| 24 | Frog Jump with K Distances | 1D DP | 🔴 Core | min over last k moves | — |
| 25 | Maximum Sum of Non-Adjacent Elements (House Robber) | 1D DP | 🔴 Core | pick / not-pick | [LC](https://leetcode.com/problems/house-robber/) |
| 26 | House Robber II | 1D DP | 🔴 Core | pick / not-pick (circular) | [LC](https://leetcode.com/problems/house-robber-ii/) |
| 27 | Ninja's Training | 2D DP | 🔴 Core | state = (day, last task) | — |
| 28 | Grid Unique Paths | DP on Grids | 🔴 Core | grid paths (right/down) | [LC](https://leetcode.com/problems/unique-paths/) |
| 29 | Unique Paths II | DP on Grids | 🟡 Pro | grid paths + obstacles | [LC](https://leetcode.com/problems/unique-paths-ii/) |
| 30 | Minimum Falling Path Sum | DP on Grids | 🔴 Core | grid, variable start/end | [LC](https://leetcode.com/problems/minimum-falling-path-sum/) |
| 31 | Triangle | DP on Grids | 🔴 Core | grid, fixed start, variable end | [LC](https://leetcode.com/problems/triangle/) |
| 32 | Cherry Pickup II | DP on Grids | 🟡 Pro | 3D DP — two walkers | [LC](https://leetcode.com/problems/cherry-pickup-ii/) |
| 33 | Count Square Submatrices with All Ones | DP on Grids | ⚪ Untiered | square-ending-here DP | [LC](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) |
| 34 | Best Time to Buy and Sell Stock | DP on Stocks | 🔴 Core | running min | [LC](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |
| 35 | Best Time to Buy and Sell Stock II | DP on Stocks | 🔴 Core | state = (day, holding?) | [LC](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) |
| 36 | Best Time to Buy and Sell Stock III | DP on Stocks | 🟡 Pro | state = (day, holding?, txns left) | [LC](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) |
| 37 | Best Time to Buy and Sell Stock IV | DP on Stocks | 🟡 Pro | state = (day, holding?, txns left) | [LC](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) |
| 38 | Best Time to Buy and Sell Stock with Transaction Fee | DP on Stocks | 🔴 Core | state = (day, holding?) | [LC](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) |
| 39 | Best Time to Buy and Sell Stock with Cooldown | DP on Stocks | 🔴 Core | state = (day, holding?) | [LC](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) |
| 40 | Subset Sum Equal to Target | DP on Subsequences | 🔴 Core | pick / not-pick on (index, target) | — |
| 41 | Partition Equal Subset Sum | DP on Subsequences | 🔴 Core | subset sum | [LC](https://leetcode.com/problems/partition-equal-subset-sum/) |
| 42 | Partition a Set into Two Subsets with Minimum Absolute Sum Difference | DP on Subsequences | 🟡 Pro | subset sum (whole last row) | [LC](https://leetcode.com/problems/last-stone-weight-ii/) |
| 43 | Count Subsets with Sum K | DP on Subsequences | 🔴 Core | counting subset sum | — |
| 44 | Count Partitions with Given Difference | DP on Subsequences | 🔴 Core | counting subset sum | — |
| 45 | 0/1 Knapsack | DP on Subsequences | 🔴 Core | pick / not-pick on (index, capacity) | — |
| 46 | Minimum Coins (Coin Change) | DP on Subsequences | 🔴 Core | unbounded pick | [LC](https://leetcode.com/problems/coin-change/) |
| 47 | Target Sum | DP on Subsequences | 🔴 Core | counting subset sum | [LC](https://leetcode.com/problems/target-sum/) |
| 48 | Coin Change II | DP on Subsequences | 🟡 Pro | unbounded counting | [LC](https://leetcode.com/problems/coin-change-ii/) |
| 49 | Unbounded Knapsack | DP on Subsequences | 🔴 Core | unbounded pick | — |
| 50 | Rod Cutting | DP on Subsequences | 🟡 Pro | unbounded knapsack | — |
| 51 | Longest Increasing Subsequence | Longest Increasing Subsequence | 🔴 Core | LIS | [LC](https://leetcode.com/problems/longest-increasing-subsequence/) |
| 52 | Print Longest Increasing Subsequence | Longest Increasing Subsequence | 🟡 Pro | LIS + parent array | — |
| 53 | Largest Divisible Subset | Longest Increasing Subsequence | 🔴 Core | LIS on a custom relation | [LC](https://leetcode.com/problems/largest-divisible-subset/) |
| 54 | Longest String Chain | Longest Increasing Subsequence | 🔴 Core | LIS on a custom relation | [LC](https://leetcode.com/problems/longest-string-chain/) |
| 55 | Longest Bitonic Subsequence | Longest Increasing Subsequence | 🔴 Core | LIS from both ends | — |
| 56 | Number of Longest Increasing Subsequences | Longest Increasing Subsequence | 🔴 Core | LIS + count array | [LC](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) |
| 57 | Longest Common Subsequence | DP on Strings | 🔴 Core | two-string DP (match / skip) | [LC](https://leetcode.com/problems/longest-common-subsequence/) |
| 58 | Longest Common Substring | DP on Strings | 🔴 Core | two-string DP (contiguous) | — |
| 59 | Longest Palindromic Subsequence | DP on Strings | 🔴 Core | LCS(s, reverse(s)) | [LC](https://leetcode.com/problems/longest-palindromic-subsequence/) |
| 60 | Minimum Insertions to Make a String Palindrome | DP on Strings | 🟡 Pro | n - LPS | [LC](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/) |
| 61 | Minimum Insertions/Deletions to Convert String A to B | DP on Strings | 🔴 Core | n + m - 2·LCS | [LC](https://leetcode.com/problems/delete-operation-for-two-strings/) |
| 62 | Shortest Common Supersequence | DP on Strings | 🟡 Pro | LCS table + backtrack | [LC](https://leetcode.com/problems/shortest-common-supersequence/) |
| 63 | Distinct Subsequences | DP on Strings | 🟡 Pro | two-string counting DP | [LC](https://leetcode.com/problems/distinct-subsequences/) |
| 64 | Edit Distance | DP on Strings | 🟡 Pro | two-string DP (3 operations) | [LC](https://leetcode.com/problems/edit-distance/) |
| 65 | Wildcard Matching | DP on Strings | 🟡 Pro | two-string DP (pattern) | [LC](https://leetcode.com/problems/wildcard-matching/) |
| 66 | Word Break | DP on Strings | 🔴 Core | prefix DP | [LC](https://leetcode.com/problems/word-break/) |
| 67 | Count Palindromic Subsequences (length 5) | DP on Strings | 🟡 Pro | prefix/suffix pair counts | [LC](https://leetcode.com/problems/count-palindromic-subsequences/) |
| 68 | Matrix Chain Multiplication | Partition DP (MCM) | 🟡 Pro | partition DP f(i, j) | — |
| 69 | Burst Balloons | Partition DP (MCM) | 🟡 Pro | partition DP (last action) | [LC](https://leetcode.com/problems/burst-balloons/) |
| 70 | Palindrome Partitioning II | Partition DP (MCM) | 🟡 Pro | front partition | [LC](https://leetcode.com/problems/palindrome-partitioning-ii/) |
| 71 | Partition Array for Maximum Sum | Partition DP (MCM) | 🟡 Pro | front partition | [LC](https://leetcode.com/problems/partition-array-for-maximum-sum/) |
| 72 | Minimum Cost to Cut a Stick | Partition DP (MCM) | 🟡 Pro | partition DP f(i, j) | [LC](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/) |
| 73 | Evaluate Boolean Expression to True | Partition DP (MCM) | 🟡 Pro | partition DP with a true/false flag | — |

---

## DP Pattern Quick Reference

### Memoize → Tabulate → Space-Optimise (Climbing Stairs shape)
```
memo:  f(i): if i <= 1 return 1; if dp[i] != -1 return dp[i]; return dp[i] = f(i-1) + f(i-2)
tab:   dp[0] = dp[1] = 1; for i in 2..=n: dp[i] = dp[i-1] + dp[i-2]
space: prev2 = 1, prev = 1; for i in 2..=n: cur = prev + prev2; prev2 = prev; prev = cur
```

### Pick / Not-Pick on (index, target) — subset sum, knapsack, coins
```
notPick = f(i-1, t)
pick    = a[i] <= t ? f(i-1, t-a[i])   // 0/1: move to the previous index
                    : f(i,   t-a[i])   // unbounded: stay on the same index
combine with || (exists), + (count), max/min (optimise)
```

### Two-String Match / Skip — LCS family
```
f(i, j): if i < 0 or j < 0 → base
  s[i] == t[j] → 1 + f(i-1, j-1)
  else         → max(f(i-1, j), f(i, j-1))
shift to 1-based indices so row 0 / column 0 hold the base case
```

### Stock State Machine
```
f(day, canBuy, cap):
  canBuy → max(-p[day] + f(day+1, 0, cap), f(day+1, 1, cap))
  else   → max( p[day] + f(day+1, 1, cap-1), f(day+1, 0, cap))
fee: subtract it on the sell · cooldown: a sell jumps to day+2
```

### Partition DP — MCM shape
```
f(i, j): if i > j (or i == j) → base
  best over k in i..j of  f(i, k) + f(k+1, j) + cost(i, k, j)
tabulate with i descending, j ascending (from j = i)
```

---

## What These Patterns Unlock Later

| Pattern | Reappears in |
|---|---|
| Pick / don't-pick | Part 2 — DP on Subsequences (22–50 memoize this exact recursion tree) |
| Memoization + tabulation (Part 2) | Graphs (shortest paths are DP over edges), Trees (DP on subtrees: diameter, max path sum) |
| Partition DP | Interval problems generally; Burst Balloons-style "last action" thinking |
| Backtracking + undo | Graphs (DFS with a visited set), Tries (building/searching word paths) |
| Constraint satisfaction | Graphs (graph coloring, Hamiltonian path), Sudoku-style problems generally |
| Divide-and-conquer halving (Pow(x,n)) | Binary Search's "halve the search space" instinct, applied to exponentiation instead of an array |
| Grid backtracking | Graphs (grid-as-graph DFS/BFS), Part 2 DP on grids (28–33 — same movement rules, memoized) |

---

## Revision Sessions

### Before a Contest
Only 🔴 Core: **1–12** (all of Implementation Problems, Subsequence Pattern Problems, and FAQs Medium except Combination Sum III)
Focus especially on: the pick/don't-pick skeleton (problem 3) and the duplicate-skip trick (problems 10 & 12) — these two ideas cover most of what shows up in disguise elsewhere.
DP 🔴 Core: **22–28, 30, 31, 34, 35, 38–41, 43–47, 49, 51, 53–59, 61, 66** — the anchors are Climbing Stairs (22), 0/1 Knapsack (45), Stock II (35), LIS (51) and LCS (57).

### Before an Interview
All 🔴 + 🟡. Emphasis on: **N-Queens / Sudoku Solver** (constraint satisfaction, extremely common), **Word Search** (grid backtracking, extremely common), **Expression Add Operators** (the hardest bookkeeping in this step). For DP: **Edit Distance (64)**, **Coin Change (46)**, **LIS (51)**, **Word Break (66)**, **Burst Balloons (69)** — and be ready to go recursion → memo → tabulation → space-optimised on any of them.

### Periodic Revision (every 2-3 weeks)
Problems where implementation details fade fastest: **Combination Sum II / Subsets II** (the exact duplicate-skip condition), **Sudoku Solver** (all three simultaneous validity checks), **Expression Add Operators** (undoing multiplication precedence). DP: **Stock III/IV** (the transactions dimension), **Count Subsets with Sum K** (zeros in the base case), **Shortest Common Supersequence** (rebuilding the string from the table), **Burst Balloons** ("last balloon" framing).

---

## Resources

| Resource | Link |
|---|---|
| Striver's A2Z Sheet | [takeuforward.org](https://takeuforward.org/prep-hub/strivers-a2z-dsa-sheet) |
| YouTube — Recursion Playlist | [takeUforward Channel](https://www.youtube.com/@takeUforward) |
| Introduction to DP (theory) | [Video](https://youtu.be/tyB0ztf0DNY) · [Article](https://takeuforward.org/blogs/data-structure-and-algorithm/dynamic-programming-memoization-tabulation) |

---

| ← Previous | Index | Next → |
|---|---|---|
| [Step 6 — Linked List](LinkedList.md) | [All Topics](README.md) | *Trees & BST coming next* |

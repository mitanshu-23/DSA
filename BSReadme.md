# Striver's A2Z DSA Sheet — Step 4: Binary Search

> **Source:** [takeuforward.org — Striver's A2Z DSA Sheet](https://takeuforward.org/dsa/strivers-a2z-sheet-learn-dsa-a-to-z)  
> **Video Playlist:** [takeUforward YouTube Channel](https://www.youtube.com/@takeUforward)  
> **Total Problems in this step:** 32  
> **Sub-steps:** 4.1 BS on 1D Arrays (13) · 4.2 BS on Answers / Search Space (14) · 4.3 BS on 2D Arrays (5)

---

## What is Binary Search?

Binary Search is a search algorithm that works on **sorted** data by repeatedly halving the search space. Instead of scanning every element (O(n)), it eliminates half the candidates at each step, achieving **O(log n)** time. The core template:

```
lo = 0, hi = n - 1
while lo <= hi:
    mid = lo + (hi - lo) / 2
    if arr[mid] == target: return mid
    elif arr[mid] < target: lo = mid + 1
    else: hi = mid - 1
```

Beyond simple search, Binary Search generalises to:
- **1D arrays** — finding bounds, rotated arrays, peak elements, single elements
- **Search space / answer-space** — when the answer itself is monotonic (e.g. "minimum days", "minimum speed")
- **2D matrices** — treating a matrix as a virtual sorted array

### Key Invariants to remember
| Variant | When to use `lo = mid + 1` vs `hi = mid` |
|---|---|
| Find exact target | `lo = mid + 1` / `hi = mid - 1` |
| Lower bound (first `>= x`) | `hi = mid` when `arr[mid] >= x` |
| Upper bound (first `> x`) | `hi = mid` when `arr[mid] > x` |
| Answer space (minimise) | `hi = mid` when `check(mid)` is feasible |
| Answer space (maximise) | `lo = mid` when `check(mid)` is feasible |

---

## 4.1 — Binary Search on 1D Arrays

Problems that directly apply binary search on a **given sorted (or rotated) array**.

---

### 1. Binary Search to Find X in Sorted Array

**Difficulty:** Easy  
**Core Idea:** Classic binary search — compare `arr[mid]` with target and shrink the window.

| Platform | Link |
|---|---|
| LeetCode | [LC 704 — Binary Search](https://leetcode.com/problems/binary-search/) |
| GFG | [GFG — Binary Search](https://www.geeksforgeeks.org/binary-search/) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/binary-search-algorithm-iterative-and-recursive-implementation/) |

---

### 2. Implement Lower Bound

**Difficulty:** Easy  
**Core Idea:** Find the **first index** where `arr[i] >= x`. Use `hi = mid` when condition is met, track the answer.

| Platform | Link |
|---|---|
| LeetCode | [LC 2529 — Maximum Count (uses lower_bound concept)](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/) · [`std::lower_bound` equivalent: LC 35](https://leetcode.com/problems/search-insert-position/) |
| GFG | [GFG — Lower Bound](https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1) |
| Article / Video | [takeUforward](https://takeuforward.org/arrays/implement-lower-bound-bs-2) |

---

### 3. Implement Upper Bound

**Difficulty:** Easy  
**Core Idea:** Find the **first index** where `arr[i] > x`. Similar to lower bound but condition shifts to `arr[mid] > x`.

| Platform | Link |
|---|---|
| LeetCode | [LC 34 — Find First and Last Position](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) |
| GFG | [GFG — Upper Bound](https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1) |
| Article / Video | [takeUforward](https://takeuforward.org/arrays/implement-upper-bound) |

---

### 4. Search Insert Position

**Difficulty:** Easy  
**Core Idea:** If target exists return its index; otherwise return the insertion index — which is exactly the **lower bound**.

| Platform | Link |
|---|---|
| LeetCode | [LC 35 — Search Insert Position](https://leetcode.com/problems/search-insert-position/) |
| GFG | [GFG — Search Insert Position](https://www.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1) |
| Article / Video | [takeUforward](https://takeuforward.org/arrays/search-insert-position) |

---

### 5. Floor and Ceil in Sorted Array

**Difficulty:** Easy  
**Core Idea:** **Floor** = largest element `<= x` (upper bound index - 1 trick). **Ceil** = smallest element `>= x` (lower bound). Both derivable from the two bound templates.

| Platform | Link |
|---|---|
| LeetCode | N/A (pure logic problem; no direct LC equivalent) |
| GFG | [GFG — Floor in Sorted Array](https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1) |
| Coding Ninjas | [Coding Ninjas — Ceil The Floor](https://www.naukri.com/code360/problems/ceil-the-floor_893098) |
| Article / Video | [takeUforward](https://takeuforward.org/arrays/floor-and-ceil-in-sorted-array) |

---

### 6. Find First and Last Occurrence of Element in Sorted Array

**Difficulty:** Easy–Medium  
**Core Idea:** Run lower-bound to find **first** occurrence, upper-bound (minus 1) to find **last**. Two binary searches.

| Platform | Link |
|---|---|
| LeetCode | [LC 34 — Find First and Last Position](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) |
| GFG | [GFG — First and Last Occurrence](https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/last-occurrence-in-a-sorted-array/) |

---

### 7. Count Occurrences of a Number in Sorted Array

**Difficulty:** Easy  
**Core Idea:** `count = last_occurrence - first_occurrence + 1`. Derived directly from problem 6.

| Platform | Link |
|---|---|
| LeetCode | [LC 34 (derive count from first/last)](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) |
| GFG | [GFG — Count Occurrences](https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1) |
| Article / Video | [takeUforward](https://takeuforward.org/arrays/count-occurrences-in-sorted-array) |

---

### 8. Search in Rotated Sorted Array I (No Duplicates)

**Difficulty:** Medium  
**Core Idea:** One half of the array is always sorted. Check which half is sorted, then decide which half the target can lie in.

| Platform | Link |
|---|---|
| LeetCode | [LC 33 — Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) |
| GFG | [GFG — Search In Rotated Sorted Array](https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/search-element-in-a-rotated-sorted-array/) |

---

### 9. Search in Rotated Sorted Array II (With Duplicates)

**Difficulty:** Medium  
**Core Idea:** Duplicates can make `arr[lo] == arr[mid] == arr[hi]`, so we can't determine which side is sorted. When ambiguous, do `lo++, hi--` and re-check.

| Platform | Link |
|---|---|
| LeetCode | [LC 81 — Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) |
| GFG | [GFG — Search in Rotated Sorted Array II](https://www.geeksforgeeks.org/problems/search-in-rotated-array2624/1) |
| Article / Video | [takeUforward](https://takeuforward.org/arrays/search-in-rotated-sorted-array-ii-duplicates-allowed) |

---

### 10. Minimum in Rotated Sorted Array

**Difficulty:** Medium  
**Core Idea:** The minimum is at the **inflection point**. The sorted half's leftmost element is a candidate; always move towards the unsorted (lower) half.

| Platform | Link |
|---|---|
| LeetCode | [LC 153 — Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) |
| GFG | [GFG — Minimum in Rotated Sorted Array](https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/minimum-element-in-rotated-sorted-array/) |

---

### 11. Find Out How Many Times Array Has Been Rotated

**Difficulty:** Easy–Medium  
**Core Idea:** The **number of rotations = index of the minimum element**. Reuse problem 10's approach.

| Platform | Link |
|---|---|
| LeetCode | N/A (GFG / Coding Ninjas only) |
| GFG | [GFG — Number of Times Array Rotated](https://www.geeksforgeeks.org/problems/rotation4723/1) |
| Coding Ninjas | [Coding Ninjas — Number of Rotations](https://www.naukri.com/code360/problems/rotation_7449070) |
| Article / Video | [takeUforward](https://takeuforward.org/arrays/number-of-times-array-is-rotated) |

---

### 12. Single Element in a Sorted Array

**Difficulty:** Medium  
**Core Idea:** Every pair occupies even-odd indices. The single element breaks this pattern. Binary search on index parity: if `arr[mid] == arr[mid^1]`, single is to the right; else to the left.

| Platform | Link |
|---|---|
| LeetCode | [LC 540 — Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/) |
| GFG | [GFG — Single Element in Sorted Array](https://www.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/find-the-single-element-in-a-sorted-array/) |

---

### 13. Find Peak Element

**Difficulty:** Medium  
**Core Idea:** A peak is where `arr[i] > arr[i-1]` and `arr[i] > arr[i+1]`. If `arr[mid] < arr[mid+1]`, the peak is on the right. Else on the left (or at mid).

| Platform | Link |
|---|---|
| LeetCode | [LC 162 — Find Peak Element](https://leetcode.com/problems/find-peak-element/) |
| GFG | [GFG — Peak Element](https://www.geeksforgeeks.org/problems/peak-element/1) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/peak-element-in-array/) |

---

## 4.2 — Binary Search on Answer (Search Space)

These problems don't have a sorted array to search through — instead, the **answer itself** lies in a range, and you binary search on that range using a **feasibility check function**.

**General template:**
```
lo, hi = min_possible_answer, max_possible_answer
while lo < hi:
    mid = (lo + hi) / 2
    if is_feasible(mid):
        hi = mid        # or lo = mid + 1 for maximise
    else:
        lo = mid + 1    # or hi = mid - 1
return lo
```

---

### 14. Find Square Root of a Number (Floor)

**Difficulty:** Easy  
**Core Idea:** Binary search in range `[1, n]`. If `mid * mid <= n`, it's a candidate; move `lo = mid + 1`. Answer is `hi` at the end.

| Platform | Link |
|---|---|
| LeetCode | [LC 69 — Sqrt(x)](https://leetcode.com/problems/sqrtx/) |
| GFG | [GFG — Square Root](https://www.geeksforgeeks.org/problems/square-root/1) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/finding-sqrt-of-a-number-using-binary-search) |

---

### 15. Find the Nth Root of a Number

**Difficulty:** Easy–Medium  
**Core Idea:** Binary search in `[1, m]`. Compute `mid^n` carefully (use a helper that returns -1 on overflow, 0 on exact match, 1 if too large).

| Platform | Link |
|---|---|
| LeetCode | N/A |
| GFG | [GFG — Nth Root of M](https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1) |
| Coding Ninjas | [Coding Ninjas — Nth Root](https://www.naukri.com/code360/problems/nth-root-of-m_1062679) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/finding-nth-root-of-a-number-using-binary-search) |

---

### 16. Koko Eating Bananas

**Difficulty:** Medium  
**Core Idea:** Binary search on speed `k ∈ [1, max(piles)]`. For a given speed, compute total hours `= Σ ceil(pile / k)`. Find the minimum `k` where total hours `<= h`.

| Platform | Link |
|---|---|
| LeetCode | [LC 875 — Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) |
| GFG | [GFG — Koko Eating Bananas](https://www.geeksforgeeks.org/problems/koko-eating-bananas/1) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/koko-eating-bananas) |

---

### 17. Minimum Days to Make M Bouquets

**Difficulty:** Medium  
**Core Idea:** Binary search on `day ∈ [min(bloomDay), max(bloomDay)]`. Check if on `mid` days you can form `m` bouquets of `k` consecutive bloomed flowers.

| Platform | Link |
|---|---|
| LeetCode | [LC 1482 — Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) |
| GFG | [GFG — M Bouquets](https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/minimum-days-to-make-m-bouquets) |

---

### 18. Find the Smallest Divisor Given a Threshold

**Difficulty:** Medium  
**Core Idea:** Binary search divisor `d ∈ [1, max(nums)]`. For a given `d`, sum = `Σ ceil(nums[i] / d)`. Find minimum `d` where sum `<= threshold`.

| Platform | Link |
|---|---|
| LeetCode | [LC 1283 — Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) |
| GFG | [GFG — Smallest Divisor](https://www.geeksforgeeks.org/problems/find-the-smallest-divisor/1) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/find-the-smallest-divisor-given-a-threshold) |

---

### 19. Capacity to Ship Packages Within D Days

**Difficulty:** Medium  
**Core Idea:** Binary search capacity `∈ [max(weights), sum(weights)]`. Check if all packages ship within `D` days using the given capacity. Classic "minimum capacity" pattern.

| Platform | Link |
|---|---|
| LeetCode | [LC 1011 — Capacity to Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) |
| GFG | [GFG — Ship Packages](https://www.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/capacity-to-ship-packages-within-d-days) |

---

### 20. Kth Missing Positive Number

**Difficulty:** Easy–Medium  
**Core Idea:** Binary search on index: for index `i`, the number of missing positives before `arr[i]` is `arr[i] - (i+1)`. Find the first index where this count `>= k`.

| Platform | Link |
|---|---|
| LeetCode | [LC 1539 — Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/) |
| GFG | [GFG — Kth Missing Positive](https://www.geeksforgeeks.org/problems/kth-missing-positive-number2913/1) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/kth-missing-positive-number) |

---

### 21. Aggressive Cows

**Difficulty:** Medium (Classic)  
**Core Idea:** Binary search on **minimum distance** between cows `∈ [1, max - min of stalls]`. For a given distance, greedily check if you can place all `c` cows with at least that gap.

| Platform | Link |
|---|---|
| LeetCode | N/A (SPOJ / GFG / Coding Ninjas) |
| GFG | [GFG — Aggressive Cows](https://www.geeksforgeeks.org/problems/aggressive-cows/1) |
| SPOJ | [SPOJ — AGGRCOW](https://www.spoj.com/problems/AGGRCOW/) |
| Coding Ninjas | [Coding Ninjas — Aggressive Cows](https://www.naukri.com/code360/problems/aggressive-cows_1082559) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/aggressive-cows-detailed-solution) |

---

### 22. Book Allocation Problem

**Difficulty:** Medium (Classic)  
**Core Idea:** Binary search on **maximum pages** allocated to a student `∈ [max(pages), sum(pages)]`. Greedily check if you can assign books to `m` students within the limit.

> ⚠️ Constraint: books must be contiguous; a student gets a contiguous chunk.

| Platform | Link |
|---|---|
| LeetCode | [LC 1011](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) (same pattern) |
| GFG | [GFG — Allocate Minimum Number of Pages](https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1) |
| Coding Ninjas | [Coding Ninjas — Book Allocation](https://www.naukri.com/code360/problems/allocate-books_1090540) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/) |

---

### 23. Split Array — Largest Sum

**Difficulty:** Hard  
**Core Idea:** **Same pattern as Book Allocation.** Binary search on the maximum subarray sum. Check if the array can be split into at most `k` subarrays where each sum `<= mid`.

| Platform | Link |
|---|---|
| LeetCode | [LC 410 — Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) |
| GFG | [GFG — Split Array Largest Sum](https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/split-array-largest-sum) |

---

### 24. Painter's Partition Problem

**Difficulty:** Hard  
**Core Idea:** **Mirror of Book Allocation.** Minimise the maximum time taken; binary search on time. Assign contiguous boards to painters and check feasibility.

| Platform | Link |
|---|---|
| LeetCode | [LC 410](https://leetcode.com/problems/split-array-largest-sum/) (same as Split Array) |
| GFG | [GFG — Painter's Partition](https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1) |
| Coding Ninjas | [Coding Ninjas — Painter's Partition](https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/painters-partition-problem) |

---

### 25. Minimise Maximum Distance Between Gas Stations

**Difficulty:** Hard  
**Core Idea:** Binary search (floating point) on maximum gap `d`. For a given `d`, compute the minimum number of additional stations needed. Stop when count `<= k`.

| Platform | Link |
|---|---|
| LeetCode | [LC 774 — Minimize Max Distance to Gas Station](https://leetcode.com/problems/minimize-max-distance-to-gas-station/) *(Premium)* |
| GFG | [GFG — Minimise Max Distance to Gas Station](https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/minimise-maximum-distance-between-gas-stations) |

---

### 26. Median of Two Sorted Arrays

**Difficulty:** Hard  
**Core Idea:** Binary search a partition on the **smaller array**. Ensure left half of both arrays combined has correct size and `maxLeft1 <= minRight2` and `maxLeft2 <= minRight1`. O(log(min(m, n))).

| Platform | Link |
|---|---|
| LeetCode | [LC 4 — Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) |
| GFG | [GFG — Median of Two Sorted Arrays](https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/median-of-two-sorted-arrays/) |

---

### 27. Kth Element of Two Sorted Arrays

**Difficulty:** Hard  
**Core Idea:** Binary search the cut on the smaller array such that the combined left partition has exactly `k` elements. Derived from the median problem but without the averaging step.

| Platform | Link |
|---|---|
| LeetCode | [LC 4 (generalised k-th)](https://leetcode.com/problems/median-of-two-sorted-arrays/) |
| GFG | [GFG — K-th Element of Two Sorted Arrays](https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1) |
| Coding Ninjas | [Coding Ninjas — K-th Element](https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164290) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays/) |

---

## 4.3 — Binary Search on 2D Arrays

---

### 28. Find the Row with Maximum Number of 1s

**Difficulty:** Easy  
**Core Idea:** Each row is sorted (0s then 1s). Use **upper bound** to find the first 1 in each row. Track the row with the leftmost 1.

| Platform | Link |
|---|---|
| LeetCode | [LC 2089 — Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/) *(different; closest variant)* |
| GFG | [GFG — Row with Max 1s](https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1) |
| Article / Video | [takeUforward](https://takeuforward.org/arrays/row-with-maximum-number-of-1s) |

---

### 29. Search in a 2D Matrix

**Difficulty:** Medium  
**Core Idea:** Treat the entire matrix as a **virtual 1D sorted array** of size `m*n`. Map `mid` → `(mid / n, mid % n)`. Classic binary search applies directly.

| Platform | Link |
|---|---|
| LeetCode | [LC 74 — Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) |
| GFG | [GFG — Search in a 2D Matrix](https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/) |

---

### 30. Search in Row-wise and Column-wise Sorted Matrix

**Difficulty:** Medium  
**Core Idea:** **Not pure binary search** — use the **staircase search** starting from top-right corner. If element is smaller, move down; if larger, move left. O(m + n).

> Note: This is covered in the binary search step because it's a natural extension, even though the algorithm itself is a two-pointer approach.

| Platform | Link |
|---|---|
| LeetCode | [LC 240 — Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) |
| GFG | [GFG — Search in a Row-Column Sorted Matrix](https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1) |
| Article / Video | [takeUforward](https://takeuforward.org/data-structure/search-in-a-row-and-column-wise-sorted-matrix/) |

---

### 31. Find Peak Element in 2D Matrix

**Difficulty:** Hard  
**Core Idea:** Binary search on columns. For each mid column, find the row with the global max in that column. If the neighbor column has a larger element, shift toward it. Guarantees a peak exists.

| Platform | Link |
|---|---|
| LeetCode | [LC 1901 — Find a Peak Element II](https://leetcode.com/problems/find-a-peak-element-ii/) |
| GFG | [GFG — Peak Element in 2D Matrix](https://www.geeksforgeeks.org/problems/peak-element-in-2d-matrix/1) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/find-peak-element-in-2d-matrix) |

---

### 32. Median in a Row-wise Sorted Matrix

**Difficulty:** Hard  
**Core Idea:** Binary search on the **value range** `[min_element, max_element]`. For each candidate median `mid`, count how many elements across all rows are `<= mid` (using binary search per row). Total count `> (m*n)/2` means median is in `[lo, mid]`.

| Platform | Link |
|---|---|
| LeetCode | [LC 2387 — Median of a Row Wise Sorted Matrix](https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/) *(Premium)* |
| GFG | [GFG — Matrix Median](https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1) |
| Coding Ninjas | [Coding Ninjas — Matrix Median](https://www.naukri.com/code360/problems/median-of-a-row-wise-sorted-matrix_1115473) |
| Article / Video | [takeUforward](https://takeuforward.org/binary-search/median-of-row-wise-sorted-matrix) |

---

## Problem Summary Table

| # | Problem | Difficulty | Sub-step | LeetCode | GFG |
|---|---|---|---|---|---|
| 1 | Binary Search to Find X | Easy | 4.1 | [LC 704](https://leetcode.com/problems/binary-search/) | [GFG](https://www.geeksforgeeks.org/binary-search/) |
| 2 | Implement Lower Bound | Easy | 4.1 | [LC 35](https://leetcode.com/problems/search-insert-position/) | [GFG](https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1) |
| 3 | Implement Upper Bound | Easy | 4.1 | [LC 34](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [GFG](https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1) |
| 4 | Search Insert Position | Easy | 4.1 | [LC 35](https://leetcode.com/problems/search-insert-position/) | [GFG](https://www.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1) |
| 5 | Floor and Ceil in Sorted Array | Easy | 4.1 | — | [GFG](https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1) |
| 6 | First and Last Occurrence | Easy | 4.1 | [LC 34](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [GFG](https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1) |
| 7 | Count Occurrences | Easy | 4.1 | [LC 34](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [GFG](https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1) |
| 8 | Search in Rotated Array I | Medium | 4.1 | [LC 33](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [GFG](https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1) |
| 9 | Search in Rotated Array II | Medium | 4.1 | [LC 81](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) | [GFG](https://www.geeksforgeeks.org/problems/search-in-rotated-array2624/1) |
| 10 | Minimum in Rotated Array | Medium | 4.1 | [LC 153](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | [GFG](https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1) |
| 11 | Times Array Is Rotated | Easy | 4.1 | — | [GFG](https://www.geeksforgeeks.org/problems/rotation4723/1) |
| 12 | Single Element in Sorted Array | Medium | 4.1 | [LC 540](https://leetcode.com/problems/single-element-in-a-sorted-array/) | [GFG](https://www.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1) |
| 13 | Find Peak Element | Medium | 4.1 | [LC 162](https://leetcode.com/problems/find-peak-element/) | [GFG](https://www.geeksforgeeks.org/problems/peak-element/1) |
| 14 | Square Root (Floor) | Easy | 4.2 | [LC 69](https://leetcode.com/problems/sqrtx/) | [GFG](https://www.geeksforgeeks.org/problems/square-root/1) |
| 15 | Nth Root of a Number | Easy | 4.2 | — | [GFG](https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1) |
| 16 | Koko Eating Bananas | Medium | 4.2 | [LC 875](https://leetcode.com/problems/koko-eating-bananas/) | [GFG](https://www.geeksforgeeks.org/problems/koko-eating-bananas/1) |
| 17 | Minimum Days for M Bouquets | Medium | 4.2 | [LC 1482](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) | [GFG](https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1) |
| 18 | Smallest Divisor ≤ Threshold | Medium | 4.2 | [LC 1283](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) | [GFG](https://www.geeksforgeeks.org/problems/find-the-smallest-divisor/1) |
| 19 | Capacity to Ship in D Days | Medium | 4.2 | [LC 1011](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | [GFG](https://www.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1) |
| 20 | Kth Missing Positive Number | Easy | 4.2 | [LC 1539](https://leetcode.com/problems/kth-missing-positive-number/) | [GFG](https://www.geeksforgeeks.org/problems/kth-missing-positive-number2913/1) |
| 21 | Aggressive Cows | Medium | 4.2 | — | [GFG](https://www.geeksforgeeks.org/problems/aggressive-cows/1) |
| 22 | Book Allocation Problem | Medium | 4.2 | [LC 1011](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | [GFG](https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1) |
| 23 | Split Array — Largest Sum | Hard | 4.2 | [LC 410](https://leetcode.com/problems/split-array-largest-sum/) | [GFG](https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1) |
| 24 | Painter's Partition | Hard | 4.2 | [LC 410](https://leetcode.com/problems/split-array-largest-sum/) | [GFG](https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1) |
| 25 | Minimise Max Distance to Gas Station | Hard | 4.2 | [LC 774 *(Premium)*](https://leetcode.com/problems/minimize-max-distance-to-gas-station/) | [GFG](https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1) |
| 26 | Median of Two Sorted Arrays | Hard | 4.2 | [LC 4](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [GFG](https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1) |
| 27 | Kth Element of Two Sorted Arrays | Hard | 4.2 | [LC 4 (generalised)](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [GFG](https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1) |
| 28 | Row with Maximum 1s | Easy | 4.3 | — | [GFG](https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1) |
| 29 | Search in a 2D Matrix | Medium | 4.3 | [LC 74](https://leetcode.com/problems/search-a-2d-matrix/) | [GFG](https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1) |
| 30 | Search in Row & Column Sorted Matrix | Medium | 4.3 | [LC 240](https://leetcode.com/problems/search-a-2d-matrix-ii/) | [GFG](https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1) |
| 31 | Peak Element in 2D Matrix | Hard | 4.3 | [LC 1901](https://leetcode.com/problems/find-a-peak-element-ii/) | [GFG](https://www.geeksforgeeks.org/problems/peak-element-in-2d-matrix/1) |
| 32 | Median in Row-wise Sorted Matrix | Hard | 4.3 | [LC 2387 *(Premium)*](https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/) | [GFG](https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1) |

---

## Common Binary Search Patterns — Cheatsheet

### Pattern 1 — Exact Search (classic)
```
Find X in sorted array
lo=0, hi=n-1; while lo<=hi; if arr[mid]==x return; else shrink
```

### Pattern 2 — Lower / Upper Bound
```
Find first >=x  →  hi = mid if arr[mid]>=x,  else lo = mid+1
Find first >x   →  hi = mid if arr[mid]>x,   else lo = mid+1
```

### Pattern 3 — Rotated Array
```
One half is always sorted; check which half, then decide direction
Handle duplicates by doing lo++, hi-- when arr[lo]==arr[mid]==arr[hi]
```

### Pattern 4 — Answer Space (Minimise)
```
Binary search on the answer value, not on array index
Check feasibility: can(mid) → hi = mid, else lo = mid + 1
```

### Pattern 5 — Answer Space (Maximise)
```
can(mid) → lo = mid, else hi = mid - 1
Watch for infinite loops; use lo + (hi - lo + 1) / 2 as mid
```

### Pattern 6 — 2D as 1D
```
index i in virtual 1D → (i/cols, i%cols) in matrix
Standard binary search applies
```

### Pattern 7 — Value-range on Matrix / Two Arrays
```
Binary search on value ∈ [global_min, global_max]
count_less_equal(mid) tells you which side the answer is on
```

---

## Recommended Study Order

1. Problems 1–7 (bounds, occurrences) — master the two templates
2. Problems 8–13 (rotated arrays, peak, single element)
3. Problems 14–16 (intro to search space: sqrt, Nth root, Koko)
4. Problems 17–20 (standard search-space medium)
5. Problems 21–24 (Aggressive Cows / Book Allocation family — **interview staples**)
6. Problems 25 (floating-point binary search)
7. Problems 26–27 (hard: two sorted arrays — requires clean reasoning)
8. Problems 28–30 (2D matrix basics)
9. Problems 31–32 (2D hard)

---

## Resources

| Resource | Link |
|---|---|
| Striver's A2Z Sheet | [takeuforward.org](https://takeuforward.org/dsa/strivers-a2z-sheet-learn-dsa-a-to-z) |
| YouTube Playlist | [takeUforward Channel](https://www.youtube.com/@takeUforward) |
| Binary Search Playlist | [BS Playlist](https://www.youtube.com/playlist?list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0i3) |
| Striver's Binary Search Blog | [takeuforward BS page](https://takeuforward.org/blogs/binary-search) |

---

## Where This Fits in the Sheet

Binary Search (Step 4) builds directly on **Arrays** (Step 3) — the two-pointer, sorted-array, and answer-space instincts you form there are exactly what this step exploits to get from O(n) to O(log n).

| ← Previous | Index | Next → |
|---|---|---|
| [Step 3 — Arrays](ArraysReadme.md) | [All Topics](README.md) | *Next step coming soon* |
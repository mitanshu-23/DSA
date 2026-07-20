# Striver's A2Z DSA Sheet — Step 3: Arrays

> **Source:** [takeuforward.org — Striver's A2Z DSA Sheet](https://takeuforward.org/dsa/strivers-a2z-sheet-learn-dsa-a-to-z)  
> **YouTube:** [takeUforward Channel](https://www.youtube.com/@takeUforward)  
> **Total Problems:** 40  
> **Sub-steps:** 3.1 Easy (12) · 3.2 Medium (15) · 3.3 Hard (13)

---

## What You Will Learn in This Step

Arrays is **not just a data structure** — it is the training ground for every core algorithmic technique you will use everywhere else:

| Technique | Where it first appears | Where it reappears |
|---|---|---|
| Prefix sums | Subarray sum problems | DP, Trees, Graphs |
| Two pointers | 2Sum, Sort 0/1/2 | Sliding window, Linked list |
| Hashing (freq map) | Majority element, Missing number | Strings, Graphs |
| Kadane's idea | Max subarray sum | DP (1D), Stock problems |
| Merge-sort thinking | Count inversions, Reverse pairs | Merge sort, External sort |
| Greedy on sorted arrays | Stock buy/sell, Leaders | Greedy chapter |
| In-place manipulation | Rotate matrix, Next permutation | Strings, Linked list |

---

## Smart Solve Order — Don't Go Strictly Easy → Medium → Hard

The sheet labels Easy/Medium/Hard, but several problems have **tight conceptual dependencies** that cut across that boundary. Doing them in correlation order means you build each tool once and then reuse it, rather than re-learning it from scratch.

### Recommended Solve Order (by correlation clusters)

```
CLUSTER 1 — Basic Traversal & In-place (do these first, no tricks)
  Largest element
  Second largest element
  Check if sorted
  Remove duplicates from sorted array
  Left rotate by 1
  Left rotate by D places
  Move zeros to end
  Linear search

CLUSTER 2 — Two Sorted Arrays (union/intersection mental model)
  Find Union of two sorted arrays          ← sets up merge logic
  Merge two sorted arrays without space    ← Hard, but directly follows Union

CLUSTER 3 — Missing / Duplicate / XOR (bit tricks + math)
  Find missing number                      ← XOR or sum formula
  Find number appearing once (others twice)← XOR
  Find repeating and missing number        ← Hard, math / XOR
  Maximum consecutive ones                 ← simple scan

CLUSTER 4 — Prefix Sum / Subarray (core pattern)
  Longest subarray with sum K (positives only)
  Count subarrays with given sum           ← prefix + hashmap
  Longest subarray with sum K (pos + neg) ← extends above
  Count subarrays with given XOR K        ← same prefix pattern, XOR variant
  Largest subarray with 0 sum             ← same idea, special case K=0

CLUSTER 5 — Sorting + Two Pointers (medium block)
  Sort array of 0s, 1s, 2s               ← Dutch national flag
  2Sum problem                            ← two pointers on sorted / hashmap
  3Sum problem                            ← extends 2Sum
  4Sum problem                            ← extends 3Sum

CLUSTER 6 — Majority / Voting
  Majority element > n/2                  ← Boyer-Moore voting
  Majority element > n/3                  ← Extended voting (two candidates)

CLUSTER 7 — Subarray Optimisation (Kadane family)
  Kadane's Algorithm (max subarray sum)
  Print subarray with max sum             ← Kadane + tracking
  Maximum product subarray                ← Kadane variant with min/max tracking

CLUSTER 8 — Greedy / Observation
  Stock buy and sell                      ← single pass greedy
  Leaders in an array                     ← scan from right
  Next permutation                        ← in-place lexicographic algorithm
  Merge overlapping intervals             ← sort by start, then greedy sweep

CLUSTER 9 — Matrix (treat as 2D array)
  Set matrix zeros
  Rotate matrix by 90 degrees
  Spiral traversal of matrix
  Pascal's triangle

CLUSTER 10 — Hashing / HashMap problems
  Longest consecutive sequence            ← HashSet O(n)
  Rearrange array by sign                 ← two-pointer / index trick

CLUSTER 11 — Merge Sort Based (hardest — do last)
  Count inversions                        ← modified merge sort
  Reverse pairs                           ← same idea, different condition
```

### Why this order beats Easy → Medium → Hard

- **Merge two sorted arrays** is labelled Hard but is just an extension of Union (Easy). Doing them back to back is more efficient than doing Union, then jumping to 10 other mediums, then coming back.
- **Count subarrays with sum K / XOR K / 0 sum** are all the same prefix-hashmap trick. Doing all 3-4 together locks the pattern in permanently.
- **2Sum → 3Sum → 4Sum** is a direct chain. 3Sum is just 2Sum inside a loop. 4Sum is just 3Sum with one more loop. If you do them weeks apart you'll re-derive the approach every time.
- **Count inversions and Reverse pairs** both need modified merge sort. They're the only two problems in the sheet that do. Doing them together means you learn modified merge sort once.

---

## 3.1 — Easy Problems

---

### 1. Largest Element in an Array

**Core Idea:** Single pass, track max. O(n) time, O(1) space.

| Platform | Link |
|---|---|
| LeetCode | [LC 1480 variant](https://leetcode.com/problems/running-sum-of-1d-array/) / [GFG equivalent](https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1) |
| GFG | [GFG — Largest Element in Array](https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1) |
| Article | [takeUforward](https://takeuforward.org/arrays/find-the-largest-element-in-an-array/) |

---

### 2. Second Largest Element Without Sorting

**Core Idea:** Single pass tracking both max and second-max. Watch out for duplicates — second largest must be strictly less than the largest.

| Platform | Link |
|---|---|
| LeetCode | [LC 414 — Third Maximum Number](https://leetcode.com/problems/third-maximum-number/) *(same idea, extended)* |
| GFG | [GFG — Second Largest](https://www.geeksforgeeks.org/problems/second-largest3735/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/find-second-smallest-and-second-largest-element-in-an-array/) |

---

### 3. Check if the Array is Sorted

**Core Idea:** Scan pairs `(arr[i], arr[i+1])`. If any `arr[i] > arr[i+1]`, not sorted.

| Platform | Link |
|---|---|
| LeetCode | [LC 1752 — Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/) *(extended version)* |
| GFG | [GFG — Array is Sorted](https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1) |
| Article | [takeUforward](https://takeuforward.org/arrays/check-if-the-array-is-sorted/) |

---

### 4. Remove Duplicates from Sorted Array

**Core Idea:** Two-pointer in-place. `i` is the write pointer, `j` is the read pointer. When `arr[j] != arr[i]`, increment `i` and write.

| Platform | Link |
|---|---|
| LeetCode | [LC 26 — Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) |
| GFG | [GFG — Remove Duplicates](https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/) |

---

### 5. Left Rotate an Array by One Place

**Core Idea:** Store `arr[0]`, shift everything left by one, put stored value at end.

| Platform | Link |
|---|---|
| LeetCode | [LC 189 — Rotate Array](https://leetcode.com/problems/rotate-array/) *(right rotation; trivially reversible)* |
| GFG | [GFG — Rotate Array by One](https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1) |
| Article | [takeUforward](https://takeuforward.org/arrays/left-rotate-the-array-by-one/) |

---

### 6. Left Rotate an Array by D Places

**Core Idea:** **Reversal algorithm** — reverse first D, reverse rest, reverse all. O(n) time, O(1) space. Better than using a temp array.

| Platform | Link |
|---|---|
| LeetCode | [LC 189 — Rotate Array](https://leetcode.com/problems/rotate-array/) |
| GFG | [GFG — Rotate Array by D](https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/left-rotate-the-array-by-k-place/) |

---

### 7. Move Zeros to End

**Core Idea:** Two-pointer. `j` finds the first zero, `i` finds the first non-zero after `j`. Swap. Both walk forward.

| Platform | Link |
|---|---|
| LeetCode | [LC 283 — Move Zeroes](https://leetcode.com/problems/move-zeroes/) |
| GFG | [GFG — Move Zeros to End](https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/move-all-zeros-to-the-end-of-the-array/) |

---

### 8. Linear Search

**Core Idea:** Scan left to right, return index when found. Foundation for understanding why binary search is an upgrade.

| Platform | Link |
|---|---|
| LeetCode | [LC 704 — Binary Search](https://leetcode.com/problems/binary-search/) *(contrast with this)* |
| GFG | [GFG — Linear Search](https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1) |
| Article | [takeUforward](https://takeuforward.org/arrays/linear-search/) |

---

### 9. Find the Union of Two Sorted Arrays

**Core Idea:** Two-pointer merge — advance the pointer with the smaller current element. Skip duplicates by checking previous added value. Sets up the mental model for Merge Sort's merge step.

| Platform | Link |
|---|---|
| LeetCode | [LC 349 — Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) *(counterpart)* |
| GFG | [GFG — Union of Two Sorted Arrays](https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/union-of-two-sorted-arrays/) |

---

### 10. Find Missing Number in an Array

**Core Idea:** XOR all indices 0..n with all array elements — whatever remains is the missing number. Alternatively: expected sum `n*(n+1)/2` minus actual sum.

| Platform | Link |
|---|---|
| LeetCode | [LC 268 — Missing Number](https://leetcode.com/problems/missing-number/) |
| GFG | [GFG — Missing Number](https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/find-the-missing-number-in-an-array/) |

---

### 11. Maximum Consecutive Ones

**Core Idea:** Single scan. Maintain a running count; reset to 0 on seeing 0. Track global max.

| Platform | Link |
|---|---|
| LeetCode | [LC 485 — Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/) |
| GFG | [GFG — Maximum Consecutive Ones](https://www.geeksforgeeks.org/problems/maximum-consecutive-ones3234/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/count-maximum-consecutive-ones-in-the-array/) |

---

### 12. Find the Number That Appears Once (Others Appear Twice)

**Core Idea:** XOR all elements. Every duplicate cancels out (`a XOR a = 0`). The remaining value is the answer.

| Platform | Link |
|---|---|
| LeetCode | [LC 136 — Single Number](https://leetcode.com/problems/single-number/) |
| GFG | [GFG — Element Appearing Once](https://www.geeksforgeeks.org/problems/element-appearing-once2552/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/find-the-number-that-appears-once-and-the-other-numbers-twice/) |

---

## 3.2 — Medium Problems

---

### 13. Longest Subarray with Sum K (Positives Only)

**Core Idea:** Sliding window — since all values are positive, expanding window increases sum, shrinking decreases it. O(n).

> ⚠️ This only works when all elements are positive. The next problem handles negatives too.

| Platform | Link |
|---|---|
| LeetCode | [LC 209 — Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) *(same window idea)* |
| GFG | [GFG — Longest Sub-Array with Sum K](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/) |

---

### 14. Longest Subarray with Sum K (Positives + Negatives)

**Core Idea:** Prefix sum + hashmap. Store `prefix_sum → earliest index`. If `prefix[j] - prefix[i] == K`, subarray `[i+1, j]` has sum K. O(n).

> This is the general solution. Sliding window doesn't work here because shrinking the window could skip a negative that makes the sum work.

| Platform | Link |
|---|---|
| LeetCode | [LC 325 — Maximum Size Subarray Sum Equals K *(Premium)*](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) |
| GFG | [GFG — Longest Sub-Array with Sum K](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1) |
| Article | [takeUforward](https://takeuforward.org/arrays/longest-subarray-with-sum-k-approach-2/) |

---

### 15. Sort Array of 0s, 1s, and 2s

**Core Idea:** **Dutch National Flag** algorithm. Three pointers: `lo`, `mid`, `hi`. Partition into three regions in a single pass. O(n) time, O(1) space.

| Platform | Link |
|---|---|
| LeetCode | [LC 75 — Sort Colors](https://leetcode.com/problems/sort-colors/) |
| GFG | [GFG — Sort 0s 1s 2s](https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/) |

---

### 16. Majority Element (> n/2 times)

**Core Idea:** **Boyer-Moore Voting Algorithm**. Maintain a candidate and a count. Increment on match, decrement otherwise. Candidate after the scan is the answer (verify if needed).

| Platform | Link |
|---|---|
| LeetCode | [LC 169 — Majority Element](https://leetcode.com/problems/majority-element/) |
| GFG | [GFG — Majority Element](https://www.geeksforgeeks.org/problems/majority-element-1587115620/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/) |

---

### 17. Kadane's Algorithm — Maximum Subarray Sum

**Core Idea:** For each position, decide: is it better to extend the previous subarray, or start fresh? `current = max(arr[i], current + arr[i])`. Track the global max.

| Platform | Link |
|---|---|
| LeetCode | [LC 53 — Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) |
| GFG | [GFG — Kadane's Algorithm](https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/) |

---

### 18. Print Subarray with Maximum Subarray Sum

**Core Idea:** Kadane's + track `start`, `end`, `temp_start`. When you reset (start fresh), update `temp_start`. When you find a new global max, update `start = temp_start` and `end = i`.

| Platform | Link |
|---|---|
| LeetCode | [LC 53](https://leetcode.com/problems/maximum-subarray/) *(return indices variant)* |
| GFG | [GFG — Max Sum Subarray](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/) |

---

### 19. Best Time to Buy and Sell Stock

**Core Idea:** Single pass greedy. Track the minimum price seen so far. At each step, profit = `price - min_so_far`. Track global max profit.

| Platform | Link |
|---|---|
| LeetCode | [LC 121 — Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |
| GFG | [GFG — Stock Buy and Sell](https://www.geeksforgeeks.org/problems/buy-and-sell-a-stock-best-time-to-buy-and-sell-stock/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/stock-buy-and-sell/) |

---

### 20. Rearrange Array Elements by Sign

**Core Idea:** Place positives at even indices, negatives at odd indices. Use two pointers for positive and negative positions, fill alternately. O(n) with extra space.

| Platform | Link |
|---|---|
| LeetCode | [LC 2149 — Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/) |
| GFG | [GFG — Rearrange Array Elements by Sign](https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1) |
| Article | [takeUforward](https://takeuforward.org/arrays/rearrange-array-elements-by-sign/) |

---

### 21. Next Permutation

**Core Idea:** Three-step in-place algorithm:
1. Find the rightmost index `i` where `arr[i] < arr[i+1]` (the "dip")
2. Find the rightmost element greater than `arr[i]` and swap them
3. Reverse everything after index `i`

| Platform | Link |
|---|---|
| LeetCode | [LC 31 — Next Permutation](https://leetcode.com/problems/next-permutation/) |
| GFG | [GFG — Next Permutation](https://www.geeksforgeeks.org/problems/next-permutation5226/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/) |

---

### 22. Leaders in an Array

**Core Idea:** Scan from right. An element is a leader if it's greater than all elements to its right. Maintain a running max from the right.

| Platform | Link |
|---|---|
| LeetCode | *(No direct LC equivalent)* |
| GFG | [GFG — Leaders in an Array](https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/leaders-in-an-array/) |

---

### 23. Longest Consecutive Sequence in an Array

**Core Idea:** Insert all elements in a HashSet. For each element that is the **start** of a sequence (i.e. `x-1` is not in set), count the sequence length greedily. O(n) overall.

| Platform | Link |
|---|---|
| LeetCode | [LC 128 — Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) |
| GFG | [GFG — Longest Consecutive Subsequence](https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/) |

---

### 24. Set Matrix Zeros

**Core Idea:** Use first row and first column as markers. Two passes: first pass marks which rows/cols need zeroing, second pass applies the zeros. O(1) extra space (in-place).

| Platform | Link |
|---|---|
| LeetCode | [LC 73 — Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) |
| GFG | [GFG — Set Matrix Zeroes](https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/set-matrix-zero/) |

---

### 25. Rotate Matrix by 90 Degrees

**Core Idea:** Two-step in-place: (1) **Transpose** the matrix (swap `arr[i][j]` with `arr[j][i]`), then (2) **Reverse each row**. This gives a 90° clockwise rotation.

| Platform | Link |
|---|---|
| LeetCode | [LC 48 — Rotate Image](https://leetcode.com/problems/rotate-image/) |
| GFG | [GFG — Rotate Matrix](https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/rotate-image-by-90-degree/) |

---

### 26. Spiral Traversal of a Matrix

**Core Idea:** Maintain four boundaries: `top`, `bottom`, `left`, `right`. Traverse right → down → left → up, shrinking the boundaries after each direction.

| Platform | Link |
|---|---|
| LeetCode | [LC 54 — Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) |
| GFG | [GFG — Spirally Traversing a Matrix](https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/spiral-traversal-of-matrix/) |

---

### 27. Count Subarrays with Given Sum

**Core Idea:** Prefix sum + hashmap. Count how many times `prefix[j] - K` has appeared before. When seen, all those earlier indices form valid subarrays ending at `j`. O(n).

| Platform | Link |
|---|---|
| LeetCode | [LC 560 — Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) |
| GFG | [GFG — Subarray with Given Sum](https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1) |
| Article | [takeUforward](https://takeuforward.org/arrays/count-subarray-sum-equals-k/) |

---

## 3.3 — Hard Problems

---

### 28. Pascal's Triangle

**Core Idea:** Three sub-problems in one: (1) find element at row `r`, col `c` using combinatorics `C(r-1, c-1)`, (2) find entire row `r` in O(r), (3) generate full triangle up to row `n`. Each row is derived from the previous.

| Platform | Link |
|---|---|
| LeetCode | [LC 118 — Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) |
| GFG | [GFG — Pascal's Triangle](https://www.geeksforgeeks.org/problems/pascals-triangle0652/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/) |

---

### 29. Majority Element (> n/3 Times)

**Core Idea:** Extended Boyer-Moore with **two candidates**. At most 2 elements can appear more than n/3 times. Maintain two candidate-count pairs. Final pass verifies both.

| Platform | Link |
|---|---|
| LeetCode | [LC 229 — Majority Element II](https://leetcode.com/problems/majority-element-ii/) |
| GFG | [GFG — Majority Element (n/3)](https://www.geeksforgeeks.org/problems/majority-vote/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/) |

---

### 30. 3Sum Problem

**Core Idea:** Sort array. Fix one element at index `i`, then two-pointer on the rest `[i+1, n-1]`. Skip duplicates at every level. O(n²).

| Platform | Link |
|---|---|
| LeetCode | [LC 15 — 3Sum](https://leetcode.com/problems/3sum/) |
| GFG | [GFG — 3Sum](https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/) |

---

### 31. 4Sum Problem

**Core Idea:** Sort array. Fix two elements `i` and `j`, then two-pointer on `[j+1, n-1]`. Skip duplicates at all three levels. O(n³). Use `long` to avoid overflow.

| Platform | Link |
|---|---|
| LeetCode | [LC 18 — 4Sum](https://leetcode.com/problems/4sum/) |
| GFG | [GFG — 4Sum](https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/) |

---

### 32. Largest Subarray with Sum 0

**Core Idea:** Prefix sum + hashmap. If `prefix[j] == prefix[i]`, then subarray `[i+1, j]` has sum 0. Store first occurrence of each prefix sum; maximize `j - i`.

| Platform | Link |
|---|---|
| LeetCode | [LC 325 *(Premium)*](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) *(K=0 case)* |
| GFG | [GFG — Largest Subarray with 0 Sum](https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/) |

---

### 33. Count Number of Subarrays with Given XOR K

**Core Idea:** Same prefix + hashmap pattern as subarray sum K, but with XOR. Store `prefix_xor → count`. If `prefix_xor[j] XOR K` has been seen before, those indices form valid subarrays.

| Platform | Link |
|---|---|
| LeetCode | [LC 1915 — Number of Wonderful Substrings](https://leetcode.com/problems/number-of-wonderful-substrings/) *(harder variant)* |
| GFG | [GFG — Count Subarrays with given XOR](https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/) |

---

### 34. Merge Overlapping Subintervals

**Core Idea:** Sort by start time. Maintain a result list. For each interval: if it overlaps with the last interval in result (`start <= result.back().end`), extend the end. Otherwise, push new interval.

| Platform | Link |
|---|---|
| LeetCode | [LC 56 — Merge Intervals](https://leetcode.com/problems/merge-intervals/) |
| GFG | [GFG — Merge Overlapping Intervals](https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/) |

---

### 35. Merge Two Sorted Arrays Without Extra Space

**Core Idea:** Two approaches — (1) **Gap method** (Shell sort variant): start gap = `(m+n+1)/2`, swap out-of-order pairs, halve gap each round; O(n log n). (2) Three-pointer with virtual merge from the back (more intuitive). O(n+m) passes.

| Platform | Link |
|---|---|
| LeetCode | [LC 88 — Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) |
| GFG | [GFG — Merge Without Extra Space](https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115621/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/) |

---

### 36. Find the Repeating and Missing Number

**Core Idea:** Multiple approaches — (1) XOR to find `XOR = repeat XOR missing`, then split by a set bit; (2) Math: use sum and sum-of-squares equations; (3) Cyclic sort / index marking. XOR or math approach is O(n) with O(1) space.

| Platform | Link |
|---|---|
| LeetCode | [LC 645 — Set Mismatch](https://leetcode.com/problems/set-mismatch/) *(simpler variant)* |
| GFG | [GFG — Find Missing and Repeating](https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/) |

---

### 37. Count Inversions

**Core Idea:** Modified **merge sort**. An inversion is a pair `(i, j)` where `i < j` but `arr[i] > arr[j]`. During merge: when a right-half element is smaller than a left-half element, all remaining left-half elements also form inversions with it. Count += `mid - left_pointer + 1`.

| Platform | Link |
|---|---|
| LeetCode | [LC 315 — Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) *(harder generalisation)* |
| GFG | [GFG — Count Inversions](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/count-inversions-in-an-array/) |

---

### 38. Reverse Pairs

**Core Idea:** Modified merge sort (same structure as Count Inversions). Condition changes: count pairs where `arr[i] > 2 * arr[j]` with `i < j`. Count before merging (separate counting pass), then merge normally.

| Platform | Link |
|---|---|
| LeetCode | [LC 493 — Reverse Pairs](https://leetcode.com/problems/reverse-pairs/) |
| GFG | [GFG — Reverse Pairs](https://www.geeksforgeeks.org/problems/reverse-pairs/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/count-reverse-pairs/) |

---

### 39. 2Sum Problem

**Core Idea:** Two approaches — (1) **Sort + two pointers**: sort, then shrink window from both ends; O(n log n). (2) **HashMap**: store complement needed; O(n). Problem usually asks for indices → use HashMap to preserve original indices.

| Platform | Link |
|---|---|
| LeetCode | [LC 1 — Two Sum](https://leetcode.com/problems/two-sum/) |
| GFG | [GFG — Two Sum](https://www.geeksforgeeks.org/problems/key-pair5616/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/) |

---

### 40. Maximum Product Subarray

**Core Idea:** Kadane-style but track both `max_product` and `min_product` at each step (negatives can flip sign and make min the new max). Reset to `arr[i]` when it's better to start fresh.

| Platform | Link |
|---|---|
| LeetCode | [LC 152 — Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) |
| GFG | [GFG — Maximum Product Subarray](https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array/) |

---

## Full Problem Table

| # | Problem | Difficulty | Pattern | LeetCode | GFG |
|---|---|---|---|---|---|
| 1 | Largest Element | Easy | Traversal | — | [GFG](https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1) |
| 2 | Second Largest (no sort) | Easy | Traversal | [LC 414](https://leetcode.com/problems/third-maximum-number/) | [GFG](https://www.geeksforgeeks.org/problems/second-largest3735/1) |
| 3 | Check if Sorted | Easy | Traversal | [LC 1752](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/) | [GFG](https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1) |
| 4 | Remove Duplicates (sorted) | Easy | Two Pointer | [LC 26](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [GFG](https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1) |
| 5 | Left Rotate by 1 | Easy | In-place | — | [GFG](https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1) |
| 6 | Left Rotate by D | Easy | Reversal | [LC 189](https://leetcode.com/problems/rotate-array/) | [GFG](https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1) |
| 7 | Move Zeros to End | Easy | Two Pointer | [LC 283](https://leetcode.com/problems/move-zeroes/) | [GFG](https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1) |
| 8 | Linear Search | Easy | Traversal | — | [GFG](https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1) |
| 9 | Union of Two Sorted Arrays | Easy | Two Pointer | [LC 349](https://leetcode.com/problems/intersection-of-two-arrays/) | [GFG](https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1) |
| 10 | Find Missing Number | Easy | XOR / Math | [LC 268](https://leetcode.com/problems/missing-number/) | [GFG](https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1) |
| 11 | Max Consecutive Ones | Easy | Scan | [LC 485](https://leetcode.com/problems/max-consecutive-ones/) | [GFG](https://www.geeksforgeeks.org/problems/maximum-consecutive-ones3234/1) |
| 12 | Single Number (others twice) | Easy | XOR | [LC 136](https://leetcode.com/problems/single-number/) | [GFG](https://www.geeksforgeeks.org/problems/element-appearing-once2552/1) |
| 13 | Longest Subarray Sum K (pos) | Medium | Sliding Window | [LC 209](https://leetcode.com/problems/minimum-size-subarray-sum/) | [GFG](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1) |
| 14 | Longest Subarray Sum K (all) | Medium | Prefix + HashMap | [LC 325 *](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) | [GFG](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1) |
| 15 | Sort 0s 1s 2s | Medium | Dutch Flag | [LC 75](https://leetcode.com/problems/sort-colors/) | [GFG](https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1) |
| 16 | Majority Element n/2 | Medium | Boyer-Moore | [LC 169](https://leetcode.com/problems/majority-element/) | [GFG](https://www.geeksforgeeks.org/problems/majority-element-1587115620/1) |
| 17 | Kadane's Algorithm | Medium | Kadane | [LC 53](https://leetcode.com/problems/maximum-subarray/) | [GFG](https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1) |
| 18 | Print Max Subarray | Medium | Kadane + Track | [LC 53](https://leetcode.com/problems/maximum-subarray/) | [GFG](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1) |
| 19 | Stock Buy and Sell | Medium | Greedy | [LC 121](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [GFG](https://www.geeksforgeeks.org/problems/buy-and-sell-a-stock-best-time-to-buy-and-sell-stock/1) |
| 20 | Rearrange by Sign | Medium | Two Pointer | [LC 2149](https://leetcode.com/problems/rearrange-array-elements-by-sign/) | [GFG](https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1) |
| 21 | Next Permutation | Medium | In-place | [LC 31](https://leetcode.com/problems/next-permutation/) | [GFG](https://www.geeksforgeeks.org/problems/next-permutation5226/1) |
| 22 | Leaders in an Array | Medium | Right Scan | — | [GFG](https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1) |
| 23 | Longest Consecutive Sequence | Medium | HashSet | [LC 128](https://leetcode.com/problems/longest-consecutive-sequence/) | [GFG](https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1) |
| 24 | Set Matrix Zeros | Medium | Matrix Marking | [LC 73](https://leetcode.com/problems/set-matrix-zeroes/) | [GFG](https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1) |
| 25 | Rotate Matrix 90° | Medium | Transpose+Reverse | [LC 48](https://leetcode.com/problems/rotate-image/) | [GFG](https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1) |
| 26 | Spiral Traversal | Medium | Boundary Shrink | [LC 54](https://leetcode.com/problems/spiral-matrix/) | [GFG](https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1) |
| 27 | Count Subarrays Sum K | Medium | Prefix + HashMap | [LC 560](https://leetcode.com/problems/subarray-sum-equals-k/) | [GFG](https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1) |
| 28 | Pascal's Triangle | Hard | Math / DP | [LC 118](https://leetcode.com/problems/pascals-triangle/) | [GFG](https://www.geeksforgeeks.org/problems/pascals-triangle0652/1) |
| 29 | Majority Element n/3 | Hard | Boyer-Moore x2 | [LC 229](https://leetcode.com/problems/majority-element-ii/) | [GFG](https://www.geeksforgeeks.org/problems/majority-vote/1) |
| 30 | 3Sum | Hard | Sort + Two Ptr | [LC 15](https://leetcode.com/problems/3sum/) | [GFG](https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1) |
| 31 | 4Sum | Hard | Sort + Two Ptr | [LC 18](https://leetcode.com/problems/4sum/) | [GFG](https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1) |
| 32 | Largest Subarray Sum 0 | Hard | Prefix + HashMap | [LC 325 *](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) | [GFG](https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1) |
| 33 | Count Subarrays XOR K | Hard | Prefix XOR + HashMap | — | [GFG](https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1) |
| 34 | Merge Overlapping Intervals | Hard | Sort + Greedy | [LC 56](https://leetcode.com/problems/merge-intervals/) | [GFG](https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1) |
| 35 | Merge Two Sorted Arrays (no space) | Hard | Gap Method | [LC 88](https://leetcode.com/problems/merge-sorted-array/) | [GFG](https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115621/1) |
| 36 | Find Repeating and Missing | Hard | XOR / Math | [LC 645](https://leetcode.com/problems/set-mismatch/) | [GFG](https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1) |
| 37 | Count Inversions | Hard | Merge Sort | [LC 315](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) | [GFG](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1) |
| 38 | Reverse Pairs | Hard | Merge Sort | [LC 493](https://leetcode.com/problems/reverse-pairs/) | [GFG](https://www.geeksforgeeks.org/problems/reverse-pairs/1) |
| 39 | 2Sum Problem | Hard | HashMap / Two Ptr | [LC 1](https://leetcode.com/problems/two-sum/) | [GFG](https://www.geeksforgeeks.org/problems/key-pair5616/1) |
| 40 | Maximum Product Subarray | Hard | Kadane Variant | [LC 152](https://leetcode.com/problems/maximum-product-subarray/) | [GFG](https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1) |

*\* = LeetCode Premium*

---

## Pattern Cheatsheet

### Two Pointer (sorted or partitioned)
```
Union of sorted arrays, Remove duplicates, Move zeros, Sort 0/1/2, 2Sum, 3Sum, 4Sum
Always: left pointer moves right, right pointer moves left (or both move right at different speeds)
```

### Prefix Sum + HashMap
```
Count subarrays with sum K, XOR K, sum 0, longest subarray with sum K
Key: store (prefix_value → index or count), look up (prefix - K) in map
```

### XOR Tricks
```
Missing number: XOR all [1..n] with all arr[i]
Single number: XOR everything, pairs cancel
Repeating + Missing: XOR to get (repeat XOR missing), then split by a set bit
```

### Kadane's Family
```
Max subarray sum: carry forward or restart (max(arr[i], curr + arr[i]))
Max product subarray: track both min and max (negatives flip sign)
```

### Modified Merge Sort
```
Count inversions: during merge, when right element < left element, count += remaining left elements
Reverse pairs: count pairs BEFORE merge (two pointers), then merge normally
```

### Boyer-Moore Voting
```
n/2 majority: one candidate, increment on match, decrement on mismatch
n/3 majority: two candidates, same idea with two slots
Always verify candidate in a second pass if not guaranteed to exist
```

### Matrix Tricks
```
Set zeros: use row[0] and col[0] as flags (O(1) space)
Rotate 90°: transpose then reverse each row
Spiral: four boundary pointers, shrink after each direction
```

---

## What These Patterns Unlock Later

| Pattern learned in Arrays | Reappears in |
|---|---|
| Prefix sum + hashmap | Subarray problems in Strings, DP |
| Two pointers | Linked list (slow/fast), Sliding window step |
| Merge sort (inversions) | External sorting, Segment trees |
| Kadane's | DP Chapter (1D DP introduction) |
| Boyer-Moore | Nowhere else — but appears in interviews frequently |
| Interval merging | Greedy chapter, scheduling problems |
| XOR tricks | Bit Manipulation chapter |
| Matrix traversal | Graph BFS/DFS on grids |

---

## Resources

| Resource | Link |
|---|---|
| Striver's A2Z Sheet | [takeuforward.org](https://takeuforward.org/dsa/strivers-a2z-sheet-learn-dsa-a-to-z) |
| YouTube — Arrays Playlist | [takeUforward Arrays](https://www.youtube.com/playlist?list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB) |
| takeUforward Article Hub | [takeuforward.org/arrays](https://takeuforward.org/category/data-structure/arrays/) |

---

## Where This Fits in the Sheet

Arrays (Step 3) is the foundation. The very next step, **Binary Search**, is really just "arrays, but exploit the sorted/monotonic structure" — the two-pointer and search-space instincts you build here carry over directly.

| ← Previous | Index | Next → |
|---|---|---|
| *Start of tracked steps* | [All Topics](README.md) | [Step 4 — Binary Search](BSReadme.md) |
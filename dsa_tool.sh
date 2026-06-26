#!/usr/bin/env bash
# =============================================================================
#  DSA Practice Tool — Binary Search Edition
#  Striver's A2Z DSA Sheet · Step 4 · 32 Problems
# =============================================================================
#  Features
#  --------
#  • Browse all 32 problems by Group or by Difficulty (Easy→Medium→Hard)
#  • Select a platform (LeetCode / GFG / Coding Ninjas) per problem
#  • Auto-generate Rust solution templates with correct function signatures
#  • Auto-manage Rust mod.rs hierarchy so `cargo build` always works
#  • Track status: not_started → in_progress → completed
#  • Progress dashboard with per-difficulty and per-group bars
#  • "Start Next" auto-picks the next unsolved problem in study order
# =============================================================================

set -uo pipefail

# ─── Paths ────────────────────────────────────────────────────────────────────
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="$SCRIPT_DIR/src"
BS_DIR="$SRC_DIR/binary_search"
MAIN_RS="$SRC_DIR/main.rs"
PROGRESS_FILE="$SCRIPT_DIR/.dsa_progress"
SOLUTIONS_DIR="$SCRIPT_DIR/solutions"   # non-Rust solutions (not built by cargo)

# ─── ANSI Colors ──────────────────────────────────────────────────────────────
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
BOLD='\033[1m'
DIM='\033[2m'
NC='\033[0m'

# ─── Problem Database ─────────────────────────────────────────────────────────
# Each entry: "id|name|difficulty|group|lc_url|gfg_url|cn_url|fn_signature|core_idea"
# group: 1=1D Arrays  2=Answer Space  3=2D Arrays
declare -a PROBLEMS=(
  # ── Group 1 · Binary Search on 1D Arrays ─────────────────────────────────
  "01|Binary Search to Find X in Sorted Array|Easy|1|https://leetcode.com/problems/binary-search/|https://www.geeksforgeeks.org/binary-search/||fn search(nums: Vec<i32>, target: i32) -> i32|Classic binary search — compare arr[mid] with target; shrink window each iteration"
  "02|Implement Lower Bound|Easy|1|https://leetcode.com/problems/search-insert-position/|https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1||fn lower_bound(nums: &[i32], x: i32) -> usize|First index where arr[i] >= x; set hi=mid when condition met; track result"
  "03|Implement Upper Bound|Easy|1|https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/|https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1||fn upper_bound(nums: &[i32], x: i32) -> usize|First index where arr[i] > x; similar to lower bound but condition is strictly greater"
  "04|Search Insert Position|Easy|1|https://leetcode.com/problems/search-insert-position/|https://www.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1||fn search_insert(nums: Vec<i32>, target: i32) -> i32|Return index if found else insertion index — this is exactly the lower bound"
  "05|Floor and Ceil in Sorted Array|Easy|1||https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1|https://www.naukri.com/code360/problems/ceil-the-floor_893098|fn floor_and_ceil(arr: &[i32], x: i32) -> (i32, i32)|Floor=largest<=x; Ceil=smallest>=x; both derivable from lower/upper bound templates"
  "06|Find First and Last Occurrence|Easy|1|https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/|https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1||fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32>|Lower bound for first occurrence; upper_bound-1 for last; two independent binary searches"
  "07|Count Occurrences of a Number in Sorted Array|Easy|1|https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/|https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1||fn count_occurrences(nums: &[i32], target: i32) -> i32|count = last_occurrence - first_occurrence + 1; direct application of problem 6"
  "08|Search in Rotated Sorted Array I (No Duplicates)|Medium|1|https://leetcode.com/problems/search-in-rotated-sorted-array/|https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1||fn search(nums: Vec<i32>, target: i32) -> i32|One half is always sorted; determine which; check if target lies there and move accordingly"
  "09|Search in Rotated Sorted Array II (With Duplicates)|Medium|1|https://leetcode.com/problems/search-in-rotated-sorted-array-ii/|https://www.geeksforgeeks.org/problems/search-in-rotated-array2624/1||fn search(nums: Vec<i32>, target: i32) -> bool|Duplicates cause ambiguity; when arr[lo]==arr[mid]==arr[hi] do lo++ hi-- and retry"
  "10|Minimum in Rotated Sorted Array|Medium|1|https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/|https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1||fn find_min(nums: Vec<i32>) -> i32|Min is at the inflection point; sorted half leftmost is a candidate; move toward unsorted"
  "11|How Many Times Array Has Been Rotated|Easy|1||https://www.geeksforgeeks.org/problems/rotation4723/1|https://www.naukri.com/code360/problems/rotation_7449070|fn how_many_times(arr: Vec<i32>) -> usize|Number of rotations equals index of the minimum element; reuse problem 10"
  "12|Single Element in a Sorted Array|Medium|1|https://leetcode.com/problems/single-element-in-a-sorted-array/|https://www.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1||fn single_non_duplicate(nums: Vec<i32>) -> i32|Pairs sit at even-odd index pairs; if arr[mid]==arr[mid^1] single is on the right else left"
  "13|Find Peak Element|Medium|1|https://leetcode.com/problems/find-peak-element/|https://www.geeksforgeeks.org/problems/peak-element/1||fn find_peak_element(nums: Vec<i32>) -> i32|If arr[mid] < arr[mid+1] the peak is on the right; otherwise it is on the left or at mid"
  # ── Group 2 · Binary Search on Answer Space ────────────────────────────────
  "14|Find Square Root of a Number (Floor)|Easy|2|https://leetcode.com/problems/sqrtx/|https://www.geeksforgeeks.org/problems/square-root/1||fn my_sqrt(x: u64) -> u64|BS in [1,n]; if mid*mid<=n it is a candidate; move lo=mid+1; answer is hi at the end"
  "15|Find the Nth Root of a Number|Easy|2||https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1|https://www.naukri.com/code360/problems/nth-root-of-m_1062679|fn nth_root(n: u32, m: u64) -> i64|BS in [1,m]; helper computes mid^n and returns -1/0/1 for too-large/exact/too-small"
  "16|Koko Eating Bananas|Medium|2|https://leetcode.com/problems/koko-eating-bananas/|https://www.geeksforgeeks.org/problems/koko-eating-bananas/1||fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32|BS on speed k in [1,max(piles)]; total=sum(ceil(pile/k)); find minimum k where total<=h"
  "17|Minimum Days to Make M Bouquets|Medium|2|https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/|https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1||fn min_days(bloom_day: Vec<i32>, m: i32, k: i32) -> i32|BS on day in [min,max](bloomDay); check if m bouquets of k consecutive bloomed flowers possible"
  "18|Find the Smallest Divisor Given a Threshold|Medium|2|https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/|https://www.geeksforgeeks.org/problems/find-the-smallest-divisor/1||fn smallest_divisor(nums: Vec<i32>, threshold: i32) -> i32|BS divisor in [1,max(nums)]; sum=sum(ceil(nums[i]/d)); find minimum d where sum<=threshold"
  "19|Capacity to Ship Packages Within D Days|Medium|2|https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/|https://www.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1||fn ship_within_days(weights: Vec<i32>, days: i32) -> i32|BS capacity in [max(weights),sum(weights)]; verify all packages ship within D days"
  "20|Kth Missing Positive Number|Easy|2|https://leetcode.com/problems/kth-missing-positive-number/|https://www.geeksforgeeks.org/problems/kth-missing-positive-number2913/1||fn find_kth_missing(arr: Vec<i32>, k: i32) -> i32|Missing before arr[i] = arr[i]-(i+1); find first index where that count >= k"
  "21|Aggressive Cows|Medium|2||https://www.geeksforgeeks.org/problems/aggressive-cows/1|https://www.naukri.com/code360/problems/aggressive-cows_1082559|fn aggressive_cows(stalls: Vec<i32>, k: i32) -> i32|BS on min distance in [1,max-min stalls]; greedily check if all c cows can be placed"
  "22|Book Allocation Problem|Medium|2||https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1|https://www.naukri.com/code360/problems/allocate-books_1090540|fn allocate_books(pages: Vec<i32>, m: i32) -> i32|BS on max pages in [max(pages),sum(pages)]; greedily assign contiguous books to m students"
  "23|Split Array — Largest Sum|Hard|2|https://leetcode.com/problems/split-array-largest-sum/|https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1||fn split_array(nums: Vec<i32>, k: i32) -> i32|Identical to Book Allocation; BS on max subarray sum; check if splits into at most k parts"
  "24|Painter's Partition Problem|Hard|2|https://leetcode.com/problems/split-array-largest-sum/|https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1|https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557|fn painter_partition(boards: Vec<i32>, k: i32) -> i32|Mirror of Book Allocation; minimise maximum time; assign contiguous boards to k painters"
  "25|Minimise Maximum Distance Between Gas Stations|Hard|2|https://leetcode.com/problems/minimize-max-distance-to-gas-station/|https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1||fn min_max_gas_dist(stations: Vec<i32>, k: i32) -> f64|Floating-point BS on max gap d; count extra stations needed for each gap; stop when count<=k"
  "26|Median of Two Sorted Arrays|Hard|2|https://leetcode.com/problems/median-of-two-sorted-arrays/|https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1||fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64|BS partition on smaller array; ensure maxLeft1<=minRight2 and maxLeft2<=minRight1; O(log min)"
  "27|Kth Element of Two Sorted Arrays|Hard|2|https://leetcode.com/problems/median-of-two-sorted-arrays/|https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1|https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164290|fn kth_element(arr1: Vec<i32>, arr2: Vec<i32>, k: i32) -> i32|BS cut on smaller array so combined left partition has exactly k elements; generalised median"
  # ── Group 3 · Binary Search on 2D Arrays ───────────────────────────────────
  "28|Find the Row with Maximum Number of 1s|Easy|3||https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1||fn row_with_max_ones(mat: Vec<Vec<i32>>) -> i32|Each row is sorted (0s then 1s); upper_bound finds first 1; track row with leftmost 1"
  "29|Search in a 2D Matrix|Medium|3|https://leetcode.com/problems/search-a-2d-matrix/|https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1||fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool|Treat matrix as virtual 1D sorted array; map virtual index to (mid/cols, mid%cols)"
  "30|Search in Row-wise and Column-wise Sorted Matrix|Medium|3|https://leetcode.com/problems/search-a-2d-matrix-ii/|https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1||fn search_matrix_ii(matrix: Vec<Vec<i32>>, target: i32) -> bool|Staircase from top-right; smaller->move down; larger->move left; O(m+n)"
  "31|Find Peak Element in 2D Matrix|Hard|3|https://leetcode.com/problems/find-a-peak-element-ii/|https://www.geeksforgeeks.org/problems/peak-element-in-2d-matrix/1||fn find_peak_grid(mat: Vec<Vec<i32>>) -> Vec<i32>|BS on columns; for mid-col find row with global max; shift toward larger neighbour column"
  "32|Median in a Row-wise Sorted Matrix|Hard|3|https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/|https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1|https://www.naukri.com/code360/problems/median-of-a-row-wise-sorted-matrix_1115473|fn matrix_median(matrix: Vec<Vec<i32>>) -> i32|BS value range [min,max]; count elements<=mid per row with BS; total>(m*n)/2 means reduce hi"
)

declare -a GROUP_NAMES=("" "Binary Search on 1D Arrays" "Binary Search on Answer Space" "Binary Search on 2D Arrays")
declare -a GROUP_DIRS=("" "group_1_1d_arrays" "group_2_answer_space" "group_3_2d_arrays")

# ─── Platform Language Support ────────────────────────────────────────────────
# Languages each judge accepts (Rust is listed only where supported — notably GFG
# does NOT offer Rust). The first entry is the default. This is just data: edit it
# if a platform adds/drops a language.
declare -A PLATFORM_LANGS=(
  ["LC"]="Rust C++ Java Python3 C C# JavaScript TypeScript Go Kotlin Swift Ruby"
  ["GFG"]="C++ Java Python3 C# JavaScript PHP"
  ["CN"]="Rust C++ Java Python3 JavaScript C C# Kotlin Go Swift"
)
declare -A PLATFORM_DIR=( ["LC"]="leetcode" ["GFG"]="gfg" ["CN"]="coding_ninjas" )

# Language → source-file extension
declare -A LANG_EXT=(
  ["Rust"]="rs" ["C++"]="cpp" ["Java"]="java" ["Python3"]="py" ["Python"]="py"
  ["C"]="c" ["C#"]="cs" ["JavaScript"]="js" ["TypeScript"]="ts" ["Go"]="go"
  ["Kotlin"]="kt" ["Swift"]="swift" ["Ruby"]="rb" ["PHP"]="php"
)
# Languages whose line comments start with '#' (everything else uses '//')
declare -A LANG_HASH_COMMENT=( ["Python3"]=1 ["Python"]=1 ["Ruby"]=1 )

# ─── Problem Statements ───────────────────────────────────────────────────────
# Each value is the full problem statement; \n is used as a line separator and
# expanded when writing into Rust doc-comments.
declare -A PROBLEM_STATEMENTS
PROBLEM_STATEMENTS["01"]="Given an array of integers nums sorted in ascending order and an integer target, write an algorithm to determine if target exists in the array.\nReturn its index if found, or -1 if not found. You must write an algorithm with O(log n) runtime.\n\nExample 1:  nums = [-1, 0, 3, 5, 9, 12],  target = 9  →  4\nExample 2:  nums = [-1, 0, 3, 5, 9, 12],  target = 2  →  -1\n\nConstraints:\n  1 <= nums.length <= 10^4\n  -10^4 < nums[i], target < 10^4\n  All integers in nums are unique and sorted in ascending order."

PROBLEM_STATEMENTS["02"]="Given a sorted array arr[] of size n and a value x, return the 0-based index of the first element >= x.\nIf every element is less than x, return n.\n\nExample 1:  arr = [1, 2, 4, 4, 7],  x = 4  →  2  (first index where arr[i] >= 4)\nExample 2:  arr = [1, 2, 4, 4, 7],  x = 5  →  4  (first index where arr[i] >= 5)\nExample 3:  arr = [1, 2, 4, 4, 7],  x = 8  →  5  (no element >= 8, return n)\n\nConstraints:\n  1 <= n <= 10^5\n  1 <= arr[i], x <= 10^9\n  arr is sorted in non-decreasing order."

PROBLEM_STATEMENTS["03"]="Given a sorted array arr[] of size n and a value x, return the 0-based index of the first element strictly greater than x.\nIf every element is <= x, return n.\n\nExample 1:  arr = [1, 2, 4, 4, 7],  x = 4  →  4  (first index where arr[i] > 4)\nExample 2:  arr = [1, 2, 4, 4, 7],  x = 0  →  0  (first index where arr[i] > 0)\nExample 3:  arr = [1, 2, 4, 4, 7],  x = 7  →  5  (no element > 7, return n)\n\nConstraints:\n  1 <= n <= 10^5\n  arr is sorted in non-decreasing order."

PROBLEM_STATEMENTS["04"]="Given a sorted array of distinct integers and a target value, return the index if the target is found.\nIf not, return the index where it would be inserted to keep the array sorted.\nYou must write an algorithm with O(log n) runtime.\n\nExample 1:  nums = [1, 3, 5, 6],  target = 5  →  2\nExample 2:  nums = [1, 3, 5, 6],  target = 2  →  1\nExample 3:  nums = [1, 3, 5, 6],  target = 7  →  4\n\nConstraints:\n  1 <= nums.length <= 10^4\n  -10^4 <= nums[i] <= 10^4\n  nums contains distinct values sorted in ascending order."

PROBLEM_STATEMENTS["05"]="Given a sorted array arr[] and a value x, find:\n  Floor  — the largest element in arr[] that is <= x  (return -1 if none)\n  Ceil   — the smallest element in arr[] that is >= x  (return -1 if none)\n\nExample 1:  arr = [1, 2, 8, 10, 10, 12, 19],  x = 5   →  floor = 2,  ceil = 8\nExample 2:  arr = [1, 2, 8, 10, 10, 12, 19],  x = 20  →  floor = 19, ceil = -1\nExample 3:  arr = [1, 2, 8, 10, 10, 12, 19],  x = 0   →  floor = -1, ceil = 1\n\nConstraints:\n  1 <= arr.length <= 10^5\n  arr is sorted in non-decreasing order."

PROBLEM_STATEMENTS["06"]="Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of target.\nReturn [-1, -1] if target is not present.\nYou must write an algorithm with O(log n) runtime.\n\nExample 1:  nums = [5, 7, 7, 8, 8, 10],  target = 8  →  [3, 4]\nExample 2:  nums = [5, 7, 7, 8, 8, 10],  target = 6  →  [-1, -1]\nExample 3:  nums = [],                    target = 0  →  [-1, -1]\n\nConstraints:\n  0 <= nums.length <= 10^5\n  -10^9 <= nums[i] <= 10^9\n  nums is sorted in non-decreasing order."

PROBLEM_STATEMENTS["07"]="Given a sorted array arr[] and a target integer, count the number of times target appears in arr[].\n\nExample 1:  arr = [1, 1, 2, 2, 2, 3],  target = 2  →  3\nExample 2:  arr = [1, 1, 2, 2, 2, 3],  target = 4  →  0\n\nHint: count = last_occurrence_index - first_occurrence_index + 1.\nReuse your lower_bound / upper_bound implementations from problems 2 and 3.\n\nConstraints:\n  1 <= arr.length <= 10^5\n  arr is sorted in non-decreasing order."

PROBLEM_STATEMENTS["08"]="There is an integer array nums sorted in ascending order (with distinct values) that has been rotated at an unknown pivot.\nGiven nums and target, return the index of target or -1 if not found.\nYou must write an O(log n) algorithm.\n\nExample 1:  nums = [4, 5, 6, 7, 0, 1, 2],  target = 0  →  4\nExample 2:  nums = [4, 5, 6, 7, 0, 1, 2],  target = 3  →  -1\nExample 3:  nums = [1],                     target = 0  →  -1\n\nKey insight: at least one half of the array is always sorted.\n\nConstraints:\n  1 <= nums.length <= 5000\n  All values are distinct."

PROBLEM_STATEMENTS["09"]="Same as Problem 08 but nums may contain duplicates.\nReturn true if target exists, false otherwise.\n\nExample 1:  nums = [2, 5, 6, 0, 0, 1, 2],  target = 0  →  true\nExample 2:  nums = [2, 5, 6, 0, 0, 1, 2],  target = 3  →  false\n\nKey insight: when arr[lo] == arr[mid] == arr[hi] you cannot determine which half is sorted;\ndo lo++, hi-- and retry.\n\nConstraints:\n  1 <= nums.length <= 5000\n  -10^4 <= nums[i], target <= 10^4"

PROBLEM_STATEMENTS["10"]="Suppose an array of length n sorted in ascending order is rotated between 1 and n times.\nFind the minimum element. You must write an algorithm that runs in O(log n).\n\nExample 1:  nums = [3, 4, 5, 1, 2]     →  1\nExample 2:  nums = [4, 5, 6, 7, 0, 1, 2]  →  0\nExample 3:  nums = [11, 13, 15, 17]    →  11  (rotated 4 = 0 times)\n\nConstraints:\n  n >= 1, all values are unique."

PROBLEM_STATEMENTS["11"]="Given a sorted array that has been rotated k times (right rotation), find k.\nk equals the index of the minimum element in the rotated array.\n\nExample 1:  arr = [4, 5, 6, 7, 0, 1, 2]  →  4  (minimum 0 is at index 4)\nExample 2:  arr = [1, 2, 3, 4, 5]        →  0  (not rotated)\nExample 3:  arr = [3, 4, 5, 1, 2]        →  3  (minimum 1 is at index 3)\n\nConstraints:\n  All values are distinct.\n  Array was originally sorted in ascending order."

PROBLEM_STATEMENTS["12"]="You are given a sorted array consisting of only integers where every element appears exactly twice,\nexcept for one element which appears exactly once.\nReturn the single element. O(log n) time and O(1) space required.\n\nExample 1:  nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]  →  2\nExample 2:  nums = [3, 3, 7, 7, 10, 11, 11]      →  10\n\nKey insight: before the single element, pairs occupy (even, odd) index slots;\nafter it, they occupy (odd, even) slots. Check if arr[mid] == arr[mid ^ 1].\n\nConstraints:\n  1 <= nums.length <= 10^5\n  Array is sorted."

PROBLEM_STATEMENTS["13"]="A peak element is an element that is strictly greater than its neighbors.\nGiven a 0-indexed integer array nums, find a peak element and return its index.\nFor boundary elements, consider nums[-1] = nums[n] = -infinity.\nThere may be multiple peaks; return any.\nYou must write an O(log n) algorithm.\n\nExample 1:  nums = [1, 2, 3, 1]          →  2\nExample 2:  nums = [1, 2, 1, 3, 5, 6, 4] →  5  (or 1, both valid)\n\nConstraints:\n  1 <= nums.length <= 1000\n  nums[i] != nums[i+1] for all valid i"

PROBLEM_STATEMENTS["14"]="Given a non-negative integer x, return the square root of x rounded down to the nearest integer.\nThe returned integer should be non-negative.\nDo not use any built-in exponent function or operator (e.g. pow(x, 0.5) or x ** 0.5).\n\nExample 1:  x = 4   →  2\nExample 2:  x = 8   →  2  (sqrt(8) ≈ 2.82, floor = 2)\n\nConstraints:\n  0 <= x <= 2^31 - 1"

PROBLEM_STATEMENTS["15"]="Given two numbers n and m, find the nth root of m.\nIf m does not have a perfect integer nth root, return -1.\n\nExample 1:  n = 2, m = 9   →  3   (3^2 = 9)\nExample 2:  n = 3, m = 27  →  3   (3^3 = 27)\nExample 3:  n = 2, m = 5   →  -1  (no integer whose square is 5)\n\nHint: binary search in [1, m]; use a helper that computes mid^n carefully to avoid overflow.\n\nConstraints:\n  1 <= n <= 30\n  1 <= m <= 10^9"

PROBLEM_STATEMENTS["16"]="Koko has n piles of bananas. The guards leave for h hours.\nEach hour Koko picks one pile and eats up to k bananas from it. If the pile has < k bananas she eats all of them.\nFind the minimum eating speed k (bananas/hour) such that she can eat all piles within h hours.\n\nExample 1:  piles = [3, 6, 7, 11],  h = 8   →  4\nExample 2:  piles = [30, 11, 23, 4, 20],  h = 5   →  30\nExample 3:  piles = [30, 11, 23, 4, 20],  h = 6   →  23\n\nConstraints:\n  1 <= piles.length <= h\n  1 <= piles[i] <= 10^9"

PROBLEM_STATEMENTS["17"]="You have n flowers. bloomDay[i] is the day flower i blooms.\nTo make one bouquet you need k adjacent bloomed flowers.\nReturn the minimum number of days needed to make m bouquets, or -1 if impossible.\n\nExample 1:  bloomDay = [1,10,3,10,2],  m = 3,  k = 1  →  3\nExample 2:  bloomDay = [1,10,3,10,2],  m = 3,  k = 2  →  -1\nExample 3:  bloomDay = [7,7,7,7,12,7,7],  m = 2,  k = 3  →  12\n\nConstraints:\n  bloomDay.length == n\n  1 <= n, m*k <= 10^9\n  1 <= bloomDay[i] <= 10^9"

PROBLEM_STATEMENTS["18"]="Given an array of integers nums and an integer threshold, find the smallest divisor d such that\nthe sum of ceil(nums[i] / d) for all i is <= threshold.\n\nExample 1:  nums = [1, 2, 5, 9],  threshold = 6   →  5\n  (d=5: ceil(1/5)+ceil(2/5)+ceil(5/5)+ceil(9/5) = 1+1+1+2 = 5 <= 6)\nExample 2:  nums = [44, 22, 33, 11, 100],  threshold = 5  →  44\n\nConstraints:\n  1 <= nums[i] <= 10^6\n  nums.length <= threshold <= 10^6"

PROBLEM_STATEMENTS["19"]="You are given an array weights where weights[i] is the weight of the ith package.\nPackages must be loaded in order. Find the minimum weight capacity of a ship so that\nall packages are shipped within days days.\n\nExample 1:  weights = [1,2,3,4,5,6,7,8,9,10],  days = 5  →  15\nExample 2:  weights = [3,2,2,4,1,4],  days = 3  →  6\nExample 3:  weights = [1,2,3,1,1],  days = 4   →  3\n\nConstraints:\n  1 <= days <= weights.length <= 500\n  1 <= weights[i] <= 500"

PROBLEM_STATEMENTS["20"]="Given a strictly increasing array arr[] of positive integers and a positive integer k,\nreturn the kth positive integer that is missing from the array.\n\nExample 1:  arr = [2, 3, 4, 7, 11],  k = 5  →  9\n  (missing: 1, 5, 6, 8, 9 — 5th is 9)\nExample 2:  arr = [1, 2, 3, 4],  k = 2  →  6\n\nKey insight: the count of positive integers missing before arr[i] is arr[i] - (i+1).\nBinary search for the first index where this count >= k.\n\nConstraints:\n  1 <= arr.length <= 1000\n  1 <= k <= 1000"

PROBLEM_STATEMENTS["21"]="Given n stall positions (not necessarily sorted) and an integer k representing the number of cows,\nplace k cows in the stalls such that the minimum distance between any two cows is maximised.\nReturn that maximum minimum distance.\n\nExample 1:  stalls = [0, 3, 4, 7, 10, 9],  k = 4  →  3\nExample 2:  stalls = [4, 2, 1, 3, 6],  k = 2  →  5\n\nConstraints:\n  2 <= k <= n <= 10^5\n  0 <= stalls[i] <= 10^9"

PROBLEM_STATEMENTS["22"]="Given an array pages[] where pages[i] = pages in book i, and m students,\nallocate all books to students such that:\n  - Each student gets a contiguous sequence of books.\n  - Every book is allocated to exactly one student.\n  - The maximum pages assigned to any student is minimised.\nReturn -1 if allocation is impossible (m > number of books).\n\nExample 1:  pages = [12, 34, 67, 90],  m = 2  →  113\n  (Student 1: [12,34,67]=113, Student 2: [90]=90; max=113)\nExample 2:  pages = [15, 17, 20],  m = 2  →  32\n\nConstraints:\n  1 <= pages.length <= 10^5\n  1 <= pages[i] <= 10^3"

PROBLEM_STATEMENTS["23"]="Given an integer array nums and an integer k, split nums into k non-empty subarrays\nto minimise the largest subarray sum. Return that minimised largest sum.\n\nExample 1:  nums = [7, 2, 5, 10, 8],  k = 2  →  18  ([7,2,5] and [10,8])\nExample 2:  nums = [1, 2, 3, 4, 5],   k = 2  →  9   ([1,2,3,4] and [5])\n\nNote: this is the same pattern as Book Allocation — binary search on the answer.\n\nConstraints:\n  1 <= nums.length <= 1000\n  0 <= nums[i] <= 10^6\n  1 <= k <= min(50, nums.length)"

PROBLEM_STATEMENTS["24"]="Given n boards of lengths boards[] and k painters, assign contiguous sections to painters\nso that the maximum time any painter works is minimised.\nEach painter paints at 1 unit of board per unit of time.\n\nExample 1:  boards = [10, 20, 30, 40],  k = 2  →  60\n  (Painter 1: [10,20,30]=60, Painter 2: [40]=40; max=60)\nExample 2:  boards = [10, 20, 30],  k = 3  →  30\n\nNote: identical pattern to Book Allocation and Split Array Largest Sum.\n\nConstraints:\n  1 <= k <= boards.length <= 10^5\n  1 <= boards[i] <= 10^6"

PROBLEM_STATEMENTS["25"]="Given a sorted array of gas station positions along a highway and an integer k,\nadd k additional gas stations to minimise the maximum distance between any two adjacent stations.\nReturn the answer within an error of 10^-6.\n\nExample 1:  stations = [1,2,3,4,5,6,7,8,9,10],  k = 9  →  0.500000\nExample 2:  stations = [23,24,36,39,46,56,57,65,84,98],  k = 1  →  14.000000\n\nConstraints:\n  10 <= stations.length <= 2000\n  0 <= stations[i] <= 10^8\n  stations is sorted in increasing order\n  1 <= k <= 10^6"

PROBLEM_STATEMENTS["26"]="Given two sorted arrays nums1 and nums2 of sizes m and n, return the median of the two arrays.\nOverall runtime must be O(log(min(m, n))).\n\nExample 1:  nums1 = [1, 3],  nums2 = [2]          →  2.0\nExample 2:  nums1 = [1, 2],  nums2 = [3, 4]       →  2.5\n\nKey insight: binary search a partition on the smaller array such that the\ncombined left partition has (m+n+1)/2 elements AND maxLeft1<=minRight2 AND maxLeft2<=minRight1.\n\nConstraints:\n  nums1.length + nums2.length >= 1\n  Both arrays are sorted."

PROBLEM_STATEMENTS["27"]="Given two sorted arrays arr1 and arr2 of sizes m and n, and an integer k (1-indexed),\nreturn the kth smallest element in the merged sorted array.\n\nExample 1:  arr1 = [2,3,6,7,9],  arr2 = [1,4,8,10],  k = 5  →  6\nExample 2:  arr1 = [100,112,256,349,770],  arr2 = [72,86,113,119,265,445,893],  k = 7  →  256\n\nKey insight: same binary search partition as Problem 26 but stop when the left\npartition has exactly k elements.\n\nConstraints:\n  1 <= k <= m+n\n  Both arrays are sorted."

PROBLEM_STATEMENTS["28"]="Given a boolean matrix mat[][] where each row is sorted (0s followed by 1s),\nreturn the 0-indexed row number that has the most 1s.\nIf two rows have equal 1s, return the row with the smaller index. Return -1 if no 1 exists.\n\nExample 1:  mat = [[0,1,1,1],[0,0,1,1],[1,1,1,1],[0,0,0,0]]  →  2\nExample 2:  mat = [[0,0],[1,1]]  →  1\n\nConstraints:\n  1 <= mat.length, mat[0].length <= 1000\n  mat[i][j] is 0 or 1\n  Each row is sorted in non-decreasing order."

PROBLEM_STATEMENTS["29"]="You are given an m x n integer matrix with the following properties:\n  - Each row is sorted in non-decreasing order.\n  - The first integer of each row is greater than the last integer of the previous row.\nReturn true if target exists in the matrix.\n\nExample 1:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]],  target = 3   →  true\nExample 2:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]],  target = 13  →  false\n\nKey insight: the matrix is equivalent to a single sorted 1D array. Map virtual index i to (i/cols, i%cols).\n\nConstraints:\n  m, n >= 1\n  -10^4 <= matrix[i][j], target <= 10^4"

PROBLEM_STATEMENTS["30"]="Write an efficient algorithm that searches for a value target in an m x n integer matrix where:\n  - Integers in each row are sorted in ascending from left to right.\n  - Integers in each column are sorted in ascending from top to bottom.\n\nExample 1:  matrix = [[1,4,7,11],[2,5,8,12],[3,6,9,16],[10,13,14,17]],  target = 5   →  true\nExample 2:  matrix = [[1,4,7,11],[2,5,8,12],[3,6,9,16],[10,13,14,17]],  target = 20  →  false\n\nKey insight: start at top-right; if element < target move down; if > target move left. O(m+n).\n\nConstraints:\n  m, n >= 1\n  -10^9 <= matrix[i][j] <= 10^9"

PROBLEM_STATEMENTS["31"]="A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors\n(left, right, top, bottom).\nGiven a 0-indexed m x n matrix mat, return the position of any peak element.\nYou must write an algorithm that runs in O(m log n) or O(n log m).\n\nExample 1:  mat = [[1,4],[3,2]]       →  [0,1]  (4 > 1,2; valid peak)\nExample 2:  mat = [[10,20,15],[21,30,14],[7,16,32]]  →  [1,1]  (30 is a peak)\n\nConstraints:\n  1 <= mat.length, mat[0].length <= 500\n  No two adjacent cells are equal."

PROBLEM_STATEMENTS["32"]="Given an m x n matrix where each row is sorted in non-decreasing order and m*n is odd,\nreturn the median of the matrix.\n\nExample 1:  matrix = [[1,3,5],[2,6,9],[3,6,9]]  →  5\nExample 2:  matrix = [[1,1,1],[2,2,2],[3,3,3]]  →  2\n\nKey insight: binary search on the value range [global_min, global_max].\nFor each candidate mid, count elements <= mid using binary search per row.\nMedian is the smallest value where that total count > (m*n)/2.\n\nConstraints:\n  1 <= m, n <= 500\n  1 <= matrix[i][j] <= 10^6\n  m*n is odd."

# ─── Field Parsers ────────────────────────────────────────────────────────────
# Split a "a|b|c|..." record without forking an external `cut` for every access.
field() {
  local -a _f
  IFS='|' read -r -a _f <<< "${1}"
  printf '%s' "${_f[$(( ${2} - 1 ))]-}"
}
p_id()    { field "${1}" 1; }
p_name()  { field "${1}" 2; }
p_diff()  { field "${1}" 3; }
p_group() { field "${1}" 4; }
p_lc()    { field "${1}" 5; }
p_gfg()   { field "${1}" 6; }
p_cn()    { field "${1}" 7; }
p_sig()   { field "${1}" 8; }
p_idea()  { field "${1}" 9; }

# Parse a record once into P_* globals — no subshell, no `cut`, no per-field forks.
# Hot loops should call this and read $P_ID/$P_DIFF/… instead of $(p_id "$p") etc.
unpack_problem() {
  IFS='|' read -r P_ID P_NAME P_DIFF P_GROUP P_LC P_GFG P_CN P_SIG P_IDEA <<< "${1}"
}

# id → record lookup, built once, replaces linear scans over PROBLEMS.
declare -A PROB_BY_ID
for _p in "${PROBLEMS[@]}"; do PROB_BY_ID["${_p%%|*}"]="${_p}"; done
unset _p

diff_color() {
  case "${1}" in
    Easy)   printf '%b' "${GREEN}${BOLD}Easy${NC}" ;;
    Medium) printf '%b' "${YELLOW}${BOLD}Medium${NC}" ;;
    Hard)   printf '%b' "${RED}${BOLD}Hard${NC}" ;;
    *)      printf '%s' "${1}" ;;
  esac
}

status_icon() {
  case "${1}" in
    completed)   printf '%b' "${GREEN}✓${NC}" ;;
    in_progress) printf '%b' "${YELLOW}◎${NC}" ;;
    *)           printf '%b' "${DIM}○${NC}" ;;
  esac
}

# ─── Progress Tracking ────────────────────────────────────────────────────────
# Format per line: id|status|platform|date_started|date_completed|language
# status: not_started | in_progress | completed
# The trailing language field was added later; older 5-field lines load fine
# (language simply reads as empty) and are upgraded on the next write.

# In-memory cache of the progress file, loaded once and refreshed on every write.
# Reads (get_status/get_platform/…) hit RAM, not the filesystem.
declare -A ST_STATUS ST_PLATFORM ST_START ST_DONE ST_LANG

load_progress() {
  ST_STATUS=(); ST_PLATFORM=(); ST_START=(); ST_DONE=(); ST_LANG=()
  local id status platform sdate cdate lang
  while IFS='|' read -r id status platform sdate cdate lang; do
    [[ -z "${id}" ]] && continue
    ST_STATUS["${id}"]="${status}"
    ST_PLATFORM["${id}"]="${platform}"
    ST_START["${id}"]="${sdate}"
    ST_DONE["${id}"]="${cdate}"
    ST_LANG["${id}"]="${lang}"
  done < "${PROGRESS_FILE}"
}

init_progress() {
  if [[ ! -f "${PROGRESS_FILE}" ]]; then
    local today
    today=$(date '+%Y-%m-%d')
    for p in "${PROBLEMS[@]}"; do
      printf '%s|not_started|||%s|\n' "${p%%|*}" "${today}"
    done > "${PROGRESS_FILE}"
  fi
  load_progress
}

get_status()   { printf '%s' "${ST_STATUS[${1}]:-not_started}"; }
get_platform() { printf '%s' "${ST_PLATFORM[${1}]:-}"; }
get_language() { printf '%s' "${ST_LANG[${1}]:-}"; }

# set_status <id> <status> [platform] [language]
# Omitting language (passing 3 args) preserves the previously recorded one; pass
# an explicit empty string as the 4th arg to clear it.
set_status() {
  local id="${1}" status="${2}" platform="${3:-}" language="${4-__keep__}"
  local today
  today=$(date '+%Y-%m-%d')
  local start_date="${ST_START[${id}]:-}" completed_date=""
  [[ -z "${start_date}" ]] && start_date="${today}"
  [[ "${status}" == "completed" ]] && completed_date="${today}"
  local lang
  if [[ "${language}" == "__keep__" ]]; then lang="${ST_LANG[${id}]:-}"; else lang="${language}"; fi

  ST_STATUS["${id}"]="${status}"
  ST_PLATFORM["${id}"]="${platform}"
  ST_START["${id}"]="${start_date}"
  ST_DONE["${id}"]="${completed_date}"
  ST_LANG["${id}"]="${lang}"

  # Rewrite the file once from the cache, preserving the canonical study order.
  local pid
  for p in "${PROBLEMS[@]}"; do
    pid="${p%%|*}"
    printf '%s|%s|%s|%s|%s|%s\n' "${pid}" "${ST_STATUS[${pid}]:-not_started}" \
      "${ST_PLATFORM[${pid}]:-}" "${ST_START[${pid}]:-${today}}" \
      "${ST_DONE[${pid}]:-}" "${ST_LANG[${pid}]:-}"
  done > "${PROGRESS_FILE}"
}

count_by_status() {
  local want="${1}" id n=0
  for id in "${!ST_STATUS[@]}"; do
    [[ "${ST_STATUS[${id}]}" == "${want}" ]] && (( n++ ))
  done
  printf '%s' "${n}"
}

# ─── Progress Bar ─────────────────────────────────────────────────────────────
progress_bar() {
  local done="${1}" total="${2}" width="${3:-20}"
  (( total == 0 )) && total=1
  local filled=$(( done * width / total ))
  (( filled > width )) && filled="${width}"
  local fbar ebar
  printf -v fbar '%*s' "${filled}" ''
  printf -v ebar '%*s' "$(( width - filled ))" ''
  printf '%s%s' "${fbar// /█}" "${ebar// /░}"
}

# ─── Path Management ─────────────────────────────────────────────────────────
snake_name() {
  local s="${1,,}"            # lowercase (bash 4+)
  s="${s//[^a-z0-9]/_}"       # non-alphanumeric → underscore
  while [[ "${s}" == *__* ]]; do s="${s//__/_}"; done  # collapse runs
  s="${s#_}"; s="${s%_}"      # trim leading/trailing underscore
  printf '%s' "${s}"
}

get_problem_dir() {
  local p="${1}"
  local g diff gdir ddir
  g=$(p_group "${p}")
  diff=$(p_diff "${p}")
  gdir="${GROUP_DIRS[$g]}"
  ddir="${diff,,}"
  echo "${BS_DIR}/${gdir}/${ddir}"
}

get_problem_file() {
  local p="${1}"
  local id nm dir
  id=$(p_id "${p}")
  nm=$(snake_name "$(p_name "${p}")")
  dir=$(get_problem_dir "${p}")
  echo "${dir}/p${id}_${nm}.rs"
}

# ─── Module Management ────────────────────────────────────────────────────────
add_mod_decl() {
  # add_mod_decl <mod_file> <module_name>
  local mod_file="${1}" mod_name="${2}"
  [[ ! -f "${mod_file}" ]] && touch "${mod_file}"
  if ! grep -q "pub mod ${mod_name};" "${mod_file}" 2>/dev/null; then
    echo "pub mod ${mod_name};" >> "${mod_file}"
  fi
}

ensure_module_chain() {
  local p="${1}"
  local g diff gdir ddir
  g=$(p_group "${p}")
  diff=$(p_diff "${p}")
  gdir="${GROUP_DIRS[$g]}"
  ddir="${diff,,}"

  mkdir -p "${BS_DIR}/${gdir}/${ddir}"

  # main.rs → binary_search
  if ! grep -q "pub mod binary_search;" "${MAIN_RS}" 2>/dev/null; then
    local old_content
    old_content=$(cat "${MAIN_RS}")
    {
      echo "#![allow(dead_code, unused_variables, unused_imports)]"
      echo ""
      echo "pub mod binary_search;"
      echo ""
      printf '%s\n' "${old_content}"
    } > "${MAIN_RS}"
  fi

  add_mod_decl "${BS_DIR}/mod.rs"           "${gdir}"
  add_mod_decl "${BS_DIR}/${gdir}/mod.rs"   "${ddir}"
}

register_problem_mod() {
  local p="${1}"
  local g diff gdir ddir id nm
  g=$(p_group "${p}")
  diff=$(p_diff "${p}")
  gdir="${GROUP_DIRS[$g]}"
  ddir="${diff,,}"
  id=$(p_id "${p}")
  nm=$(snake_name "$(p_name "${p}")")
  local mod_name="p${id}_${nm}"
  add_mod_decl "${BS_DIR}/${gdir}/${ddir}/mod.rs" "${mod_name}"
}

# ─── Rust Template Generator ─────────────────────────────────────────────────
create_rust_template() {
  local p="${1}" platform="${2:-LC}"
  unpack_problem "${p}"
  local id="${P_ID}" name="${P_NAME}" diff="${P_DIFF}" g="${P_GROUP}"
  local lc="${P_LC}" gfg="${P_GFG}" cn="${P_CN}" fn_sig="${P_SIG}" idea="${P_IDEA}"
  local gname="${GROUP_NAMES[$g]}" primary_url

  case "${platform}" in
    GFG) primary_url="${gfg}" ;;
    CN)  primary_url="${cn}"  ;;
    ALL) primary_url="${lc:-${gfg:-${cn}}}" ;;
    *)   primary_url="${lc}"  ;;
  esac
  [[ -z "${primary_url}" ]] && primary_url="${lc:-${gfg:-${cn:-N/A}}}"

  local filepath
  filepath=$(get_problem_file "${p}")

  {
    echo "//! # Problem ${id}: ${name}"
    echo "//!"
    echo "//! **Difficulty:** ${diff}"
    echo "//! **Group:**      ${gname}"
    echo "//! **Platform:**   ${platform}"
    echo "//!"
    echo "//! ## Problem Statement"
    local stmt="${PROBLEM_STATEMENTS[$id]:-}"
    if [[ -n "${stmt}" ]]; then
      # Each \n in the stored string becomes a new //! line
      while IFS= read -r line; do
        echo "//! ${line}"
      done <<< "$(printf '%b' "${stmt}")"
    else
      echo "//! *(see problem link above)*"
    fi
    echo "//!"
    echo "//! ## Problem Link"
    echo "//! <${primary_url}>"
    echo "//!"
    echo "//! ## All Links"
    [[ -n "${lc}"  ]] && echo "//! - LeetCode:       ${lc}"
    [[ -n "${gfg}" ]] && echo "//! - GeeksForGeeks:  ${gfg}"
    [[ -n "${cn}"  ]] && echo "//! - Coding Ninjas:  ${cn}"
    echo "//!"
    echo "//! ## Core Idea"
    echo "//! ${idea}"
    echo "//!"
    echo "//! ## Your Approach"
    echo "//! <!-- Write your approach / key observations here before coding -->"
    echo "//!"
    echo "//! ## Complexity"
    echo "//! - **Time:**  O(?)"
    echo "//! - **Space:** O(?)"
    echo ""
    echo "#![allow(dead_code)]"
    echo ""
    echo "pub struct Solution;"
    echo ""
    echo "impl Solution {"
    echo "    pub ${fn_sig} {"
    echo "        todo!()"
    echo "    }"
    echo "}"
    echo ""
    echo "// ─── Tests ────────────────────────────────────────────────────────────────────"
    echo ""
    echo "#[cfg(test)]"
    echo "mod tests {"
    echo "    use super::*;"
    echo ""
    echo "    #[test]"
    echo "    fn test_example_1() {"
    echo "        // TODO: Replace todo!() with a real assertion once implemented:"
    echo "        // assert_eq!(Solution::your_method(input), expected);"
    echo "        todo!()"
    echo "    }"
    echo "}"
  } > "${filepath}"

  echo "${filepath}"
}

# ─── Non-Rust Template Generator ─────────────────────────────────────────────
# Rust solutions live in src/ and are driven by cargo; every other language is a
# standalone stub under solutions/<platform>/ holding the problem context, since
# those judges (e.g. GFG, which has no Rust) are where you'll actually submit.

# Folder that holds a problem's non-Rust solution for the chosen platform.
get_lang_file() {
  local p="${1}" platform="${2}" language="${3}"
  unpack_problem "${p}"
  local ext="${LANG_EXT[$language]:-txt}" pdir
  if [[ "${platform}" == "ALL" ]]; then
    if   [[ -n "${P_LC}"  ]]; then pdir="${PLATFORM_DIR[LC]}"
    elif [[ -n "${P_GFG}" ]]; then pdir="${PLATFORM_DIR[GFG]}"
    else                           pdir="${PLATFORM_DIR[CN]}"; fi
  else
    pdir="${PLATFORM_DIR[$platform]:-misc}"
  fi
  printf '%s/%s/p%s_%s.%s' "${SOLUTIONS_DIR}" "${pdir}" "${P_ID}" "$(snake_name "${P_NAME}")" "${ext}"
}

# A minimal, language-appropriate skeleton emitted below the header comment.
lang_skeleton() {
  case "${1}" in
    "C++")              printf 'class Solution {\npublic:\n    // TODO: implement\n};\n' ;;
    "Java"|"Kotlin"|"Swift") printf 'class Solution {\n    // TODO: implement\n}\n' ;;
    "C#")               printf 'public class Solution {\n    // TODO: implement\n}\n' ;;
    "Python3"|"Python") printf 'class Solution:\n    # TODO: implement\n    pass\n' ;;
    "Go")               printf 'package main\n\n// TODO: implement\n' ;;
    "C")                printf '/* TODO: implement */\n' ;;
    "Ruby")             printf '# TODO: implement\n' ;;
    "PHP")              printf '<?php\nclass Solution {\n    // TODO: implement\n}\n' ;;
    *)                  printf '// TODO: implement\n' ;;  # JavaScript / TypeScript / fallback
  esac
}

create_lang_template() {
  local p="${1}" platform="${2}" language="${3}"
  unpack_problem "${p}"
  local gname="${GROUP_NAMES[$P_GROUP]}" primary_url
  case "${platform}" in
    GFG) primary_url="${P_GFG}" ;;
    CN)  primary_url="${P_CN}"  ;;
    ALL) primary_url="${P_LC:-${P_GFG:-${P_CN}}}" ;;
    *)   primary_url="${P_LC}"  ;;
  esac
  [[ -z "${primary_url}" ]] && primary_url="${P_LC:-${P_GFG:-${P_CN:-N/A}}}"

  local filepath
  filepath=$(get_lang_file "${p}" "${platform}" "${language}")
  mkdir -p "$(dirname "${filepath}")"

  local c="//"
  [[ -n "${LANG_HASH_COMMENT[$language]:-}" ]] && c="#"

  {
    printf '%s Problem %s: %s\n' "${c}" "${P_ID}" "${P_NAME}"
    printf '%s\n' "${c}"
    printf '%s Difficulty: %s\n' "${c}" "${P_DIFF}"
    printf '%s Group:      %s\n' "${c}" "${gname}"
    printf '%s Platform:   %s\n' "${c}" "${platform}"
    printf '%s Language:   %s\n' "${c}" "${language}"
    printf '%s\n' "${c}"
    printf '%s Problem Statement\n' "${c}"
    local stmt="${PROBLEM_STATEMENTS[$P_ID]:-}"
    if [[ -n "${stmt}" ]]; then
      while IFS= read -r line; do printf '%s   %s\n' "${c}" "${line}"; done <<< "$(printf '%b' "${stmt}")"
    else
      printf '%s   (see problem link below)\n' "${c}"
    fi
    printf '%s\n' "${c}"
    printf '%s Problem Link\n' "${c}"
    printf '%s   %s\n' "${c}" "${primary_url}"
    printf '%s\n' "${c}"
    printf '%s All Links\n' "${c}"
    [[ -n "${P_LC}"  ]] && printf '%s   LeetCode:      %s\n' "${c}" "${P_LC}"
    [[ -n "${P_GFG}" ]] && printf '%s   GeeksForGeeks: %s\n' "${c}" "${P_GFG}"
    [[ -n "${P_CN}"  ]] && printf '%s   Coding Ninjas: %s\n' "${c}" "${P_CN}"
    printf '%s\n' "${c}"
    printf '%s Core Idea\n' "${c}"
    printf '%s   %s\n' "${c}" "${P_IDEA}"
    printf '%s\n' "${c}"
    printf '%s Reference signature (Rust): %s\n' "${c}" "${P_SIG}"
    printf '%s Complexity — Time: O(?)  Space: O(?)\n' "${c}"
    printf '\n'
    lang_skeleton "${language}"
  } > "${filepath}"

  printf '%s' "${filepath}"
}

# ─── Workspace Initialisation ─────────────────────────────────────────────────
setup_workspace() {
  printf '%b\n' "${BOLD}${CYAN}Setting up DSA workspace structure...${NC}"

  # Directory tree
  local g gdir
  for g in 1 2 3; do
    gdir="${GROUP_DIRS[$g]}"
    mkdir -p "${BS_DIR}/${gdir}/easy"
    mkdir -p "${BS_DIR}/${gdir}/medium"
    mkdir -p "${BS_DIR}/${gdir}/hard"
  done

  # src/binary_search/mod.rs
  if [[ ! -f "${BS_DIR}/mod.rs" ]]; then
    {
      echo "//! Binary Search — Striver's A2Z DSA Sheet, Step 4"
      echo "//!"
      echo "//! 32 problems across 3 groups:"
      echo "//!   Group 1 · Binary Search on 1D Arrays        (13 problems)"
      echo "//!   Group 2 · Binary Search on Answer Space     (14 problems)"
      echo "//!   Group 3 · Binary Search on 2D Arrays        ( 5 problems)"
      echo ""
      echo "pub mod group_1_1d_arrays;"
      echo "pub mod group_2_answer_space;"
      echo "pub mod group_3_2d_arrays;"
    } > "${BS_DIR}/mod.rs"
  fi

  # Per-group mod.rs
  for g in 1 2 3; do
    gdir="${GROUP_DIRS[$g]}"
    if [[ ! -f "${BS_DIR}/${gdir}/mod.rs" ]]; then
      {
        echo "//! ${GROUP_NAMES[$g]}"
        echo ""
        echo "pub mod easy;"
        echo "pub mod medium;"
        echo "pub mod hard;"
      } > "${BS_DIR}/${gdir}/mod.rs"
    fi
    # Empty difficulty mod.rs files (valid Rust — just no children yet)
    for d in easy medium hard; do
      [[ ! -f "${BS_DIR}/${gdir}/${d}/mod.rs" ]] && touch "${BS_DIR}/${gdir}/${d}/mod.rs"
    done
  done

  # src/main.rs
  if ! grep -q "pub mod binary_search;" "${MAIN_RS}" 2>/dev/null; then
    local old
    old=$(cat "${MAIN_RS}")
    {
      echo "#![allow(dead_code, unused_variables, unused_imports)]"
      echo ""
      echo "pub mod binary_search;"
      echo ""
      printf '%s\n' "${old}"
    } > "${MAIN_RS}"
  fi

  printf '%b\n' "${GREEN}Done!${NC}"
}

# ─── Display Helpers ──────────────────────────────────────────────────────────
clear_screen() { printf '\033[2J\033[H'; }

print_header() {
  printf '%b\n' "${BOLD}${CYAN}"
  echo "╔══════════════════════════════════════════════════════════════╗"
  echo "║       DSA Practice Tool  ·  Binary Search Edition           ║"
  echo "║       Striver's A2Z Sheet  ·  Step 4  ·  32 Problems        ║"
  echo "╚══════════════════════════════════════════════════════════════╝"
  printf '%b\n' "${NC}"
}

print_mini_progress() {
  local total=${#PROBLEMS[@]}
  local done in_prog
  done=$(count_by_status "completed")
  in_prog=$(count_by_status "in_progress")
  local pct=$(( done * 100 / total ))
  local bar
  bar=$(progress_bar "${done}" "${total}" 28)
  printf '  Progress: %b%s%b done · %b%s%b in-progress · %b%s%b untouched  /%s total\n' \
    "${GREEN}" "${done}" "${NC}" \
    "${YELLOW}" "${in_prog}" "${NC}" \
    "${DIM}" "$(( total - done - in_prog ))" "${NC}" \
    "${total}"
  printf '  %b%s%b  %b%d%%%b\n\n' "${CYAN}" "${bar}" "${NC}" "${BOLD}" "${pct}" "${NC}"
}

print_problem_row() {
  unpack_problem "${1}"
  local icon diff_str
  icon=$(status_icon "${ST_STATUS[${P_ID}]:-not_started}")
  case "${P_DIFF}" in
    Easy)   diff_str="$(printf '%b' "${GREEN}Easy  ${NC}")" ;;
    Medium) diff_str="$(printf '%b' "${YELLOW}Medium${NC}")" ;;
    Hard)   diff_str="$(printf '%b' "${RED}Hard  ${NC}")" ;;
  esac
  printf '  %b %s  [%s]  %s\n' "${icon}" "${P_ID}" "${diff_str}" "${P_NAME}"
}

print_problem_detail() {
  unpack_problem "${1}"
  local status platform language gname meta
  status="${ST_STATUS[${P_ID}]:-not_started}"; platform="${ST_PLATFORM[${P_ID}]:-}"
  language="${ST_LANG[${P_ID}]:-}"
  gname="${GROUP_NAMES[$P_GROUP]}"
  # " (LC · Rust)" — only the parts that are set
  meta="${platform}"
  [[ -n "${language}" ]] && meta="${meta:+${meta} · }${language}"

  echo ""
  printf '%b── Problem %s: %s ──%b\n' "${BOLD}${BLUE}" "${P_ID}" "${P_NAME}" "${NC}"
  printf '   Difficulty : %b\n'   "$(diff_color "${P_DIFF}")"
  printf '   Status     : %b %s%s\n' "$(status_icon "${status}")" "${status}" \
    "${meta:+ (${meta})}"
  printf '   Group      : %b%s%b\n' "${CYAN}" "${gname}" "${NC}"
  echo ""
  printf '   %bSignature:%b  %b%s%b\n' "${BOLD}" "${NC}" "${CYAN}" "${P_SIG}" "${NC}"
  printf '   %bCore Idea:%b  %s\n' "${BOLD}" "${NC}" "${P_IDEA}"
  echo ""
  [[ -n "${P_LC}"  ]] && printf '   %bLC :%b  %b%s%b\n' "${BOLD}" "${NC}" "${DIM}" "${P_LC}"  "${NC}"
  [[ -n "${P_GFG}" ]] && printf '   %bGFG:%b  %b%s%b\n' "${BOLD}" "${NC}" "${DIM}" "${P_GFG}" "${NC}"
  [[ -n "${P_CN}"  ]] && printf '   %bCN :%b  %b%s%b\n' "${BOLD}" "${NC}" "${DIM}" "${P_CN}"  "${NC}"
  echo ""
}

# ─── Dashboard ────────────────────────────────────────────────────────────────
print_dashboard() {
  clear_screen
  print_header

  local total=${#PROBLEMS[@]}
  local done in_prog not_started
  done=$(count_by_status "completed")
  in_prog=$(count_by_status "in_progress")
  not_started=$(( total - done - in_prog ))

  printf '%b  Overall Progress%b\n' "${BOLD}" "${NC}"
  printf '  %-14s %b%s%b  %s/%s\n' "Completed"   "${GREEN}"  "$(progress_bar "${done}"        "${total}" 26)" "${NC}" "${done}"        "${total}"
  printf '  %-14s %b%s%b  %s/%s\n' "In Progress" "${YELLOW}" "$(progress_bar "${in_prog}"     "${total}" 26)" "${NC}" "${in_prog}"     "${total}"
  printf '  %-14s %b%s%b  %s/%s\n' "Not Started" "${DIM}"    "$(progress_bar "${not_started}" "${total}" 26)" "${NC}" "${not_started}" "${total}"
  echo ""

  printf '%b  By Difficulty%b\n' "${BOLD}" "${NC}"
  for diff in Easy Medium Hard; do
    local d_total=0 d_done=0
    for p in "${PROBLEMS[@]}"; do
      unpack_problem "${p}"
      [[ "${P_DIFF}" != "${diff}" ]] && continue
      (( d_total++ )) || true
      [[ "${ST_STATUS[${P_ID}]:-not_started}" == "completed" ]] && (( d_done++ )) || true
    done
    local color
    case "${diff}" in Easy) color="${GREEN}";; Medium) color="${YELLOW}";; Hard) color="${RED}";; esac
    printf '  %b%-8s%b  %s  %s/%s\n' "${color}${BOLD}" "${diff}" "${NC}" \
      "$(progress_bar "${d_done}" "${d_total}" 22)" "${d_done}" "${d_total}"
  done
  echo ""

  printf '%b  By Group%b\n' "${BOLD}" "${NC}"
  for g in 1 2 3; do
    local g_total=0 g_done=0
    for p in "${PROBLEMS[@]}"; do
      unpack_problem "${p}"
      [[ "${P_GROUP}" != "${g}" ]] && continue
      (( g_total++ )) || true
      [[ "${ST_STATUS[${P_ID}]:-not_started}" == "completed" ]] && (( g_done++ )) || true
    done
    printf '  %b%-42s%b  %s  %s/%s\n' "${CYAN}" "${GROUP_NAMES[$g]}" "${NC}" \
      "$(progress_bar "${g_done}" "${g_total}" 16)" "${g_done}" "${g_total}"
  done
  echo ""

  # Recently completed — read dates/names straight from the in-memory cache.
  local recent
  recent=$(grep "|completed|" "${PROGRESS_FILE}" | grep -v "||$" | tail -5 | cut -d'|' -f1 || true)
  if [[ -n "${recent}" ]]; then
    printf '%b  Recently Completed%b\n' "${BOLD}" "${NC}"
    while IFS= read -r rid; do
      local rp="${PROB_BY_ID[${rid}]:-}"
      [[ -z "${rp}" ]] && continue
      unpack_problem "${rp}"
      printf '  %b✓%b  %s  %b%s%b\n' "${GREEN}" "${NC}" "${P_NAME}" "${DIM}" "${ST_DONE[${rid}]:-}" "${NC}"
    done <<< "${recent}"
    echo ""
  fi

  # Study order reminder
  printf '%b  Recommended Study Order%b\n' "${BOLD}" "${NC}"
  printf '  %bProblems 1-7%b    Bounds & occurrences — master the two templates\n' "${GREEN}" "${NC}"
  printf '  %bProblems 8-13%b   Rotated arrays, peak, single element\n' "${GREEN}" "${NC}"
  printf '  %bProblems 14-16%b  Intro to search-space BS (sqrt, Nth root, Koko)\n' "${YELLOW}" "${NC}"
  printf '  %bProblems 17-20%b  Standard answer-space medium problems\n' "${YELLOW}" "${NC}"
  printf '  %bProblems 21-24%b  Aggressive Cows / Book Allocation family — interview staples\n' "${YELLOW}" "${NC}"
  printf '  %bProblems 25-27%b  Floating-point BS and two-array hard problems\n' "${RED}" "${NC}"
  printf '  %bProblems 28-30%b  2D matrix basics\n' "${YELLOW}" "${NC}"
  printf '  %bProblems 31-32%b  2D hard problems\n' "${RED}" "${NC}"
  echo ""
}

# ─── Platform Selector ────────────────────────────────────────────────────────
# All UI output goes to stderr so the caller can capture only the result via $()
select_platform() {
  local p="${1}"
  local lc gfg cn
  lc=$(p_lc "${p}"); gfg=$(p_gfg "${p}"); cn=$(p_cn "${p}")

  echo "" >&2
  printf '%b  Select platform for this problem:%b\n' "${BOLD}" "${NC}" >&2

  # NOTE: pre-increment (( ++idx )) — post-increment returns the *old* value as
  # exit status, which is 0 (false) on the first option and silently drops the
  # "&& printf" for the LeetCode line.
  local idx=0
  [[ -n "${lc}"  ]] && (( ++idx )) && printf '  [%d]  LeetCode\n'      "${idx}" >&2
  [[ -n "${gfg}" ]] && (( ++idx )) && printf '  [%d]  GeeksForGeeks\n' "${idx}" >&2
  [[ -n "${cn}"  ]] && (( ++idx )) && printf '  [%d]  Coding Ninjas\n'  "${idx}" >&2
  printf '  [%d]  All links (use first available)\n' $(( idx + 1 )) >&2
  echo "" >&2

  local choice
  read -rp "  Choice [1-$(( idx + 1 ))]: " choice

  # Map choice number back to platform key
  local cur=0 result="LC"
  [[ -n "${lc}"  ]] && (( ++cur )) && [[ "${choice}" == "${cur}" ]] && result="LC"
  [[ -n "${gfg}" ]] && (( ++cur )) && [[ "${choice}" == "${cur}" ]] && result="GFG"
  [[ -n "${cn}"  ]] && (( ++cur )) && [[ "${choice}" == "${cur}" ]] && result="CN"
  [[ "${choice}" == "$(( cur + 1 ))" ]] && result="ALL"

  # Only the key is written to stdout — captured cleanly by $()
  echo "${result}"
}

# ─── Language Selector ────────────────────────────────────────────────────────
# Offers only the languages the chosen platform actually accepts (GFG omits Rust).
# For "ALL", offers the union across every linked platform. UI → stderr, key → stdout.
select_language() {
  local platform="${1}" langs
  if [[ "${platform}" == "ALL" ]]; then
    local seen=" " key l merged=""
    for key in LC GFG CN; do
      for l in ${PLATFORM_LANGS[$key]}; do
        [[ "${seen}" == *" ${l} "* ]] && continue
        seen+="${l} "; merged+="${l} "
      done
    done
    langs="${merged}"
  else
    langs="${PLATFORM_LANGS[$platform]:-Rust}"
  fi

  local -a arr=(${langs})
  echo "" >&2
  printf '%b  Select language (supported by this platform):%b\n' "${BOLD}" "${NC}" >&2
  local i
  for i in "${!arr[@]}"; do
    printf '  [%d]  %s\n' "$(( i + 1 ))" "${arr[$i]}" >&2
  done
  echo "" >&2

  local choice
  read -rp "  Choice [1-${#arr[@]}]: " choice
  if [[ "${choice}" =~ ^[0-9]+$ ]] && (( choice >= 1 && choice <= ${#arr[@]} )); then
    printf '%s' "${arr[$(( choice - 1 ))]}"
  else
    printf '%s' "${arr[0]}"   # default to the first (Rust where available)
  fi
}

# ─── Problem Action Menu ─────────────────────────────────────────────────────
problem_action_menu() {
  local p="${1}"
  local id
  id=$(p_id "${p}")

  while true; do
    clear_screen
    print_header
    print_problem_detail "${p}"

    # Which file represents this problem depends on the recorded language:
    # Rust (or untouched) → the cargo-tracked .rs; anything else → solutions/<platform>/.
    local lang_now platform_now filepath
    lang_now="${ST_LANG[${id}]:-}"
    platform_now="${ST_PLATFORM[${id}]:-}"
    if [[ -z "${lang_now}" || "${lang_now}" == "Rust" ]]; then
      filepath=$(get_problem_file "${p}")
    else
      filepath=$(get_lang_file "${p}" "${platform_now:-LC}" "${lang_now}")
    fi
    local file_label
    if [[ -f "${filepath}" ]]; then
      file_label="$(printf '%b' "${GREEN}Exists${NC}") — ${DIM}${filepath#"${SCRIPT_DIR}/"}${NC}"
    else
      file_label="$(printf '%b' "${DIM}Not created yet${NC}")"
    fi
    printf '  Solution file: %b\n\n' "${file_label}"

    # ── Auto-detect: Rust solution implemented but not yet marked completed ──
    local current_status
    current_status=$(get_status "${id}")
    if [[ -z "${lang_now}" || "${lang_now}" == "Rust" ]] \
       && [[ -f "${filepath}" ]] \
       && ! grep -q 'todo!()' "${filepath}" 2>/dev/null \
       && [[ "${current_status}" != "completed" ]]; then
      printf '  %b💡 todo!() removed — looks like you implemented this!%b\n' "${GREEN}${BOLD}" "${NC}"
      printf '  %b   Run tests to verify, then mark completed.%b\n\n' "${DIM}" "${NC}"
    fi

    printf '%b  Actions%b\n' "${BOLD}" "${NC}"
    echo "  [1]  Create solution template  (prompts for platform + language)"
    echo "  [2]  Mark → In Progress"
    echo "  [3]  Mark → Completed"
    echo "  [4]  Mark → Not Started  (reset)"
    echo "  [5]  Run tests  (Rust only — cargo test p<id>)"
    echo "  [6]  Show file path"
    echo "  [0]  Back"
    echo ""
    local choice
    read -rp "  Choice: " choice

    case "${choice}" in
      0) return ;;
      1)
        local platform language
        platform=$(select_platform "${p}")
        language=$(select_language "${platform}")

        # Target path depends on the chosen language.
        local target
        if [[ "${language}" == "Rust" ]]; then
          target=$(get_problem_file "${p}")
        else
          target=$(get_lang_file "${p}" "${platform}" "${language}")
        fi
        if [[ -f "${target}" ]]; then
          printf '\n  %bFile already exists.%b Overwrite? [y/N]: ' "${YELLOW}" "${NC}"
          local overwrite; read -r overwrite
          if [[ ! "${overwrite}" =~ ^[Yy]$ ]]; then
            printf '\n  %bSkipped.%b\n' "${DIM}" "${NC}"
            read -rp "  Press Enter..." _
            continue
          fi
        fi

        local created
        if [[ "${language}" == "Rust" ]]; then
          ensure_module_chain "${p}"
          created=$(create_rust_template "${p}" "${platform}")
          register_problem_mod "${p}"
        else
          created=$(create_lang_template "${p}" "${platform}" "${language}")
        fi
        set_status "${id}" "in_progress" "${platform}" "${language}"
        printf '\n  %b✓ Created %s template:%b  %s\n' "${GREEN}" "${language}" "${NC}" "${created#"${SCRIPT_DIR}/"}"
        if [[ "${language}" == "Rust" ]]; then
          printf '  %bTip:%b  cargo test %s -- --show-output\n' "${DIM}" "${NC}" "p${id}"
          printf '  %bTip:%b  cargo build  (to verify it compiles)\n' "${DIM}" "${NC}"
        else
          printf '  %bNote:%b  %s solutions live under solutions/ and are not built by cargo.\n' "${DIM}" "${NC}" "${language}"
        fi
        read -rp "  Press Enter..." _
        ;;
      2)
        set_status "${id}" "in_progress" "$(get_platform "${id}")"
        printf '\n  %b◎ Marked as In Progress%b\n' "${YELLOW}" "${NC}"
        read -rp "  Press Enter..." _
        ;;
      3)
        set_status "${id}" "completed" "$(get_platform "${id}")"
        printf '\n  %b✓ Marked as Completed! Well done!%b\n' "${GREEN}" "${NC}"
        read -rp "  Press Enter..." _
        ;;
      4)
        set_status "${id}" "not_started" "" ""
        printf '\n  %bReset to Not Started%b\n' "${DIM}" "${NC}"
        read -rp "  Press Enter..." _
        ;;
      5)
        if [[ -n "${lang_now}" && "${lang_now}" != "Rust" ]]; then
          printf '\n  %bAutomated tests run only for Rust solutions (cargo).%b\n' "${YELLOW}" "${NC}"
          printf '  %bYour %s solution lives at %s — run it on the platform.%b\n' \
            "${DIM}" "${lang_now}" "${filepath#"${SCRIPT_DIR}/"}" "${NC}"
          read -rp "  Press Enter..." _
        else
          # Run tests for this specific problem module
          local mod_name
          mod_name="p${id}_$(snake_name "$(p_name "${p}")")"
          printf '\n  %bRunning: cargo test %s -- --show-output%b\n\n' "${CYAN}" "${mod_name}" "${NC}"
          if cargo test "${mod_name}" -- --show-output 2>&1; then
            printf '\n  %bAll tests passed!%b  Mark as completed? [Y/n]: ' "${GREEN}${BOLD}" "${NC}"
            local yn; read -r yn
            if [[ ! "${yn}" =~ ^[Nn]$ ]]; then
              set_status "${id}" "completed" "$(get_platform "${id}")"
              printf '  %b✓ Marked as Completed!%b\n' "${GREEN}" "${NC}"
            fi
          else
            printf '  %bTests failed — keep going!%b\n' "${RED}" "${NC}"
          fi
          read -rp "  Press Enter..." _
        fi
        ;;
      6)
        printf '\n  %b%s%b\n' "${CYAN}" "${filepath}" "${NC}"
        read -rp "  Press Enter..." _
        ;;
    esac
  done
}

# ─── Browse by Group ──────────────────────────────────────────────────────────
browse_by_group() {
  while true; do
    clear_screen
    print_header
    printf '%b  Browse by Group%b\n\n' "${BOLD}" "${NC}"

    for g in 1 2 3; do
      local g_total=0 g_done=0
      for p in "${PROBLEMS[@]}"; do
        unpack_problem "${p}"
        [[ "${P_GROUP}" != "${g}" ]] && continue
        (( g_total++ )) || true
        [[ "${ST_STATUS[${P_ID}]:-not_started}" == "completed" ]] && (( g_done++ )) || true
      done
      printf '  [%d]  Group %d · %b%s%b  (%s/%s)\n' \
        "${g}" "${g}" "${CYAN}" "${GROUP_NAMES[$g]}" "${NC}" "${g_done}" "${g_total}"
    done
    echo "  [0]  Back"
    echo ""
    local choice
    read -rp "  Choice: " choice
    [[ "${choice}" == "0" ]] && return
    [[ "${choice}" =~ ^[123]$ ]] || continue

    # Show problems in this group, ordered Easy → Medium → Hard
    while true; do
      clear_screen
      print_header
      printf '%b  Group %s · %s%b\n\n' "${BOLD}${CYAN}" "${choice}" "${GROUP_NAMES[$choice]}" "${NC}"

      local idx=0
      declare -a gprobs=()
      for diff_filter in Easy Medium Hard; do
        local printed_header=0
        for p in "${PROBLEMS[@]}"; do
          unpack_problem "${p}"
          [[ "${P_GROUP}" != "${choice}" ]] && continue
          [[ "${P_DIFF}" != "${diff_filter}" ]] && continue
          if (( printed_header == 0 )); then
            printed_header=1
            printf '\n  %b── %s ──%b\n' "${BOLD}" "${diff_filter}" "${NC}"
          fi
          gprobs+=("${p}")
          printf '  [%2d]  ' "$((++idx))"
          print_problem_row "${p}"
        done
      done

      echo ""
      echo "  [ 0]  Back"
      echo ""
      local sel
      read -rp "  Select problem [0-${idx}]: " sel
      [[ "${sel}" == "0" ]] && break
      [[ "${sel}" =~ ^[0-9]+$ ]] || continue
      (( sel >= 1 && sel <= idx )) || continue
      problem_action_menu "${gprobs[$((sel-1))]}"
    done
  done
}

# ─── Browse by Difficulty ────────────────────────────────────────────────────
browse_by_difficulty() {
  while true; do
    clear_screen
    print_header
    printf '%b  Browse by Difficulty%b\n\n' "${BOLD}" "${NC}"
    echo "  [1]  Easy"
    echo "  [2]  Medium"
    echo "  [3]  Hard"
    echo "  [0]  Back"
    echo ""
    local choice
    read -rp "  Choice: " choice
    [[ "${choice}" == "0" ]] && return

    local target_diff
    case "${choice}" in
      1) target_diff="Easy" ;;
      2) target_diff="Medium" ;;
      3) target_diff="Hard" ;;
      *) continue ;;
    esac

    while true; do
      clear_screen
      print_header
      printf '  %b Problems\n\n' "$(diff_color "${target_diff}")"

      local idx=0
      declare -a dprobs=()
      local current_group=0
      for p in "${PROBLEMS[@]}"; do
        unpack_problem "${p}"
        [[ "${P_DIFF}" != "${target_diff}" ]] && continue
        if [[ "${P_GROUP}" != "${current_group}" ]]; then
          current_group="${P_GROUP}"
          printf '  %b── %s ──%b\n' "${DIM}" "${GROUP_NAMES[$P_GROUP]}" "${NC}"
        fi
        dprobs+=("${p}")
        printf '  [%2d]  ' "$((++idx))"
        print_problem_row "${p}"
      done
      echo ""
      echo "  [ 0]  Back"
      echo ""
      local sel
      read -rp "  Select problem [0-${idx}]: " sel
      [[ "${sel}" == "0" ]] && break
      [[ "${sel}" =~ ^[0-9]+$ ]] || continue
      (( sel >= 1 && sel <= idx )) || continue
      problem_action_menu "${dprobs[$((sel-1))]}"
    done
  done
}

# ─── Show All Problems ────────────────────────────────────────────────────────
show_all_problems() {
  clear_screen
  print_header
  printf '%b  All 32 Problems%b\n' "${BOLD}" "${NC}"

  local current_group=0
  local idx=0
  declare -a all_probs=()
  for p in "${PROBLEMS[@]}"; do
    unpack_problem "${p}"
    if [[ "${P_GROUP}" != "${current_group}" ]]; then
      current_group="${P_GROUP}"
      printf '\n  %b── %s ──%b\n' "${BOLD}${CYAN}" "${GROUP_NAMES[$P_GROUP]}" "${NC}"
    fi
    all_probs+=("${p}")
    printf '  [%2d]  ' "$((++idx))"
    print_problem_row "${p}"
  done

  echo ""
  echo "  [ 0]  Back to menu  |  [1-32] Open problem"
  echo ""
  local sel
  read -rp "  Choice: " sel
  [[ "${sel}" == "0" ]] && return
  [[ "${sel}" =~ ^[0-9]+$ ]] || return
  (( sel >= 1 && sel <= idx )) || return
  problem_action_menu "${all_probs[$((sel-1))]}"
}

# ─── Next Unsolved ────────────────────────────────────────────────────────────
next_unsolved() {
  # Follows the recommended study order (problems in PROBLEMS array order)
  for p in "${PROBLEMS[@]}"; do
    if [[ "${ST_STATUS[${p%%|*}]:-not_started}" != "completed" ]]; then
      printf '%s' "${p}"
      return
    fi
  done
}

# ─── Cheatsheet ───────────────────────────────────────────────────────────────
show_cheatsheet() {
  clear_screen
  print_header
  printf '%b  Binary Search Pattern Cheatsheet%b\n\n' "${BOLD}" "${NC}"

  local patterns=(
    "1. Exact Search (classic)|Find target X in sorted array|lo=0 hi=n-1; while lo<=hi; if arr[mid]==x return; else shrink"
    "2. Lower Bound|First index where arr[i] >= x|hi=mid when arr[mid]>=x; else lo=mid+1; return lo at end"
    "3. Upper Bound|First index where arr[i] > x|hi=mid when arr[mid]>x; else lo=mid+1; return lo at end"
    "4. Rotated Array|One half is always sorted|Check sorted half; if target in range go there; else go other side"
    "5. Answer Space — Minimise|BS on the answer value|can(mid) -> hi=mid; else lo=mid+1; return lo"
    "6. Answer Space — Maximise|Flip direction|can(mid) -> lo=mid; else hi=mid-1; use mid=lo+(hi-lo+1)/2"
    "7. 2D as 1D|Virtual index into matrix|index i -> (i/cols, i%cols); standard BS on range [0, m*n-1]"
    "8. Value-range on Matrix|BS on value not index|count_le(mid) per row; total > (m*n)/2 -> reduce hi"
  )

  for pat in "${patterns[@]}"; do
    local title desc tmpl
    IFS='|' read -r title desc tmpl <<< "${pat}"
    printf '  %b%s%b\n' "${BOLD}${BLUE}" "${title}" "${NC}"
    printf '  %bWhen:%b %s\n' "${DIM}" "${NC}" "${desc}"
    printf '  %bHow:%b  %b%s%b\n\n' "${DIM}" "${NC}" "${CYAN}" "${tmpl}" "${NC}"
  done

  read -rp "  Press Enter to go back..." _
}

# ─── Main Menu ────────────────────────────────────────────────────────────────
main_menu() {
  while true; do
    clear_screen
    print_header
    print_mini_progress

    printf '%b  Main Menu%b\n\n' "${BOLD}" "${NC}"
    echo "  [1]  Browse by Group        (Easy → Medium → Hard within each group)"
    echo "  [2]  Browse by Difficulty   (see all Easy / Medium / Hard across groups)"
    echo "  [3]  Start Next Unsolved    (recommended study order)"
    echo "  [4]  Show All Problems"
    echo "  [5]  Progress Dashboard"
    echo "  [6]  Pattern Cheatsheet"
    echo "  [0]  Exit"
    echo ""
    local choice
    read -rp "  Choice: " choice

    case "${choice}" in
      0)
        printf '\n  %bGoodbye! Keep grinding. 🚀%b\n\n' "${DIM}" "${NC}"
        exit 0
        ;;
      1) browse_by_group ;;
      2) browse_by_difficulty ;;
      3)
        local nxt
        nxt=$(next_unsolved)
        if [[ -z "${nxt}" ]]; then
          printf '\n  %b🎉 All 32 problems completed! Impressive!%b\n' "${GREEN}${BOLD}" "${NC}"
          read -rp "  Press Enter..." _
        else
          problem_action_menu "${nxt}"
        fi
        ;;
      4) show_all_problems ;;
      5) print_dashboard; read -rp "  Press Enter to go back..." _ ;;
      6) show_cheatsheet ;;
    esac
  done
}

# ─── Entry Point ──────────────────────────────────────────────────────────────
main() {
  # First-run workspace setup
  if [[ ! -d "${BS_DIR}" ]]; then
    clear_screen
    print_header
    setup_workspace
    sleep 1
  fi

  init_progress

  # VS Code tasks.json passes the chosen action as the first argument.
  # Running the script directly (no arg) always shows the main menu.
  local mode="${1:-}"
  case "${mode}" in
    group)      browse_by_group;      main_menu ;;
    difficulty) browse_by_difficulty; main_menu ;;
    all)        show_all_problems;    main_menu ;;
    dashboard)
      print_dashboard
      read -rp "  Press Enter to continue..." _
      main_menu
      ;;
    cheatsheet) show_cheatsheet;      main_menu ;;
    next)
      local nxt
      nxt=$(next_unsolved)
      if [[ -z "${nxt}" ]]; then
        clear_screen
        print_header
        printf '\n  %b🎉 All 32 problems completed! Impressive!%b\n' "${GREEN}${BOLD}" "${NC}"
        read -rp "  Press Enter..." _
      else
        problem_action_menu "${nxt}"
      fi
      main_menu
      ;;
    *) main_menu ;;
  esac
}

main "$@"

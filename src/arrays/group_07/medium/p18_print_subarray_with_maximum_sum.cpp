// Problem 18: Print Subarray with Maximum Sum
//
// Difficulty: Medium
// Group:      7
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Return the contiguous subarray (its elements) that has the largest sum.
//
//   Example 1:  nums = [-2,1,-3,4,-1,2,1,-5,4]  →  [4,-1,2,1]
//   Example 2:  nums = [1, 2, 3]                →  [1, 2, 3]
//
//   Constraints:
//     1 <= nums.length <= 10^4
//
// Problem Link
//   https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &arr) {
  int sum = 0;
  int longest_sum = arr[0];
  int start_indx_ans = 0;
  int end_indx_ans = arr.size() - 1;

  int curr_indx = 0;
  int start = 0;

  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];

    if (sum <= 0) {
      if (sum > longest_sum) {
        longest_sum = sum;
        end_indx_ans = i;
      }
      sum = 0;
      start_indx_ans = i + 1;
    } else {
      if (sum > longest_sum) {
        longest_sum = sum;
        end_indx_ans = i;
      }
    }
  }

  for (int i = start_indx_ans; i <= end_indx_ans; i++) {
    cout << arr[i] << " ";
  }

  return longest_sum;
}

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: run Kadane while tracking start/end; on reset remember
//   temp_start, commit on a new max.
//
// Core Idea
//   Kadane while tracking start/end; remember temp_start on reset, commit on a
//   new global max
//
// Reference signature (Rust): fn max_subarray_range(nums: Vec<i32>) -> Vec<i32>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/maximum-subarray/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

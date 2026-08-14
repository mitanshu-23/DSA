// Problem 21: Next Permutation
//
// Difficulty: Medium
// Group:      8
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Rearrange the numbers in-place into the next lexicographically greater
//   permutation. If none exists, wrap to the sorted (smallest) order.
//
//   Example 1:  nums = [1, 2, 3]  →  [1, 3, 2]
//   Example 2:  nums = [3, 2, 1]  →  [1, 2, 3]
//   Example 3:  nums = [1, 1, 5]  →  [1, 5, 1]
//
//   Constraints:
//     1 <= nums.length <= 100
//
// Problem Link
//   https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int starting = -1;
    int completed_till = nums.size() - 1;
    int i = nums.size() - 2;

    for (; i >= 0; i--) {
      if (nums[i] >= nums[i + 1]) {
        continue;
      } else {
        completed_till = i;
        break;
      }
    }

    if (i == -1) {
      sort(nums.begin(), nums.end());
      return;
    }

    int min_val = INT_MAX;
    auto min_it = nums.end();

    for (auto it = nums.begin() + i + 1; it != nums.end(); ++it) {
      if (*it > nums[completed_till] && *it < min_val) {
        min_val = *it;
        min_it = it;
      }
    }

    // int min_val = *min_it;
    int min_index = std::distance(nums.begin(), min_it);

    // cout << completed_till << " " << nums[completed_till] << endl;
    // cout << "Index: " << min_index;
    // swap(nums[completed_till], nums[min_index]);
    // sort(nums.begin() + completed_till + 1, nums.end());
    swap(nums[completed_till], nums[min_index]);
    sort(nums.begin() + completed_till + 1, nums.end());
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: find the rightmost dip, swap with the next greater to its
//   right, reverse the suffix.
//
// Core Idea
//   Find the rightmost dip i, swap with the next greater to its right, reverse
//   the suffix
//
// Reference signature (Rust): fn next_permutation(nums: &mut Vec<i32>)
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/next-permutation/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/next-permutation5226/1

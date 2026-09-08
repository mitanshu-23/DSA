// Problem 15: Sort Array of 0s, 1s, and 2s
//
// Difficulty: Medium
// Group:      5
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given an array of only 0s, 1s and 2s, sort it in-place in a single pass (no
//   counting sort).
//
//   Example 1:  nums = [2,0,2,1,1,0]  →  [0,0,1,1,2,2]
//   Example 2:  nums = [2,0,1]        →  [0,1,2]
//
//   Constraints:
//     1 <= nums.length <= 300
//     nums[i] is 0, 1, or 2.
//
// Problem Link
//   https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int curr = 0;
    int z_ptr = 0;
    int t_ptr = nums.size() - 1;

    while (z_ptr < nums.size()) {
      if (nums[z_ptr] == 0) {
        z_ptr++;
      } else {
        break;
      }
    }

    while (t_ptr >= 0) {
      if (nums[t_ptr] == 2) {
        t_ptr--;
      } else {
        break;
      }
    }

    curr = z_ptr + 1;

    while (t_ptr > curr) {
      if (nums[curr] == 0) {
        std::swap(nums[curr], nums[z_ptr]);
        z_ptr++;
      } else if (nums[curr] == 2) {
        std::swap(nums[curr], nums[t_ptr]);
        t_ptr--;
        curr--;
      }
      curr++;
    }
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: Dutch National Flag with three pointers lo, mid, hi.
//
// Core Idea
//   Dutch National Flag: lo/mid/hi partition into three regions in a single
//   pass
//
// Reference signature (Rust): fn sort_colors(nums: &mut Vec<i32>)
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/sort-colors/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

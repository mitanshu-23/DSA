// Problem 39: 2Sum Problem
//
// Difficulty: Hard
// Group:      5
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given an array nums and a target, return the indices of the two numbers
//   that add to target. Exactly one solution exists and you may not reuse an
//   element.
//
//   Example 1:  nums = [2,7,11,15], target = 9  →  [0, 1]
//   Example 2:  nums = [3, 2, 4], target = 6     →  [1, 2]
//
//   Constraints:
//     2 <= nums.length <= 10^4
//
// Problem Link
//   https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> exists;

    for (int i = 0; i < nums.size(); i++) {
      if (exists.contains(target - nums[i])) {
        return {nums[i], target - nums[i]};
      }
      // Enter in Map
      exists[nums[i]] = true;
    }
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: hashmap of value->index; for each x check whether (target - x)
//   was already seen.
//
// Core Idea
//   HashMap of complement->index for O(n) with original indices, or sort + two
//   pointers
//
// Reference signature (Rust): fn two_sum(nums: Vec<i32>, target: i32) ->
// Vec<i32> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/two-sum/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/key-pair5616/1

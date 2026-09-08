// Problem 30: 3Sum Problem
//
// Difficulty: Hard
// Group:      5
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Return all unique triplets [a, b, c] with a + b + c = 0. No duplicate
//   triplets.
//
//   Example 1:  nums = [-1,0,1,2,-1,-4]  →  [[-1,-1,2],[-1,0,1]]
//   Example 2:  nums = [0,0,0]           →  [[0,0,0]]
//
//   Constraints:
//     3 <= nums.length <= 3000
//
// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
// nums[k] == 0.
//
// Notice that the solution set must not contain duplicate triplets.

// Problem Link
//   https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      int target = -(nums[i]);
      for (int j = i + 1, k = nums.size() - 1; j < k;) {
        // cout << target << " " << nums[j] << " " << nums[k] << endl;
        if ((nums[j] + nums[k]) > target) {
          k--;
        } else if ((nums[j] + nums[k]) < target) {
          j++;
        } else {
          result.push_back({nums[j], nums[k], nums[i]});
          while ((j < k) && (nums[j + 1] == nums[j])) {
            j++;
          }
          j++;

          while ((j < k) && (nums[k - 1] == nums[k])) {
            k--;
          }
          k--;
        }
      }

      while (i < (nums.size() - 1) && nums[i + 1] == nums[i]) {
        i++;
      }
    }
    return result;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: sort, fix i, two-pointer on the rest; skip duplicate values at
//   every level.
//
// Core Idea
//   Sort; fix i then two-pointer on the rest; skip duplicates at every level;
//   O(n^2)
//
// Reference signature (Rust): fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/3sum/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

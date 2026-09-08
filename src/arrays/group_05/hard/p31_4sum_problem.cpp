// Problem 31: 4Sum Problem
//
// Difficulty: Hard
// Group:      5
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Return all unique quadruplets [a,b,c,d] with a+b+c+d = target. No duplicate
//   quadruplets.
//
//   Example 1:  nums = [1,0,-1,0,-2,2], target = 0  →
//   [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]] Example 2:  nums = [2,2,2,2,2], target
//   = 8       →  [[2,2,2,2]]
//
//   Constraints:
//     1 <= nums.length <= 200
//     -10^9 <= nums[i], target <= 10^9
//
// Problem Link
//   https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        long long new_target =
            (long long)target - ((long long)nums[i] + (long long)nums[j]);
        // cout << new_target << " " << j + 1 << " " << nums.size()
        //  << endl;
        for (int k = j + 1, l = (nums.size() - 1); k < l;) {
          long long curr_sum = (long long)nums[k] + (long long)nums[l];
          if (new_target > curr_sum) {
            k++;
          } else if (new_target < curr_sum) {
            l--;
          } else {
            result.push_back({nums[i], nums[j], nums[k], nums[l]});

            while (k < l && (nums[k + 1] == nums[k])) {
              k++;
            }
            k++;

            while (k < l && (nums[l - 1] == nums[l])) {
              l--;
            }
            l--;
          }
        }

        while ((j < nums.size() - 1) && nums[j + 1] == nums[j]) {
          j++;
        }
      }
      while ((i < (nums.size() - 1)) && nums[i + 1] == nums[i]) {
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
//   Key insight: sort, fix i and j, two-pointer; skip duplicates at all levels;
//   use i64 to avoid overflow.
//
// Core Idea
//   Sort; fix i and j then two-pointer; skip duplicates at all levels; use i64
//   to avoid overflow
//
// Reference signature (Rust): fn four_sum(nums: Vec<i32>, target: i32) ->
// Vec<Vec<i32>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/4sum/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

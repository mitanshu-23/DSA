// Problem 16: Majority Element (> n/2 times)
//
// Difficulty: Medium
// Group:      6
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   An element appearing more than n/2 times is the majority element; it is
//   guaranteed to exist. Return it.
//
//   Example 1:  nums = [3, 2, 3]           →  3
//   Example 2:  nums = [2,2,1,1,1,2,2]     →  2
//
//   Constraints:
//     1 <= nums.length <= 5*10^4
//
// Problem Link
//   https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int ans = 0;
    int ans_cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (ans_cnt == 0) {
        ans = nums[i];
        ans_cnt++;
      } else if (nums[i] == ans) {
        ans_cnt++;
      } else {
        ans_cnt--;
      }
    }

    return ans;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: Boyer-Moore voting — one candidate and a count.
//
// Core Idea
//   Boyer-Moore voting: one candidate and a count; increment on match,
//   decrement otherwise
//
// Reference signature (Rust): fn majority_element(nums: Vec<i32>) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/majority-element/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

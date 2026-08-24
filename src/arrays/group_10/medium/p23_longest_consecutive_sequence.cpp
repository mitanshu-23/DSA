// Problem 23: Longest Consecutive Sequence
//
// Difficulty: Medium
// Group:      10
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Return the length of the longest run of consecutive integers present in
//   nums (array order does not matter). O(n) expected.
//
//   Example 1:  nums = [100,4,200,1,3,2]       →  4   (1,2,3,4)
//   Example 2:  nums = [0,3,7,2,5,8,4,6,0,1]  →  9
//
//   Constraints:
//     0 <= nums.length <= 10^5
//
// Problem Link
//   https://leetcode.com/problems/longest-consecutive-sequence/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }

    // vector<int> nums_dup = nums;
    int sz = nums.size();

    unordered_map<int, int> exists;
    for (auto num : nums) {
      exists[num] = 1;
    }

    int ans = 1;
    for (auto num : exists) {
      int cntr = 0;
      int to_find = num.first;
      if ((exists.find(to_find) != exists.end() &&
           (exists.find(to_find + 1) == exists.end()))) {
        while (exists.find(to_find) != exists.end()) {
          cntr += 1;
          to_find--;
        }
      }
      ans = std::max(ans, cntr);
    }

    return ans;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: put all in a HashSet; only begin counting at x when x-1 is not
//   in the set.
//
// Core Idea
//   Put all in a HashSet; only begin counting at x when x-1 is absent; walk up;
//   O(n)
//
// Reference signature (Rust): fn longest_consecutive(nums: Vec<i32>) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/longest-consecutive-sequence/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

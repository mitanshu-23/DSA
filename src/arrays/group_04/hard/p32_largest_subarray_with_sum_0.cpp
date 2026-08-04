// Problem 32: Largest Subarray with Sum 0
//
// Difficulty: Hard
// Group:      4
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given an array arr[] (may contain negatives), return the length of the
//   longest subarray with sum 0.
//
//   Example 1:  arr = [15, -2, 2, -8, 1, 7, 10, 23]  →  5   ([-2,2,-8,1,7])
//   Example 2:  arr = [1, 2, 3]                       →  0
//
//   Constraints:
//     1 <= arr.length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxLength(vector<int> &arr) {
    // code here
    int ans = 0;
    unordered_map<int, int> first_map;
    int pre_sum = 0;
    first_map[0] = -1;
    for (int i = 0; i < arr.size(); i++) {
      int new_sum = pre_sum + arr[i];
      int req = -new_sum;
      auto it = first_map.find(req);
      if (it != first_map.end()) {
        int first = first_map[req];
        ans = std::max(ans, i - first);
      }

      if (first_map.find(new_sum) == first_map.end()) {
        first_map[new_sum] = i;
      }
      pre_sum = new_sum;
    }

    return ans;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: prefix sum + hashmap of the FIRST index of each prefix; equal
//   prefixes bound a zero-sum span.
//
// Core Idea
//   Prefix sum + hashmap of first occurrence; equal prefixes bound a span that
//   sums to 0
//
// Reference signature (Rust): fn max_len_zero_sum(arr: Vec<i32>) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

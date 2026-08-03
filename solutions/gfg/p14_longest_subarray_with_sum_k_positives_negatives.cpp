// Problem 14: Longest Subarray with Sum K (Positives + Negatives)
//
// Difficulty: Medium
// Group:      Prefix Sum / Subarray
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given an array that may contain negatives and a target k, return the length
//   of the longest subarray with sum k.
//
//   Example 1:  arr = [10, 5, 2, 7, 1, 9], k = 15  →  4   ([5,2,7,1])
//   Example 2:  arr = [-1, 1, 1], k = 1              →  3
//
//   Constraints:
//     1 <= arr.length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &arr, int k) {
    // code here
    vector<int> prefix_sum;
    unordered_map<int, int> pre_map;
    int ans = 0;
    prefix_sum.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
      prefix_sum.push_back(prefix_sum[i - 1] + arr[i]);
    }

    pre_map[0] = -1;
    for (int i = 0; i < prefix_sum.size(); i++) {
      int curr = prefix_sum[i];
      int req = curr - k;
      auto it = pre_map.find(req);
      if (it != pre_map.end()) {
        ans = max(ans, i - it->second);
      }

      auto it2 = pre_map.find(curr);
      if (it2 == pre_map.end()) {
        pre_map[curr] = i;
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
//   Key insight: prefix sum + hashmap storing the EARLIEST index of each
//   prefix; sliding window fails with negatives.
//
// Core Idea
//   Prefix sum + hashmap of the earliest index; if prefix[j]-k was seen, that
//   subarray sums to k
//
// Reference signature (Rust): fn longest_subarray_with_sum_k(arr: Vec<i32>, k:
// i64) -> i32 Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

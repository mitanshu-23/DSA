// Problem 13: Longest Subarray with Sum K (Positives)
//
// Difficulty: Medium
// Group:      4
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given an array of POSITIVE integers and a target k, return the length of
//   the longest subarray with sum k.
//
//   Example 1:  arr = [2,3,5,1,9], k = 10  →  3   ([2,3,5])
//   Example 2:  arr = [1,1,1,1], k = 2      →  2
//
//   Constraints:
//     1 <= arr.length <= 10^5
//     1 <= arr[i] <= 10^9
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
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
//   Key insight: all values positive → sliding window; grow to add, shrink from
//   the left when sum exceeds k.
//
// Core Idea
//   All values positive → sliding window: grow to add, shrink from the left
//   when the sum exceeds k
//
// Reference signature (Rust): fn longest_subarray_with_sum_k(arr: Vec<i32>, k:
// i64) -> i32 Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/minimum-size-subarray-sum/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

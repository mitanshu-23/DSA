// Problem 33: Count Subarrays with Given XOR K
//
// Difficulty: Hard
// Group:      4
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given an array arr[] and integer k, count the subarrays whose elements XOR
//   to exactly k.
//
//   Example 1:  arr = [4, 2, 2, 6, 4], k = 6  →  4
//   Example 2:  arr = [5, 6, 7, 8, 9], k = 5  →  2
//
//   Constraints:
//     1 <= arr.length <= 10^5
//     0 <= arr[i], k
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  long subarrayXor(vector<int> &arr, int k) {
    // code here
    vector<int> prefix_xor;
    unordered_map<int, int> map;
    int ans = 0;
    int curr_xor = 0;
    for (int i = 0; i < arr.size(); i++) {
      int new_xor = curr_xor ^ arr[i];
      map[new_xor]++;
      int req = k ^ new_xor;
      ans += map[req];
      curr_xor = new_xor;
    }
    return ans;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: prefix XOR + hashmap; for each prefix look up (prefix ^ k)
//   among earlier prefixes.
//
// Core Idea
//   Same prefix+hashmap trick with XOR; look up (prefix_xor ^ k) among earlier
//   prefixes
//
// Reference signature (Rust): fn subarrays_with_xor_k(arr: Vec<i32>, k: i32) ->
// i32 Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
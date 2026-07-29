// Problem 09: Find the Union of Two Sorted Arrays
//
// Difficulty: Easy
// Group:      Two Sorted Arrays (merge logic)
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given two sorted arrays a and b, return their union: all distinct elements
//   in sorted order.
//
//   Example 1:  a = [1,2,3,4,5], b = [2,3,4,4,5,6]  →  [1,2,3,4,5,6]
//   Example 2:  a = [1,1,1], b = [1,1]              →  [1]
//
//   Constraints:
//     1 <= a.length, b.length <= 10^5
//     both arrays are sorted in non-decreasing order.
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int ptr_1 = 0;
    int ptr_2 = 0;

    vector<int> ans;

    while (ptr_1 < a.size() || ptr_2 < b.size()) {
      if (ptr_1 < a.size() && ptr_2 == b.size()) {
        while (ptr_1 < a.size()) {
          if (ans.empty() || (a[ptr_1] != ans.back())) {
            ans.push_back(a[ptr_1]);
          }
          ptr_1 += 1;
        }
      } else if (ptr_1 == a.size() && ptr_2 < b.size()) {
        while (ptr_2 < b.size()) {
          if (ans.empty() || (b[ptr_2] != ans.back())) {
            ans.push_back(b[ptr_2]);
          }
          ptr_2 += 1;
        }
      } else {
        if (a[ptr_1] <= b[ptr_2]) {
          if (ans.empty() || (a[ptr_1] != ans.back())) {
            ans.push_back(a[ptr_1]);
          }
          ptr_1 += 1;
        } else {
          if (ans.empty() || (b[ptr_2] != ans.back())) {
            ans.push_back(b[ptr_2]);
          }
          ptr_2 += 1;
        }
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
//   Key insight: two-pointer merge; skip a value that equals the last one
//   already added.
//
// Core Idea
//   Two-pointer merge; advance the smaller side; skip a value equal to the last
//   one added
//
// Reference signature (Rust): fn find_union(a: Vec<i32>, b: Vec<i32>) ->
// Vec<i32> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/intersection-of-two-arrays/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

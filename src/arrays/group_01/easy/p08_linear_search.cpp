// Problem 08: Linear Search
//
// Difficulty: Easy
// Group:      1
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given an array arr[] and a target, return the index of the first occurrence
//   of target, or -1 if absent.
//
//   Example 1:  arr = [4, 2, 7, 1], target = 7  →  2
//   Example 2:  arr = [4, 2, 7, 1], target = 5  →  -1
//
//   Constraints:
//     1 <= arr.length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool binarySearch(vector<int> &arr, int k) {
    // code here
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
      int mid = left + ((right - left) / 2);

      if (arr[mid] == k) {
        return true;
      } else if (arr[mid] > k) {
        right = mid;
      } else {
        left = mid;
      }
    }

    return false;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Core Idea
//   Scan left to right and return the index when found, else -1
//
// Reference signature (Rust): fn linear_search(arr: Vec<i32>, target: i32) ->
// i32 Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1

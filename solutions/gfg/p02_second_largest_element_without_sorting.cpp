// Problem 02: Second Largest Element Without Sorting
//
// Difficulty: Easy
// Group:      Basic Traversal & In-place
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given an array arr[], return the second largest DISTINCT element, or -1 if
//   it does not exist.
//
//   Example 1:  arr = [12, 35, 1, 10, 34, 1]  →  34
//   Example 2:  arr = [10, 10, 10]            →  -1  (no distinct second
//   largest)
//
//   Constraints:
//     1 <= arr.length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/second-largest3735/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int getSecondLargest(vector<int> &arr) {
    // code here
    int largest = arr[0];
    int s_largest = -1;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] > largest) {
        s_largest = largest;
        largest = arr[i];
      } else if (arr[i] > s_largest) {
        s_largest = arr[i];
      }
    }

    return s_largest;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: track largest and second-largest in one pass; ignore values
//   equal to the current largest.
//
// Core Idea
//   Track largest and second-largest in one pass; the second must be strictly
//   less than the largest
//
// Reference signature (Rust): fn second_largest(arr: Vec<i32>) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/third-maximum-number/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/second-largest3735/1

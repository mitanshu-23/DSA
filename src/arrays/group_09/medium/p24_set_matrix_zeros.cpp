// Problem 24: Set Matrix Zeros
//
// Difficulty: Medium
// Group:      9
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given an m x n matrix, if a cell is 0 set its entire row and column to 0.
//   Do it in-place.
//
//   Example 1:  [[1,1,1],[1,0,1],[1,1,1]]        →  [[1,0,1],[0,0,0],[1,0,1]]
//   Example 2:  [[0,1,2,0],[3,4,5,2],[1,3,1,5]]  →
//   [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//
//   Constraints:
//     1 <= m, n <= 200
//
// Problem Link
//   https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    unordered_map<int, bool> rows_map;
    unordered_map<int, bool> cols_map;

    for (int i = 0; i < rows; i++) {

      for (int j = 0; j < cols; j++) {
        if (matrix[i][j] == 0) {
          rows_map[i] = true;
          cols_map[j] = true;
        }
      }
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (rows_map[i] || cols_map[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: use row 0 and column 0 as marker storage for O(1) extra space.
//
// Core Idea
//   Use row 0 and column 0 as markers; two passes mark then apply; O(1) extra
//   space
//
// Reference signature (Rust): fn set_zeroes(matrix: &mut Vec<Vec<i32>>)
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/set-matrix-zeroes/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1

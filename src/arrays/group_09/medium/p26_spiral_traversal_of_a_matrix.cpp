// Problem 26: Spiral Traversal of a Matrix
//
// Difficulty: Medium
// Group:      9
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Return all elements of the m x n matrix in spiral order.
//
//   Example 1:  [[1,2,3],[4,5,6],[7,8,9]]              →  [1,2,3,6,9,8,7,4,5]
//   Example 2:  [[1,2,3,4],[5,6,7,8],[9,10,11,12]]     →
//   [1,2,3,4,8,12,11,10,9,5,6,7]
//
//   Constraints:
//     1 <= m, n <= 10
//
// Problem Link
//   https://leetcode.com/problems/spiral-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0;
    int col = 0;

    vector<int> order;
    char dir = 'R';

    while (true) {
      // cout << "IN: " << row << " " << col << endl;
      if (dir == 'R' && col == n) {
        dir = 'D';
        row = row + 1;
        col = col - 1;
      } else if (dir == 'D' && row == m) {
        dir = 'L';
        row = row - 1;
        col = col - 1;
      } else if (dir == 'L' && col == -1) {
        dir = 'U';
        col = col + 1;
        row = row - 1;
      } else if (dir == 'U' && row == -1) {
        dir = 'R';
        col = col + 1;
        row = row + 1;
      }

      // cout << row << " " << col << endl;
      // Explicit case
      if (row == m || row == -1 || col == -1 || col == n) {
        break;
      }

      if (matrix[row][col] == -101) {
        if (dir == 'R') {
          if (matrix[row + 1][col - 1] == -101) {
            break;
          } else {
            dir = 'D';
            row = row + 1;
            col = col - 1;
          }
        } else if (dir == 'D') {
          if (matrix[row - 1][col - 1] == -101) {
            break;
          } else {
            dir = 'L';
            row = row - 1;
            col = col - 1;
          }
        } else if (dir == 'U') {
          if (matrix[row + 1][col + 1] == -101) {
            break;
          } else {
            dir = 'R';
            row = row + 1;
            col = col + 1;
          }
        } else {
          if (matrix[row - 1][col + 1] == -101) {
            break;
          } else {
            dir = 'U';
            row = row - 1;
            col = col + 1;
          }
        }
      } else {
        order.push_back(matrix[row][col]);
        matrix[row][col] = -101;
        if (dir == 'R') {
          col += 1;
        } else if (dir == 'D') {
          row += 1;
        } else if (dir == 'U') {
          row -= 1;
        } else {
          col -= 1;
        }
      }
    }

    return order;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: maintain top/bottom/left/right boundaries and shrink after
//   each pass.
//
// Core Idea
//   Keep top/bottom/left/right boundaries; go right,down,left,up shrinking
//   after each direction
//
// Reference signature (Rust): fn spiral_order(matrix: Vec<Vec<i32>>) ->
// Vec<i32> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/spiral-matrix/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

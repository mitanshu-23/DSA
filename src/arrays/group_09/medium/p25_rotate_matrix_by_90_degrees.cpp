// Problem 25: Rotate Matrix by 90 Degrees
//
// Difficulty: Medium
// Group:      9
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Rotate the n x n matrix 90 degrees clockwise, in-place.
//
//   Example 1:  [[1,2,3],[4,5,6],[7,8,9]]  →  [[7,4,1],[8,5,2],[9,6,3]]
//   Example 2:  [[1,2],[3,4]]               →  [[3,1],[4,2]]
//
//   Constraints:
//     1 <= n <= 20
//
// Problem Link
//   https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int half = n / 2;

    for (int i = 0; i < half; i++) {
      for (int j = i; j < n - 1 - i; j++) {
        int temp = matrix[i][j];
        int temp1 = matrix[j][n - 1 - i];
        // cout << "Replacing :" << temp1 << " with " << temp << endl;
        matrix[j][n - 1 - i] = temp;
        temp = temp1;
        temp1 = matrix[n - 1 - i][n - 1 - j];
        // cout << "Replacing :" << temp1 << " with " << temp << endl;
        matrix[n - 1 - i][n - 1 - j] = temp;
        temp = temp1;
        temp1 = matrix[n - 1 - j][i];
        // cout << "Replacing :" << temp1 << " with " << temp << endl;
        matrix[n - 1 - j][i] = temp;
        // cout << "Replacing :" << " with " << temp1 << endl;
        matrix[i][j] = temp1;
      }
    }
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: transpose, then reverse each row.
//
// Core Idea
//   Transpose the matrix, then reverse each row, for a clockwise 90-degree
//   rotation
//
// Reference signature (Rust): fn rotate(matrix: &mut Vec<Vec<i32>>)
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/rotate-image/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

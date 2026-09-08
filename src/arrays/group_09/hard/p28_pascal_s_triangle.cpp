// Problem 28: Pascal's Triangle
//
// Difficulty: Hard
// Group:      9
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Return the first num_rows rows of Pascal's triangle.
//
//   Example 1:  num_rows = 5  →  [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//   Example 2:  num_rows = 1  →  [[1]]
//
//   Constraints:
//     1 <= num_rows <= 30
//
// Problem Link
//   https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  vector<vector<int>> generate(int numRows) {

    vector<vector<int>> result;
    result.push_back({1});

    for (int i = 2; i <= numRows; i++) {
      vector<int> &back = result.back();
      vector<int> new_row = {1};
      for (int j = 0; j < back.size() - 1; j++) {
        new_row.push_back(back[j] + back[j + 1]);
      }
      new_row.push_back(1);
      result.push_back(new_row);
    }

    return result;
    // vector<vector<int>> result;
    // generate_helper(numRows, result);
    // return result;
  }

  vector<vector<int>> result_n_1;
  void generate_helper(int numRows, vector<vector<int>> &result) {
    if (numRows == 1) {
      result_n_1.push_back({1});
      return;
    }

    if (numRows == 2) {
      result_n_1.push_back({1});
      result_n_1.push_back({1, 1});
      return;
    }

    vector<int> new_row = {1};
    for (int i = 0; i < result_n_1.back().size() - 1; i++) {
      new_row.push_back(result_n_1.back()[i + 1] + result_n_1.back()[i]);
    }
    new_row.push_back(1);
    result_n_1.push_back(new_row);
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: each entry is C(r,c); build each row from the previous using
//   running multiplication.
//
// Core Idea
//   Each entry is C(r,c); build every row from the previous using running
//   multiplication
//
// Reference signature (Rust): fn generate(num_rows: i32) -> Vec<Vec<i32>>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/pascals-triangle/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/pascals-triangle0652/1

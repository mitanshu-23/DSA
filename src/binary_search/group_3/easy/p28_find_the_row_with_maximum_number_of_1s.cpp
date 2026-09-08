// Problem 28: Find the Row with Maximum Number of 1s
//
// Difficulty: Easy
// Group:      3
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given a boolean matrix mat[][] where each row is sorted (0s followed by
//   1s), return the 0-indexed row number that has the most 1s. If two rows have
//   equal 1s, return the row with the smaller index. Return -1 if no 1 exists.
//
//   Example 1:  mat = [[0,1,1,1],[0,0,1,1],[1,1,1,1],[0,0,0,0]]  →  2
//   Example 2:  mat = [[0,0],[1,1]]  →  1
//
//   Constraints:
//     1 <= mat.length, mat[0].length <= 1000
//     mat[i][j] is 0 or 1
//     Each row is sorted in non-decreasing order.
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
#include <bits/stdc++.h>
#include <ostream>
using namespace std;

class Solution {
public:
  int rowWithMax1s(vector<vector<int>> &arr) {
    // cout << " Called";
    int one_count = 0;
    int ans = 0;
    // code here
    for (int row = 0; row < arr.size(); row++) {
      int lo = 0;
      int hi = arr[row].size();
      int candidate = hi + 1;
      while (lo <= hi) {
        int mid = lo + ((hi - lo) / 2);
        if (arr[row][mid] == 1) {
          candidate = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }

      int num_of_1 = arr[row].size() - candidate;
      if (num_of_1 > one_count) {
        ans = row;
        one_count = num_of_1;
      }
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<int>> arr = {{0, 0}, {1, 1}};
  cout << s.rowWithMax1s(arr) << endl;
  return 0;
}

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Core Idea
//   Each row is sorted (0s then 1s); upper_bound finds first 1; track row with
//   leftmost 1
//
// Reference signature (Rust): fn row_with_max_ones(mat: Vec<Vec<i32>>) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
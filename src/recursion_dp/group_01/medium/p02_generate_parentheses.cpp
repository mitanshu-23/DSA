// Problem 02: Generate Parentheses
//
// Difficulty: Medium
// Group:      1
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given n pairs of parentheses, generate all combinations of well-formed
//   parentheses.
//
//   Example 1:  n = 3  →  ["((()))","(()())","(())()","()(())","()()()"]
//   Example 2:  n = 1  →  ["()"]
//
//   Constraints:
//     1 <= n <= 8
//
// Problem Link
//   https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<string> result;

public:
  void solve(int n, int opens, string temp) {
    if (n == 0 && opens == 0) {
      result.push_back(temp);
      return;
    }

    if (n > 0) {
      temp.push_back('(');
      solve(n - 1, opens + 1, temp);
      temp.pop_back();
    }

    if (opens > 0) {
      temp.push_back(')');
      solve(n, opens - 1, temp);
      temp.pop_back();
    }
  }
  vector<string> generateParenthesis(int n) {
    solve(n, 0, "");
    return result;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: add '(' while opens remain; add ')' only while closes placed <
//   opens placed.
//
// Core Idea
//   Build the string one char at a time: add '(' while opens remain, ')' while
//   closes < opens; record at length 2n, then backtrack
//
// Reference signature (Rust): fn generate_parenthesis(n: i32) -> Vec<String>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/generate-parentheses/

// Problem 01: Remove Outermost Parentheses
//
// Difficulty: Easy
// Group:      1
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given a valid parentheses string s consisting only of '(' and ')', remove
//   the outermost parentheses of every primitive substring and return the
//   result.
//
//   Example 1:  s = "(()())(())"        →  "()()()"
//   Example 2:  s = "(()())(())(()(()))"  →  "()()()()(())"
//   Example 3:  s = "()()"                →  ""
//
//   Constraints:
//     1 <= s.length <= 10^5
//     s is a valid parentheses string.
//
// Problem Link
//   https://leetcode.com/problems/remove-outermost-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeOuterParentheses(string s) {
    int open = 0;
    int close = 0;
    string res = "";

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ')' && open == 1) {
        open--;
        continue;
      } else if ((s[i] == '(' && open == 0)) {
        open++;
        continue;
      } else {
        res.push_back(s[i]);
        if (s[i] == '(') {
          open++;
        } else {
          open--;
        }
      }
    }

    return res;
  }

  // Worth Note Taking — standard form. One depth counter, and every character
  // is copied except the '(' that takes depth 0 -> 1 and the ')' that takes
  // depth 1 -> 0. Putting the ++/-- inside the condition does the test and the
  // update in one step, which removes the need for the `continue` branches.
  // Time: O(n)   Space: O(n) for the result
  string removeOuterParenthesesStd(string s) {
    string res;
    int depth = 0;

    for (char c : s) {
      if (c == '(' && depth++ > 0) {
        res.push_back(c);
      } else if (c == ')' && --depth > 0) {
        res.push_back(c);
      }
    }

    return res;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: track depth with a counter; characters at depth > 0 for '(' or
//   depth > 1 for ')' are not outermost.
//
// Core Idea
//   Depth counter; chars at depth>0 (for open) or depth>1 (for close) are not
//   outermost
//
// Reference signature (Rust): fn remove_outer_parentheses(s: String) -> String
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/remove-outermost-parentheses/
//   GeeksForGeeks: https://www.geeksforgeeks.org/remove-outermost-parentheses/

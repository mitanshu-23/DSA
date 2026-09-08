// Problem 09: Maximum Nesting Depth of Parentheses
//
// Difficulty: Easy
// Group:      1
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given a valid parentheses string s (may include other characters), return
//   the maximum nesting depth of the parentheses.
//
//   Example 1:  s = "(1+(2*3)+((8)/4))+1"  →  3
//   Example 2:  s = "(1)+((2))+(((3)))"     →  3
//
//   Constraints:
//     1 <= s.length <= 100
//     s is a valid parentheses string, possibly with digits and operators.
//
// Problem Link
//   https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int open = 0;
    int ans = 0;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        open++;
        ans = std::max(ans, open);
      } else if (s[i] == ')') {
        open--;
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
//   Key insight: a counter incremented on '(' and decremented on ')'; track the
//   running maximum.
//
// Core Idea
//   Same depth counter as problem 1; increment on open, decrement on close,
//   track the max
//
// Reference signature (Rust): fn max_depth(s: String) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:
//   https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1

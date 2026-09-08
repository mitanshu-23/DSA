// Problem 03: Largest Odd Number in a String
//
// Difficulty: Easy
// Group:      1
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given a string num representing a large non-negative integer, return the
//   largest-valued odd substring prefix, or empty string if none exists.
//
//   Example 1:  num = "52"    →  "5"
//   Example 2:  num = "4206"  →  ""
//   Example 3:  num = "35427" →  "35427"
//
//   Constraints:
//     1 <= num.length <= 10^5
//     num contains only digits, no leading zeros except num="0" itself.
//
// Problem Link
//   https://leetcode.com/problems/largest-odd-number-in-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string largestOddNumber(string num) {
    string num_dup = num;
    int len = num_dup.length();

    int indx = len - 1;
    while (indx >= 0) {
      if ((num_dup[indx] - '0') % 2 != 0) {
        break;
      } else {
        num_dup.pop_back();
      }
      indx -= 1;
    }

    return num_dup;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: scan from the right; return the prefix ending at the first odd
//   digit found.
//
// Core Idea
//   Scan from the right; return the prefix ending at the first odd digit found
//
// Reference signature (Rust): fn largest_odd_number(num: String) -> String
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/largest-odd-number-in-string/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/largest-odd-number-in-string/1

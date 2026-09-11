// Problem 11: Implement atoi (String to Integer)
//
// Difficulty: Medium
// Group:      5
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Implement atoi: convert a string to a 32-bit signed integer, following
//   these steps — skip leading whitespace, read an optional sign, read digits
//   until a non-digit, then clamp to [INT_MIN, INT_MAX].
//
//   Example 1:  s = "42"          →  42
//   Example 2:  s = "   -42"      →  -42
//   Example 3:  s = "4193 with words"  →  4193
//   Example 4:  s = "words and 987"    →  0
//
//   Constraints:
//     0 <= s.length <= 200
//
// Problem Link
//   https://leetcode.com/problems/string-to-integer-atoi/

// Implement the myAtoi(string s) function, which converts a string to a 32-bit
// signed integer.
//
// The algorithm for myAtoi(string s) is as follows:
//
// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or
// '+', assuming positivity if neither present. Conversion: Read the integer by
// skipping leading zeros until a non-digit character is encountered or the end
// of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231
// - 1], then round the integer to remain in the range. Specifically, integers
// less than -231 should be rounded to -231, and integers greater than 231 - 1
// should be rounded to 231 - 1. Return the integer as the final result.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    // remove any leading whitespaces if any
    long long ans = 0;
    int start_indx = 0;
    while (start_indx < s.length()) {
      if (s[start_indx] != ' ') {
        break;
      }
      start_indx++;
    }

    if (start_indx == s.length()) {
      return ans;
    }

    bool is_neg = false;
    if (s[start_indx] == '-') {
      is_neg = true;
      start_indx += 1;
    } else if (s[start_indx] == '+') {
      start_indx += 1;
    }
    // cout << start_indx << endl;
    while (start_indx < s.length()) {
      if (s[start_indx] >= '0' && s[start_indx] <= '9') {
        int val = s[start_indx] - '0';
        ans = (ans * 10) + val;

        if (is_neg && (-ans <= INT_MIN)) {
          return INT_MIN;
        } else if (!is_neg && (ans >= INT_MAX)) {
          return INT_MAX;
        }
      } else {
        break;
      }

      start_indx += 1;
    }

    if (is_neg) {
      ans *= -1;
    }

    return ans;
  }

  // Worth Note Taking — the portable overflow check: test *before* the
  // multiply, against INT_MAX / 10, so the accumulator never leaves int range
  // and no wider type is needed anywhere.
  //
  // myAtoi above is correct, but it stays in range only because it accumulates
  // in long long *and* returns the moment ans reaches the boundary. This form
  // is what you need when no wider type is available — Rust's i32 (which
  // panics on overflow in debug builds rather than wrapping), or writing a
  // 64-bit atoll where there is nothing wider than the accumulator.
  // Time: O(n)   Space: O(1)
  int myAtoiStd(string s) {
    int i = 0, n = s.length();

    while (i < n && s[i] == ' ') { // this problem's spec: only ' ' is skipped
      i++;
    }

    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
      sign = (s[i++] == '-') ? -1 : 1;
    }

    int ans = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {
      int d = s[i++] - '0';
      // would ans * 10 + d overflow? decide before doing it
      if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && d > INT_MAX % 10)) {
        return sign == 1 ? INT_MAX : INT_MIN;
      }
      ans = ans * 10 + d;
    }

    return sign * ans;
  }
};
// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: overflow must be checked before multiplying — compare against
//   INT_MAX/10 before applying the next digit.
//
// Core Idea
//   Trim, read optional sign, read digits, clamp to i32 range on overflow
//
// Reference signature (Rust): fn my_atoi(s: String) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/string-to-integer-atoi/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/implement-atoi/1

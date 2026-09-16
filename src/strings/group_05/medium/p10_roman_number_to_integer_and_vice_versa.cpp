// Problem 10: Roman Number to Integer and Vice Versa
//
// Difficulty: Medium
// Group:      5
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Convert between Roman numerals and integers.
//   (a) Roman to Integer: given a Roman numeral s, return its integer value.
//   (b) Integer to Roman: given an integer num (1-3999), return its Roman
//   numeral.
//
//   Example 1 (a):  s = "MCMXCIV"  →  1994
//   Example 2 (b):  num = 1994      →  "MCMXCIV"
//
//   Constraints:
//     1 <= value <= 3999
//
// Problem Link
//   https://leetcode.com/problems/roman-to-integer/

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D
// and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added
// together. 12 is written as XII, which is simply X + II. The number 27 is
// written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right.
// However, the numeral for four is not IIII. Instead, the number four is
// written as IV. Because the one is before the five we subtract it making four.
// The same principle applies to the number nine, which is written as IX. There
// are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> valMap{{'I', 1},   {'V', 5},   {'X', 10},
                                    {'L', 50},  {'C', 100}, {'D', 500},
                                    {'M', 1000}};

    int numeral = 0;

    for (int i = 0; i < s.length(); i++) {
      char curr = s[i];
      int finalVal = valMap[curr];
      // Check if subtract condition
      if (i < (s.length() - 1)) {

        char nxt = s[i + 1];
        int nxtVal = valMap[nxt];
        if (nxtVal > finalVal) {
          finalVal = (nxtVal - finalVal);
          i += 1;
        }
      }

      // cout << finalVal << endl;
      numeral += finalVal;
      // cout << numeral << endl;
    }

    return numeral;
  }

  // Worth Note Taking — standard form of romanToInt: sign each symbol
  // independently instead of consuming pairs, so the loop index advances
  // exactly once per iteration (no `i += 1` inside the body). Equivalent to
  // the version above — token IV contributes -1 at the I and +5 at the V.
  // Using .at() instead of operator[] also stops a lookup from silently
  // inserting a 0 entry for an unexpected character.
  // Time: O(n)   Space: O(1) (fixed 7-entry table)
  int romanToIntStd(string s) {
    static const unordered_map<char, int> valMap{
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};

    int numeral = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
      int currVal = valMap.at(s[i]);
      if (i + 1 < n && valMap.at(s[i + 1]) > currVal) {
        numeral -= currVal; // smaller symbol before a larger one: subtract
      } else {
        numeral += currVal;
      }
    }

    return numeral;
  }

  // Worth Note Taking — part (b), integer -> Roman: greedy over a descending
  // table that includes the six subtractive tokens.
  //
  // Greedy is correct because the table is *canonical*: after taking the
  // largest token <= num, the remainder is always expressible, and the inner
  // while can never run more than 3 times for a single-symbol token (a 4th
  // would have been covered by the subtractive token listed above it). The six
  // pairs must be in the table for that to hold — without 900/400/90/40/9/4,
  // greedy would emit DCCCC instead of CM.
  // Time: O(1) (num <= 3999)   Space: O(1)
  string intToRoman(int num) {
    static const int vals[] = {1000, 900, 500, 400, 100, 90, 50,
                               40,   10,  9,   5,   4,   1};
    static const char *syms[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                 "XL", "X",  "IX", "V",  "IV", "I"};

    string res;
    for (int i = 0; i < 13; i++) {
      while (num >= vals[i]) {
        num -= vals[i];
        res += syms[i];
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
//   Key insight: Roman->Int scans left to right, subtracting when the current
//   symbol's value is less than the next; Int->Roman is greedy using a
//   value-symbol table sorted descending.
//
// Core Idea
//   Scan left to right; subtract when current value < next value, else add
//
// Reference signature (Rust): fn roman_to_int(s: String) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/roman-to-integer/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1

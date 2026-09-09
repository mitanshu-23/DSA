// Problem 05: Isomorphic Strings
//
// Difficulty: Easy
// Group:      3
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given two strings s and t, return true if the characters in s can be
//   replaced to get t, with a consistent one-to-one mapping in both directions.
//
//   Example 1:  s = "egg", t = "add"     →  true
//   Example 2:  s = "foo", t = "bar"     →  false
//   Example 3:  s = "paper", t = "title" →  true
//
//   Constraints:
//     1 <= s.length <= 5*10^4
//     s.length == t.length
//
// Problem Link
//   https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, bool> isMapped;
    unordered_map<char, char> charMap;

    for (int i = 0; i < s.length(); i++) {
      if (charMap.find(s[i]) != charMap.end()) {
        char mapped = charMap[s[i]];
        if (t[i] != mapped) {
          return false;
        }
      } else if (isMapped[t[i]]) {
        return false;
      } else {
        charMap[s[i]] = t[i];
        isMapped[t[i]] = true;
      }
    }

    return true;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: maintain two maps s->t and t->s; a character may not map two
//   different ways in either direction.
//
// Core Idea
//   Two maps s->t and t->s; check consistency in both directions for every pair
//
// Reference signature (Rust): fn is_isomorphic(s: String, t: String) -> bool
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/isomorphic-strings/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

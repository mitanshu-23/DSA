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

  // Worth Note Taking — standard optimal. Instead of two hash maps, store the
  // last-seen position of each character in both strings, 1-based so that 0
  // means "never seen". s[i] and t[i] may correspond only if they last
  // appeared at the same index; checking that one equality enforces the
  // bijection in both directions at once, so no second "is already mapped"
  // table is needed. Fixed-size arrays also mean no hashing.
  // The length guard matters: without it t[i] reads out of bounds when t is
  // shorter than s.
  // Time: O(n)   Space: O(1) (two 256-entry tables)
  bool isIsomorphicStd(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    int lastS[256] = {0}, lastT[256] = {0};

    for (int i = 0; i < (int)s.length(); i++) {
      unsigned char a = s[i], b = t[i];
      if (lastS[a] != lastT[b]) {
        return false;
      }

      lastS[a] = i + 1;
      lastT[b] = i + 1;
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

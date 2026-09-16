// Problem 06: Check if One String is a Rotation of Another
//
// Difficulty: Easy
// Group:      4
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given two strings s and goal, return true if s can become goal after some
//   number of shifts (left rotations) on s.
//
//   Example 1:  s = "abcde", goal = "cdeab"  →  true
//   Example 2:  s = "abcde", goal = "abced"  →  false
//
//   Constraints:
//     1 <= s.length, goal.length <= 100
//
// Problem Link
//   https://leetcode.com/problems/rotate-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
      return false;
    }

    int maxRotations = s.length() - 1;
    int len = maxRotations + 1;

    for (int rotation = 1; rotation <= maxRotations; rotation++) {
      bool pass = true;
      for (int i = 0; i < len; i++) {
        int s_indx = (rotation + i) % len;
        if (s[s_indx] != goal[i]) {
          pass = false;
          break;
        }
      }

      if (pass) {
        return true;
      }
    }

    return s == goal; // rotation 0: the loop starts at 1, so check it here
  }

  // Worth Note Taking
  bool rotateString2(string s, string goal) {
    if (s.length() != goal.length())
      return false;
    s = s + s;
    return s.find(goal) != string::npos;
  }

  // Worth Note Taking — O(n) via KMP, the actual optimal. rotateString2's
  // find() is O(n^2) in the worst case because libstdc++ searches naively;
  // building the prefix function over goal + sentinel + s + s finds the match
  // in linear time. The sentinel (any character absent from the input) stops a
  // prefix match from spanning the join between pattern and text.
  // Reaching k == n means all n characters of goal matched inside s + s, which
  // by the substring argument means goal is a rotation of s.
  // Time: O(n)   Space: O(n)
  bool rotateStringKMP(string s, string goal) {
    int n = s.length();
    if ((int)goal.length() != n) {
      return false;
    }
    if (n == 0) {
      return true;
    }

    string pat = goal + '\x01' + s + s;
    vector<int> pi(pat.size(), 0);

    for (size_t i = 1; i < pat.size(); i++) {
      int k = pi[i - 1];
      while (k > 0 && pat[i] != pat[k]) {
        k = pi[k - 1];
      }
      if (pat[i] == pat[k]) {
        k++;
      }

      pi[i] = k;
      if (k == n) {
        return true;
      }
    }

    return false;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: goal is a rotation of s iff len(s)==len(goal) and goal is a
//   substring of s+s.
//
// Core Idea
//   goal is a rotation of s iff goal is a substring of s+s and lengths match
//
// Reference signature (Rust): fn rotate_string(s: String, goal: String) -> bool
// Complexity — rotateString:  Time: O(n^2)  Space: O(1)
//              rotateString2: Time: O(n^2) worst case (naive find)  Space: O(n)
//              KMP on goal + '#' + s + s: Time: O(n)  Space: O(n)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/rotate-string/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

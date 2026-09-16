// Problem 07: Check if Two Strings are Anagram
//
// Difficulty: Easy
// Group:      3
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given two strings s and t, return true if t is an anagram of s (same
//   letters, same multiplicity).
//
//   Example 1:  s = "anagram", t = "nagaram"  →  true
//   Example 2:  s = "rat", t = "car"           →  false
//
//   Constraints:
//     1 <= s.length, t.length <= 5*10^4
//     s and t consist of lowercase English letters.
//
// Problem Link
//   https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> wordCount;
    for (int i = 0; i < s.length(); i++) {
      wordCount[s[i]]++;
    }

    for (int j = 0; j < t.length(); j++) {
      if (wordCount.find(t[j]) != wordCount.end()) {
        if (wordCount[t[j]] == 1) {
          wordCount.erase(t[j]);
        } else {
          wordCount[t[j]]--;
        }
      } else {
        return false;
      }
    }

    return true;
  }

  // Worth Note Taking — standard optimal. One 26-entry count array,
  // incremented over s and decremented over t; a count going negative means t
  // holds a character s does not have enough of.
  //
  // NOTE the length guard on the first line — it is exactly what isAnagram
  // above is missing. Without it, any t that is a sub-multiset of s passes:
  // isAnagram("ab", "a") returns true, and so does isAnagram("aab", "ab").
  // With equal lengths, "t takes nothing s lacks" already implies the counts
  // match exactly, so no final emptiness check is needed.
  // Time: O(n)   Space: O(1)
  bool isAnagramStd(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    int count[26] = {0};
    for (char c : s) {
      count[c - 'a']++;
    }

    for (char c : t) {
      if (--count[c - 'a'] < 0) {
        return false;
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
//   Key insight: frequency array of size 26; increment for chars in s,
//   decrement for chars in t; anagram iff all zero.
//
// Core Idea
//   Frequency array of size 26; increment for s, decrement for t; all zero
//   means anagram
//
// Reference signature (Rust): fn is_anagram(s: String, t: String) -> bool
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/valid-anagram/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/anagram-1587115620/1

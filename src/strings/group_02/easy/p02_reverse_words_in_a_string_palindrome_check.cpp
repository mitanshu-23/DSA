// Problem 02: Reverse Words in a String / Palindrome Check
//
// Difficulty: Easy
// Group:      2
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Two related problems:
//   (a) Reverse Words: given s, reverse the order of the words, collapsing
//   extra spaces. (b) Valid Palindrome: given s, considering only alphanumerics
//   and ignoring case, return true if it reads the same forwards and backwards.
//
//   Example 1 (a):  s = "the sky is blue"  →  "blue is sky the"
//   Example 2 (b):  s = "A man, a plan, a canal: Panama"  →  true
//
//   Constraints:
//     1 <= s.length <= 10^4
//
// Problem Link
//   https://leetcode.com/problems/reverse-words-in-a-string/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string res = "";
    string temp = "";
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == ' ' && !temp.empty()) {
        reverse(temp.begin(), temp.end());
        res += temp + " ";
        temp.clear();
      } else if (s[i] != ' ') {
        temp.push_back(s[i]);
      }
    }
    if (!temp.empty()) {
      reverse(temp.begin(), temp.end());
      res += temp;
    } else {
      res.pop_back();
    }
    //
    return res;
  }

  // Worth Note Taking — standard optimal. Reverse the whole string, then
  // reverse each word back in place: reversing twice restores each word's own
  // characters while leaving the words in opposite order. A read index and a
  // write index compact runs of spaces during the same pass, so no temporary
  // word buffer is needed and leading/trailing spaces fall out for free.
  // Time: O(n)   Space: O(1) extra (mutates its own copy of s)
  string reverseWordsOrderStd(string s) {
    reverse(s.begin(), s.end());

    int n = s.size(), write = 0, i = 0;
    while (i < n) {
      while (i < n && s[i] == ' ') {
        i++;
      }
      if (i == n) {
        break;
      }

      if (write != 0) {
        s[write++] = ' '; // single separator before every word but the first
      }

      int wordStart = write;
      while (i < n && s[i] != ' ') {
        s[write++] = s[i++];
      }
      reverse(s.begin() + wordStart, s.begin() + write);
    }

    s.resize(write);
    return s;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: reverse-words splits on spaces and reverses the list (or
//   reverses the whole string then each word); palindrome check uses two
//   pointers from both ends.
//
// Core Idea
//   Split on spaces and reverse the word list; for palindrome use two pointers
//   walking inward
//
// Reference signature (Rust): fn reverse_words(s: String) -> String
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/reverse-words-in-a-string/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string1946/1

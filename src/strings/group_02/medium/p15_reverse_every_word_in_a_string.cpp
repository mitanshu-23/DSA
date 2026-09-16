// Problem 15: Reverse Every Word in a String
//
// Difficulty: Medium
// Group:      2
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given a string s, reverse the characters of every word while keeping the
//   words and spaces in their original order.
//
//   Example 1:  s = "Let's take LeetCode contest"  →  "s'teL ekat edoCteeL
//   tsetnoc" Example 2:  s = "God Ding"                     →  "doG gniD"
//
//   Constraints:
//     1 <= s.length <= 5*10^4
//
// Problem Link
//   https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string res = "";
    string temp = "";

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
        if (!temp.empty()) {
          reverse(temp.begin(), temp.end());
          res += temp;
          temp.clear();
        }

        res += " ";
      } else {
        temp.push_back(s[i]);
      }
    }

    if (!temp.empty()) {
      reverse(temp.begin(), temp.end());
      res += temp;
      temp.clear();
    }

    return res;
  }

  // INplace reverse
  string reverseWordsInplace(string s) {
    int indx = 0;
    while (indx < s.length()) {
      int start = indx;
      while (indx < s.length() && s[indx] != ' ') {
        indx += 1;
      }
      //   cout<<indx<<endl;
      for (int end = indx - 1; end > start; start++, end--) {
        swap(s[start], s[end]);
      }
      indx += 1;
    }

    return s;
  }

  // Worth Note Taking — standard form of reverseWordsInplace above: take each
  // word's bounds with find(' ') and hand the range to std::reverse instead of
  // swapping by hand. Identical O(n) time / O(1) extra space, with less index
  // arithmetic to get wrong. Note `start <= s.size()`, not `<`: it is what
  // makes a trailing empty word (a string ending in a space) terminate.
  // Time: O(n)   Space: O(1) extra
  string reverseWordsStd(string s) {
    size_t start = 0;

    while (start <= s.size()) {
      size_t end = s.find(' ', start);
      if (end == string::npos) {
        end = s.size();
      }

      reverse(s.begin() + start, s.begin() + end);
      start = end + 1;
    }

    return s;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: split on spaces, reverse each word's characters in place (not
//   the word order), rejoin.
//
// Core Idea
//   Reverse each word's characters in place; keep the word order unchanged
//
// Reference signature (Rust): fn reverse_each_word(s: String) -> String
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/reverse-words-in-a-string-iii/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1

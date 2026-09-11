// Problem 04: Longest Common Prefix
//
// Difficulty: Easy
// Group:      4
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given an array of strings strs, return the longest common prefix among all
//   strings. Return "" if there is none.
//
//   Example 1:  strs = ["flower","flow","flight"]  →  "fl"
//   Example 2:  strs = ["dog","racecar","car"]      →  ""
//
//   Constraints:
//     1 <= strs.length <= 200
//     0 <= strs[i].length <= 200
//
// Problem Link
//   https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string res = "";
    int pref_len = 0;
    while (true) {
      char ch = ' ';
      if (pref_len < strs[0].length()) {
        ch = strs[0][pref_len];
        for (int j = 1; j < strs.size(); j++) {
          // <= : length == pref_len means strs[j] is already exhausted, so
          // check it before indexing rather than relying on operator[]
          // returning '\0' at size().
          if (strs[j].length() <= pref_len || strs[j][pref_len] != ch) {
            return res;
          }
        }
      } else {
        return res;
      }

      res += ch;
      pref_len++;
    }

    return res;
  }

  // Worth Note Taking — the LCP of the whole set equals the LCP of just the
  // lexicographically smallest and largest strings: every other string sorts
  // between those two, so it must agree with both wherever they agree with
  // each other. One pass to find the extremes, then a single two-string
  // comparison — no per-column loop over all n strings.
  // Time: O(S), S = total characters (the min/max scan dominates)
  // Space: O(L) for the result
  string longestCommonPrefixMinMax(vector<string> &strs) {
    const string &lo = *min_element(strs.begin(), strs.end());
    const string &hi = *max_element(strs.begin(), strs.end());

    size_t i = 0;
    while (i < lo.size() && i < hi.size() && lo[i] == hi[i]) {
      i++;
    }

    return lo.substr(0, i);
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: take the first string as the candidate prefix and shrink it
//   while a later string doesn't start with it.
//
// Core Idea
//   Take the first string as candidate; shrink it while a later string does not
//   start with it
//
// Reference signature (Rust): fn longest_common_prefix(strs: Vec<String>) ->
// String
// Complexity — Time: O(n * L), n = number of strings, L = answer length
//              Space: O(1) extra, beyond the O(L) result
//
// All Links
//   LeetCode:      https://leetcode.com/problems/longest-common-prefix/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

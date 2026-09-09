// Problem 08: Sort Characters by Frequency
//
// Difficulty: Medium
// Group:      3
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given a string s, sort it in decreasing order based on the frequency of
//   characters; return any string with the same multiset that satisfies this.
//
//   Example 1:  s = "tree"    →  "eert"  (or "eetr")
//   Example 2:  s = "cccaaa"  →  "cccaaa"  (or "aaaccc")
//
//   Constraints:
//     1 <= s.length <= 5*10^5
//
// Problem Link
//   https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> freqCount;

    for (int i = 0; i < s.length(); i++) {
      freqCount[s[i]]++;
    }

    vector<pair<int, char>> vec;
    for (auto it = freqCount.begin(); it != freqCount.end(); it++) {
      vec.push_back({it->second, it->first});
    }

    sort(vec.begin(), vec.end());
    string res = "";

    for (int i = vec.size() - 1; i >= 0; i--) {
      for (int j = 0; j < vec[i].first; j++) {
        res.push_back(vec[i].second);
      }
    }

    return res;
  }

  string frequencySort2(string s) {
    unordered_map<char, int> freqCount;
    map<int, unordered_set<char>> charBucket;

    for (int i = 0; i < s.length(); i++) {
      int last_count = freqCount[s[i]];
      freqCount[s[i]]++;
      charBucket[last_count].erase(s[i]);
      charBucket[last_count + 1].insert(s[i]);
    }

    string res = "";
    for (auto it = charBucket.rbegin(); it != charBucket.rend(); ++it) {
      for (const auto &ch : it->second) {
        for (int i = 0; i < it->first; i++) {
          res.push_back(ch);
        }
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
//   Key insight: build a frequency map, sort characters by frequency
//   descending, rebuild by repeating each character its count times.
//
// Core Idea
//   Build a frequency map, sort characters descending by count, rebuild the
//   string
//
// Reference signature (Rust): fn frequency_sort(s: String) -> String
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/sort-characters-by-frequency/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/sort-characters-by-frequency/1

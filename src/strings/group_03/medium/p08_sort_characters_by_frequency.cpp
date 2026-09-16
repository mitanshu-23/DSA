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
    vector<unordered_set<char>> charBucket(s.length());

    for (int i = 0; i < s.length(); i++) {
      int last_count = freqCount[s[i]];
      freqCount[s[i]]++;
      charBucket[last_count].erase(s[i]);
      charBucket[last_count + 1].insert(s[i]);
    }

    string res = "";
    for (int i = s.length(); i >= 0; i--) {
      for (const auto &ch : charBucket[i]) {
        for (int j = 0; j < i; j++) {
          res.push_back(ch);
        }
      }
    }

    return res;
  }

  // Worth Note Taking — standard optimal: bucket sort by frequency, which
  // drops the comparison sort entirely. Bucket i holds every character
  // occurring exactly i times, so walking the buckets from high to low emits
  // whole groups in non-increasing frequency order.
  //
  // NOTE the bucket count, `best + 1`. Indexing a bucket *by a count* means
  // the largest valid index is the largest count, which for "aaa" is
  // s.length() itself — frequencySort2 above sizes its buckets s.length() and
  // then writes to charBucket[last_count + 1], which is a heap overflow on any
  // string made of a single repeated character.
  // Time: O(n)   Space: O(n)
  string frequencySortStd(string s) {
    unordered_map<char, int> freq;
    int best = 0;
    for (char c : s) {
      best = max(best, ++freq[c]);
    }

    vector<string> bucket(best + 1);
    for (const auto &kv : freq) {
      bucket[kv.second].push_back(kv.first);
    }

    string res;
    res.reserve(s.size());
    for (int f = best; f >= 1; f--) {
      for (char ch : bucket[f]) {
        res.append(f, ch);
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

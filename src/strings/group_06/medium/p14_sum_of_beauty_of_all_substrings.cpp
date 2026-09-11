// Problem 14: Sum of Beauty of All Substrings
//
// Difficulty: Medium
// Group:      6
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   The beauty of a string is the difference between the frequencies of its
//   most frequent and least frequent characters. Given s, return the sum of
//   beauty over all its substrings.
//
//   Example 1:  s = "aabcb"  →  5
//   Example 2:  s = "aabcbaa" →  17
//
//   Constraints:
//     1 <= s.length <= 500
//
// Problem Link
//   https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int beautySum(string s) {
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
      vector<int> charCount(26, 0);
      charCount[s[i] - 'a']++;

      for (int j = i + 1; j < s.length(); j++) {
        charCount[s[j] - 'a']++;
        // cout << s[j] << " " << charCount[s[j] - 'a'] << endl;
        int max = *std::max_element(charCount.begin(), charCount.end());

        // Custom comparator to find the minimum frequency that is > 0
        int min = *std::min_element(
            charCount.begin(), charCount.end(), [](int a, int b) {
              if (a <= 0)
                return false; // Treat 0 or negative as infinity
              if (b <= 0)
                return true;
              return a < b;
            });

        // cout << max << " " << min << endl;
        if (min > 0) {
          result += (max - min);
        }
      }
    }

    return result;
  }
};

// ---------------------------------------------------------------------------
// SolutionStandard — same 26-slot frequency idea as Solution above, but pulls
// max/min out with one manual pass over the 26 slots instead of two separate
// STL scans (max_element, then min_element with a custom "skip zero" lambda).
// Same O(26 n^2) time; ~2x fewer comparisons in practice.
// ---------------------------------------------------------------------------
class SolutionStandard {
public:
    int beautySum(string s) {
        int n = s.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int mx = 0, mn = INT_MAX;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] == 0) continue;
                    mx = max(mx, freq[c]);
                    mn = min(mn, freq[c]);
                }
                result += mx - mn;
            }
        }
        return result;
    }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: for each starting index expand right while maintaining a
//   26-slot frequency array; beauty = max_freq - min_freq among present chars.
//
// Core Idea
//   For each start expand right maintaining a freq array; beauty = max_freq -
//   min_freq
//
// Reference signature (Rust): fn beauty_sum(s: String) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings/1

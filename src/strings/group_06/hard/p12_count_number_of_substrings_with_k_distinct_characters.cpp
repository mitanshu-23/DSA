// Problem 12: Count Number of Substrings with K Distinct Characters
//
// Difficulty: Hard
// Group:      6
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given a string s and an integer k, count the substrings that contain
//   exactly k distinct characters.
//
//   Example 1:  s = "abcba", k = 2  →  5
//   Example 2:  s = "aba", k = 1    →  4
//
//   Constraints:
//     1 <= s.length <= 5*10^3
//     1 <= k <= 26
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int helper_more(string &s, int k) {
    vector<int> charMap(26, 0);
    int distinctChars = 0;
    int res = 0;
    int indx = 0;
    int start_indx = 0;
    while (indx < s.length()) {
      charMap[s[indx] - 'a']++;
      if (charMap[s[indx] - 'a'] == 1) {
        distinctChars++;
      }

      if (distinctChars >= k) {
        while (distinctChars >= k) {
          res += (s.length() - indx);
          charMap[s[start_indx] - 'a']--;
          if (charMap[s[start_indx] - 'a'] == 0) {
            distinctChars--;
          }
          start_indx++;
        }
      }

      indx += 1;
    }
    // 		cout << "For greater than: " << k << " ,res: " << res << endl;
    return res;
  }

  int countSubstr(string &s, int k) {
    // substrings where count is > k - substring where count is >= k
    return helper_more(s, k) - helper_more(s, k + 1);
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: count(exactly k) = count(at most k) - count(at most k-1);
//   count(at most k) is an O(n) sliding window.
//
// Core Idea
//   exactly K distinct = atMost(K) - atMost(K-1); atMost is an O(n) sliding
//   window
//
// Reference signature (Rust): fn count_substrings_with_k_distinct(s: String, k:
// i32) -> i32 Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

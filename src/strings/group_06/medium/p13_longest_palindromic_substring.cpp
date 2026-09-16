// Problem 13: Longest Palindromic Substring
//
// Difficulty: Medium
// Group:      6
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given a string s, return the longest palindromic substring of s.
//
//   Example 1:  s = "babad"  →  "bab"  (or "aba")
//   Example 2:  s = "cbbd"   →  "bb"
//
//   Constraints:
//     1 <= s.length <= 1000
//
// Problem Link
//   https://leetcode.com/problems/longest-palindromic-substring/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int ans_len = 1;
        pair<int, int> ans = {0, 0};
        // Check for odd length substrings
        for (int indx = 0; indx < s.length(); indx++) {
            int t_indx = indx;
            int offset = 0;
            while ((t_indx - (offset + 1)) >= 0 &&
                   (t_indx + (offset + 1)) < s.length()) {
                if (s[t_indx - (offset + 1)] != s[t_indx + (offset + 1)]) {
                    break;
                }
                offset++;
            }

            if (((offset * 2) + 1) > ans_len) {
                // cout << "Odd length: " << offset << " Indx: " << indx << endl;
                ans_len = offset * 2 + 1;
                ans = {indx - offset, indx + offset};
            }
        }

        // Check for even length substrings
        for (int indx = 1; indx < s.length(); indx++) {
            if (s[indx] == s[indx - 1]) {
                int left_i = indx - 2;
                int right_i = indx + 1;

                while (left_i >= 0 && right_i < s.length()) {
                    if (s[left_i] != s[right_i]) {
                        break;
                    }

                    left_i--;
                    right_i++;
                }

                if ((right_i - left_i - 1) > ans_len) {
                    // cout << "Right " << right_i << " Left: " << left_i << endl;
                    ans_len = right_i - left_i - 1;
                    ans = {left_i + 1, right_i - 1};
                }
            }
        }
        // cout << ans.first << " " << ans.second << endl;
        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};

// ---------------------------------------------------------------------------
// SolutionStandard — same expand-around-center idea as Solution above, but
// unified into a single loop over 2n-1 virtual centers instead of two
// separate odd/even passes. Same O(n^2) time; purely a style difference.
// ---------------------------------------------------------------------------
class SolutionStandard {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        int best_start = 0, best_len = 1;

        for (int center = 0; center < 2 * n - 1; center++) {
            int left = center / 2;
            int right = left + (center % 2);
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // left/right overshot by one on exit
            int len = right - left - 1;
            if (len > best_len) {
                best_len = len;
                best_start = left + 1;
            }
        }
        return s.substr(best_start, best_len);
    }
};

// ---------------------------------------------------------------------------
// SolutionManacher — Manacher's algorithm, O(n) time. Requested in the
// approach note to compare against the O(n^2) expand-around-center above.
// ---------------------------------------------------------------------------
class SolutionManacher {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        // Transform: "aba" -> "^#a#b#a#$"
        // '#' separates real chars so odd/even palindromes both become
        // odd-length in transformed space. '^' and '$' are sentinels so the
        // expand loop never needs a bounds check.
        string t = "^";
        for (char c : s) { t += '#'; t += c; }
        t += "#$";

        int n = t.size();
        vector<int> p(n, 0);       // p[i] = radius of palindrome centered at i in t
        int center = 0, right = 0; // rightmost palindrome's center and right edge

        for (int i = 1; i < n - 1; i++) {
            if (i < right) {
                // i has a mirror i' = 2*center - i inside the known
                // palindrome; p[i] is at least min(right-i, p[i']) without
                // re-checking characters.
                p[i] = min(right - i, p[2 * center - i]);
            }
            // Try to extend past what the mirror guaranteed
            while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;

            if (i + p[i] > right) { center = i; right = i + p[i]; }
        }

        int best_len = 0, best_center = 0;
        for (int i = 1; i < n - 1; i++)
            if (p[i] > best_len) { best_len = p[i]; best_center = i; }

        int start = (best_center - best_len) / 2; // map back to original indices
        return s.substr(start, best_len);
    }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: expand around every center, trying both odd-length and
//   even-length windows; track the best span seen.
//
// Core Idea
//   Expand around every center, both odd and even length; track the best window
//
// Reference signature (Rust): fn longest_palindrome(s: String) -> String
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/longest-palindromic-substring/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

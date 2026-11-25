// Problem 01: Pow(x, n)
//
// Difficulty: Medium
// Group:      1
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Implement pow(x, n), which calculates x raised to the power n.
//
//   Example 1:  x = 2.00000, n = 10  →  1024.00000
//   Example 2:  x = 2.00000, n = -2  →  0.25000
//
//   Constraints:
//     -100.0 < x < 100.0
//     -2^31 <= n <= 2^31 - 1
//
// Problem Link
//   https://leetcode.com/problems/powx-n/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // To keep in mind 2^8 = 4^4 = 16^2....
  double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    }

    if (n < 0) {
      long long nn = n;
      nn = -nn - 1;
      return ((1 / myPow(x, nn)) * (1 / x));
    }

    if (n % 2 == 0) {
      return myPow(x * x, n / 2);
    }

    return myPow(x * x, (n - 1) / 2) * x;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: x^n = (x^(n/2))^2 — halve n each call for O(log n); handle odd
//   n and negative n separately.
//
// Core Idea
//   x^n = (x^(n/2))^2; halve n each call, peel off one x when n is odd, invert
//   for negative n
//
// Reference signature (Rust): fn my_pow(x: f64, n: i32) -> f64
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/powx-n/

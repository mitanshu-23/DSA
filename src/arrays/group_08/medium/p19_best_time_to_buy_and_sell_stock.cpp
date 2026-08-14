// Problem 19: Best Time to Buy and Sell Stock
//
// Difficulty: Medium
// Group:      8
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   prices[i] is the stock price on day i. Buy once and sell on a later day to
//   maximise profit; return the max profit, or 0.
//
//   Example 1:  prices = [7,1,5,3,6,4]  →  5   (buy at 1, sell at 6)
//   Example 2:  prices = [7,6,4,3,1]   →  0
//
//   Constraints:
//     1 <= prices.length <= 10^5
//     0 <= prices[i] <= 10^4
//
// Problem Link
//   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 1) {
      return 0;
    }
    int ans = 0;
    int last_sell = prices[prices.size() - 1];
    for (int i = prices.size() - 1; i >= 0; i--) {
      ans = std::max(ans, last_sell - prices[i]);
      if (prices[i] > last_sell) {
        last_sell = prices[i];
      }
    }

    return ans;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: single pass tracking the minimum price so far.
//
// Core Idea
//   Single pass tracking the minimum price so far; profit = price - min; keep
//   the global best
//
// Reference signature (Rust): fn max_profit(prices: Vec<i32>) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/buy-and-sell-a-stock-best-time-to-buy-and-sell-stock/1

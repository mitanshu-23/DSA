// Problem 40: Maximum Product Subarray
//
// Difficulty: Hard
// Group:      7
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Return the largest product of any contiguous subarray.
//
//   Example 1:  nums = [2, 3, -2, 4]  →  6   ([2,3])
//   Example 2:  nums = [-2, 0, -1]     →  0
//
//   Constraints:
//     1 <= nums.length <= 2*10^4
//
// Problem Link
//   https://leetcode.com/problems/maximum-product-subarray/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    int product = INT_MIN;
    int start_indx = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        if ((i > 0) && (i > start_indx)) {
          product =
              std::max(product, maxProduct_helper(nums, start_indx, i - 1));
        }
        product = max(product, 0);
        start_indx = i + 1;
      }
    }
    // cout << product << endl;
    if ((start_indx <= (nums.size() - 1))) {
      product = std::max(product,
                         maxProduct_helper(nums, start_indx, nums.size() - 1));
    }

    return product;
  }

  int maxProduct_helper(vector<int> &nums, int start_indx, int end_indx) {
    // cout << start_indx << " " << end_indx << endl;
    if (start_indx == end_indx) {
      return nums[start_indx];
    }
    int first_neg_product = 0;
    int last_neg = 0;
    int last_prod = 0;
    int curr_prod = 1;

    for (int i = start_indx; i <= end_indx; i++) {
      if (nums[i] < 0) {
        if (first_neg_product == 0) {
          first_neg_product = curr_prod * nums[i];
        }
        if (last_neg == 0) {
          last_neg = nums[i];
          last_prod = curr_prod;
          curr_prod = 1;
        } else {
          curr_prod = curr_prod * last_prod * last_neg * nums[i];
          last_neg = 0;
        }
      } else {
        curr_prod = curr_prod * nums[i];
      }
    }

    int other_candidate = last_prod;
    if (last_neg != 0) {
      other_candidate = std::max(
          (last_prod * curr_prod * last_neg) / first_neg_product, last_prod);
    }

    return max(other_candidate, curr_prod);
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: track both the running max and min product (a negative swaps
//   them); reset when starting fresh wins.
//
// Core Idea
//   Track both max and min products (a negative swaps them); reset when
//   starting fresh wins
//
// Reference signature (Rust): fn max_product(nums: Vec<i32>) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/maximum-product-subarray/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
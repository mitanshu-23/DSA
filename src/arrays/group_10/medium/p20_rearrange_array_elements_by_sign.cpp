// Problem 20: Rearrange Array Elements by Sign
//
// Difficulty: Medium
// Group:      10
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   nums has an equal number of positive and negative integers. Rearrange so
//   signs alternate starting with a positive, preserving the relative order
//   within each sign.
//
//   Example 1:  nums = [3,1,-2,-5,2,-4]  →  [3,-2,1,-5,2,-4]
//   Example 2:  nums = [-1, 1]           →  [1, -1]
//
//   Constraints:
//     2 <= nums.length <= 2*10^5
//     equal positives and negatives; no zeros.
//
// Problem Link
//   https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    vector<int> result;
    int pos_ptr = 0;
    int ng_ptr = 0;
    // int half = nums.size() / 2;
    int total = 0;
    while (total < nums.size()) {
      while (nums[pos_ptr] < 0) {
        pos_ptr += 1;
      }
      while (nums[ng_ptr] > 0) {
        ng_ptr += 1;
      }
      result.push_back(nums[pos_ptr]);
      result.push_back(nums[ng_ptr]);
      pos_ptr += 1;
      ng_ptr += 1;
      total += 2;
    }

    return result;
  }

  vector<int> rearrangeArray_worelativeorder(vector<int> &nums) {
    // vector<int> result;
    int pos_ptr = 0;
    int ng_ptr = 1;
    int ptr = 0;

    while (ptr < nums.size()) {
      if (ptr % 2 == 0) {
        while (nums[pos_ptr] < 0) {
          pos_ptr += 1;
        }

        swap(nums[pos_ptr], nums[ptr]);
        pos_ptr += 1;
      } else {
        // cout << ptr << endl;
        while (nums[ng_ptr] > 0) {
          ng_ptr += 1;
        }
        // cout << ng_ptr << endl;
        swap(nums[ng_ptr], nums[ptr]);
        ng_ptr += 1;
      }

      ptr += 1;
      // pos_ptr = ptr;
      // ng_ptr = ptr;
    }

    return nums;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: positives to even indices, negatives to odd, using two
//   position pointers.
//
// Core Idea
//   Positives to even indices, negatives to odd, using two running position
//   pointers
//
// Reference signature (Rust): fn rearrange_array(nums: Vec<i32>) -> Vec<i32>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode: https://leetcode.com/problems/rearrange-array-elements-by-sign/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

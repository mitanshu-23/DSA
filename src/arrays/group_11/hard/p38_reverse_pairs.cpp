// Problem 38: Reverse Pairs
//
// Difficulty: Hard
// Group:      11
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Count the reverse pairs: pairs (i, j) with i < j and arr[i] > 2 * arr[j].
//
//   Example 1:  nums = [1,3,2,3,1]  →  2
//   Example 2:  nums = [2,4,3,5,1]  →  3
//
//   Constraints:
//     1 <= nums.length <= 5*10^4
//     -2^31 <= nums[i] <= 2^31 - 1
//
// Problem Link
//   https://leetcode.com/problems/reverse-pairs/

// 493. Reverse Pairs Hard Topics premium lock icon Companies Hint Given an
// integer
//     array nums,
//     return the number of reverse pairs in the array.

//                A reverse pair is a
//                pair(i, j) where :

//                0 <= i < j < nums.length and
//            nums[i] > 2 * nums[j].

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums, int left_i, int right_i, int mid, int &result) {
    int ptr = mid + 1;
    for (int i = left_i; i <= mid; i++) {
      while ((ptr <= right_i) && ((long long)nums[ptr] * 2LL >= nums[i])) {
        ptr++;
      }
      result += (right_i - ptr + 1);
    }
    // merge here
    vector<int> temp;
    int left = left_i;
    int right = mid + 1;
    while (left <= mid && right <= right_i) {
      if (nums[left] >= nums[right]) {
        temp.push_back(nums[left]);
        left++;
      } else {
        temp.push_back(nums[right]);
        right++;
      }
    }

    while (left <= mid) {
      temp.push_back(nums[left]);
      left++;
    }

    while (right <= right_i) {
      temp.push_back(nums[right]);
      right++;
    }

    for (int i = 0; i < temp.size(); i++) {
      nums[left_i + i] = temp[i];
    }
  }
  void split_and_merge(vector<int> &nums, int &result, int left, int right) {
    if (left == right) {
      return;
    }

    int mid = left + ((right - left) / 2);
    split_and_merge(nums, result, left, mid);
    split_and_merge(nums, result, mid + 1, right);
    merge(nums, left, right, mid, result);
  }
  int reversePairs(vector<int> &nums) {
    int result = 0;
    split_and_merge(nums, result, 0, nums.size() - 1);
    return result;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: modified merge sort — count qualifying cross-half pairs before
//   the merge step.
//
// Core Idea
//   Modified merge sort; count pairs where arr[i] > 2*arr[j] across halves
//   before merging
//
// Reference signature (Rust): fn reverse_pairs(nums: Vec<i32>) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/reverse-pairs/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/reverse-pairs/1

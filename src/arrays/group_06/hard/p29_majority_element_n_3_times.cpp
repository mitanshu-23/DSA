// Problem 29: Majority Element (> n/3 times)
//
// Difficulty: Hard
// Group:      6
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Return all elements that appear more than n/3 times (there can be at most
//   two).
//
//   Example 1:  nums = [3, 2, 3]           →  [3]
//   Example 2:  nums = [1,1,1,3,3,2,2,2]  →  [1, 2]
//
//   Constraints:
//     1 <= nums.length <= 5*10^4
//
// Problem Link
//   https://leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {

    int top = nums[0];
    int top_count = 1;
    // int indx = 1;

    // while (nums[indx] == top) {
    //   indx += 1;
    //   top_count += 1;
    //   if (indx == nums.size()) {
    //     return {top};
    //   }
    // }

    int second_top_count = 0;
    int second_top = 1000000001;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == top) {
        top_count++;
      } else if (nums[i] == second_top) {
        second_top_count++;
        if (second_top_count > top_count) {
          second_top = top;
          second_top_count = top_count;

          top = nums[i];
          top_count = second_top_count + 1;
        }
      } else {
        if (top_count == 0) {
          top = nums[i];
          top_count = 1;
        } else if (second_top_count == 0) {
          second_top_count = 1;
          second_top = nums[i];
        } else {
          second_top_count--;
          top_count--;
        }
      }
    }

    // cout << top << " " << top_count << endl;
    // cout << second_top << " " << second_top_count << endl;

    int max_1_cnt_final = 0;
    int max_2_cnt_final = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == top) {
        max_1_cnt_final++;
      }

      if (nums[i] == second_top) {
        max_2_cnt_final++;
      }
    }

    if (((max_1_cnt_final > (nums.size() / 3)) &&
         (max_2_cnt_final > (nums.size() / 3)))) {
      return {top, second_top};
    } else if (max_1_cnt_final > (nums.size() / 3)) {
      return {top};
    } else if ((max_2_cnt_final > (nums.size() / 3))) {
      return {second_top};
    }

    return {};
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: extended Boyer-Moore with two candidate/count slots; verify
//   both in a final pass.
//
// Core Idea
//   Extended Boyer-Moore with two candidates (at most two exceed n/3); verify
//   both at the end
//
// Reference signature (Rust): fn majority_element_n3(nums: Vec<i32>) ->
// Vec<i32> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/majority-element-ii/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/majority-vote/1

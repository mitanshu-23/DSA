// Problem 37: Count Inversions
//
// Difficulty: Hard
// Group:      11
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Count the inversions in arr[]: pairs (i, j) with i < j but arr[i] > arr[j].
//
//   Example 1:  arr = [2, 4, 1, 3, 5]  →  3   ((2,1),(4,1),(4,3))
//   Example 2:  arr = [5, 4, 3, 2, 1]  →  10
//
//   Constraints:
//     1 <= arr.length <= 10^5
//
// Problem Link
//   https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<pair<int, int>> merge(int left, int right, int mid,
                               vector<int> &result,
                               vector<pair<int, int>> &nums) {

    int l_ptr = left;
    int r_ptr = mid + 1;
    vector<pair<int, int>> merged;

    while (r_ptr <= right && l_ptr <= mid) {
      // remain to check for equality
      if (nums[l_ptr].first > nums[r_ptr].first) {
        result[nums[l_ptr].second] += (right - r_ptr + 1);

        merged.push_back(nums[l_ptr]);
        l_ptr += 1;
      } else {
        merged.push_back(nums[r_ptr]);
        r_ptr += 1;
      }
    }

    while (l_ptr <= mid) {
      merged.push_back(nums[l_ptr]);
      l_ptr += 1;
    }

    while (r_ptr <= right) {
      merged.push_back(nums[r_ptr]);
      r_ptr += 1;
    }

    for (int i = left; i <= right; i++) {
      nums[i] = merged[i - left];
    }

    return merged;
  }
  void split_and_merge(vector<pair<int, int>> &nums, int left_indx,
                       int right_indx, vector<int> &result) {

    if (left_indx == right_indx) {
      return;
    }

    int mid = left_indx + ((right_indx - left_indx) / 2);

    split_and_merge(nums, left_indx, mid, result);
    split_and_merge(nums, mid + 1, right_indx, result);

    merge(left_indx, right_indx, mid, result, nums);
  }

  vector<int> countSmaller(vector<int> &nums) {
    vector<pair<int, int>> dupNums;
    for (int i = 0; i < nums.size(); i++) {
      dupNums.push_back({nums[i], i});
    }
    vector<int> result(nums.size(), 0);
    split_and_merge(dupNums, 0, nums.size() - 1, result);

    return result;
  }

  // TLE
  vector<int> countSmallerv1(vector<int> &nums) {

    vector<int> dup_nums;
    vector<int> result;
    for (int i = nums.size() - 1; i >= 0; i--) {

      auto it = lower_bound(dup_nums.begin(), dup_nums.end(), nums[i]);
      int index = std::distance(dup_nums.begin(), it);
      result.push_back(index);
      dup_nums.push_back(nums[i]);
      sort(dup_nums.begin(), dup_nums.end());
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
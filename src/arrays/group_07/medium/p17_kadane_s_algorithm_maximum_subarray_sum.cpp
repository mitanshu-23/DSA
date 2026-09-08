// Problem 17: Kadane's Algorithm — Maximum Subarray Sum
//
// Difficulty: Medium
// Group:      7
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Return the largest sum of any contiguous subarray (at least one element).
//
//   Example 1:  nums = [-2,1,-3,4,-1,2,1,-5,4]  →  6   ([4,-1,2,1])
//   Example 2:  nums = [5, 4, -1, 7, 8]         →  23
//
//   Constraints:
//     1 <= nums.length <= 10^5
//     -10^4 <= nums[i] <= 10^4
//
// Problem Link
//   https://leetcode.com/problems/maximum-subarray/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int ans = *std::max_element(nums.begin(), nums.end());
    int curr_sum = 0;
    int z_exist = false;

    for (int i = 0; i < nums.size(); i++) {
      curr_sum += nums[i];
      if (curr_sum < 0) {
        curr_sum = std::max(0, nums[i]);
      } else {
        ans = std::max(ans, curr_sum);
      }
    }

    return ans;
  }

  int maxSubArray_dnq(vector<int> &nums) {
    int ans = *min_element(nums.begin(), nums.end());
    vector<int> result = helper(nums, 0, nums.size() - 1, ans);
    cout << result[0] << " " << result[1] << " " << ans;
  }

  vector<int> helper(vector<int> &nums, int start, int end, int &ans) {
    if (end == start) {
      ans = std::max(ans, nums[start]);
      return {nums[start], nums[start], nums[start]};
    }

    int mid = (end - start) / 2;
    vector<int> left_res = helper(nums, start, mid, ans);
    vector<int> right_res = helper(nums, mid + 1, end, ans);

    ans = std::max(ans, left_res[1] + right_res[0]);
    int curr = left_res[1] + right_res[0];

    return {std::max(left_res[2] + right_res[1], left_res[0]),
            std::max(left_res[1] + right_res[2], right_res[1]),
            left_res[2] + right_res[2]};
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: current = max(arr[i], current + arr[i]); track the global max
//   (Kadane).
//
// Core Idea
//   current = max(arr[i], current + arr[i]); track the global maximum
//
// Reference signature (Rust): fn max_sub_array(nums: Vec<i32>) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/maximum-subarray/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

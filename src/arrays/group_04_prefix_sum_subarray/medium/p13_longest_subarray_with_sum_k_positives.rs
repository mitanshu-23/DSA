//! # Problem 13: Longest Subarray with Sum K (Positives)
//!
//! **Difficulty:** Medium
//! **Group:**      Prefix Sum / Subarray
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given an array of POSITIVE integers and a target k, return the length of the longest subarray with sum k.
//!
//! Example 1:  arr = [2,3,5,1,9], k = 10  →  3   ([2,3,5])
//! Example 2:  arr = [1,1,1,1], k = 2      →  2
//!
//! Constraints:
//!   1 <= arr.length <= 10^5
//!   1 <= arr[i] <= 10^9
//!
//! ## Problem Link
//! <https://leetcode.com/problems/minimum-size-subarray-sum/>

#![allow(dead_code)]

use core::num;

pub struct Solution;

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut ans = None;
        let mut first_indx = 0;
        let mut curr_indx = 0;

        for ele in &nums {
            if *ele >= target {
                return 1;
            }

            sum += ele;

            if sum >= target {
                while curr_indx > first_indx && sum >= target {
                    ans = if ans.is_none() { Some(curr_indx + 1) } else { Some(std::cmp::min(ans.unwrap(), curr_indx - first_indx + 1)) };
                    sum -= nums[first_indx];
                    first_indx += 1;
                }
            }

            curr_indx += 1;
        }

        return if ans.is_none() { 0 } else { ans.unwrap() as i32 };
    }
}

// ─── Tests ────────────────────────────────────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        // TODO: Replace todo!() with a real assertion once implemented:
        // assert_eq!(Solution::your_method(input), expected);
        todo!()
    }
}

// ═══════════════════════════════════════════════════════════════════════════
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when you're stuck
// ═══════════════════════════════════════════════════════════════════════════
//
//  ## Hints
//  Key insight: all values positive → sliding window; grow to add, shrink from the left when sum exceeds k.
//
//  ## Core Idea
//  All values positive → sliding window: grow to add, shrink from the left when the sum exceeds k
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/minimum-size-subarray-sum/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

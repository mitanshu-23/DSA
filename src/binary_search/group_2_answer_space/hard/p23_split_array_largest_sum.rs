//! # Problem 23: Split Array — Largest Sum
//!
//! **Difficulty:** Hard
//! **Group:**      Binary Search on Answer Space
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given an integer array nums and an integer k, split nums into k non-empty subarrays
//! to minimise the largest subarray sum. Return that minimised largest sum.
//!
//! Example 1:  nums = [7, 2, 5, 10, 8],  k = 2  →  18  ([7,2,5] and [10,8])
//! Example 2:  nums = [1, 2, 3, 4, 5],   k = 2  →  9   ([1,2,3,4] and [5])
//!
//! Constraints:
//!   1 <= nums.length <= 1000
//!   0 <= nums[i] <= 10^6
//!   1 <= k <= min(50, nums.length)
//!
//! ## Problem Link
//! <https://leetcode.com/problems/split-array-largest-sum/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn split_array(nums: Vec<i32>, k: i32) -> i32 {
        let mut lo = *nums.iter().max().unwrap();
        let mut hi = nums.iter().sum();
        let mut candidate = hi;

        while lo <= hi {
            let mid = lo + ((hi - lo) / 2);

            if Self::sum_possible(&nums, k, mid) {
                hi = mid - 1;
                candidate = mid;
            } else {
                lo = mid + 1;
            }
        }

        candidate
    }

    fn sum_possible(nums: &Vec<i32>, k: i32, max_sum: i32) -> bool {
        let mut curr_sum = 0;
        let mut sub_arr = 1;

        for n in nums {
            curr_sum += *n;

            if curr_sum > max_sum {
                sub_arr += 1;
                curr_sum = *n;

                if sub_arr > k {
                    return false;
                }
            }
        }

        true
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
//  Note: this is the same pattern as Book Allocation — binary search on the answer.
//
//  ## Core Idea
//  Identical to Book Allocation; BS on max subarray sum; check if splits into at most k parts
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/split-array-largest-sum/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1

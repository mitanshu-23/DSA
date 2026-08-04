//! # Problem 18: Find the Smallest Divisor Given a Threshold
//!
//! **Difficulty:** Medium
//! **Group:**      2
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given an array of integers nums and an integer threshold, find the smallest divisor d such that
//! the sum of ceil(nums[i] / d) for all i is <= threshold.
//!
//! Example 1:  nums = [1, 2, 5, 9],  threshold = 6   →  5
//!   (d=5: ceil(1/5)+ceil(2/5)+ceil(5/5)+ceil(9/5) = 1+1+1+2 = 5 <= 6)
//! Example 2:  nums = [44, 22, 33, 11, 1],  threshold = 5  →  44
//!
//! Constraints:
//!   1 <= nums[i] <= 10^6
//!   nums.length <= threshold <= 10^6
//!
//! ## Problem Link
//! <https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn smallest_divisor(nums: Vec<i32>, threshold: i32) -> i32 {
        if threshold == nums.len() as i32 {
            return *nums.iter().max().unwrap();
        }

        let mut lo = 1;
        let mut hi = *nums.iter().max().unwrap() - 1;
        let mut candidate = hi;

        while lo <= hi {
            let mid = lo + ((hi - lo) / 2);

            if Self::possible(mid, &nums, threshold) {
                candidate = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        candidate
    }

    fn possible(mid: i32, nums: &Vec<i32>, threshold: i32) -> bool {
        let mut tot = 0;

        for num in nums {
            let is_ceil = if num % mid == 0 { true } else { false };
            tot += (num / mid) + if is_ceil { 0 } else { 1 };

            if tot > threshold {
                return false;
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
//  ## Core Idea
//  BS divisor in [1,max(nums)]; sum=sum(ceil(nums[i]/d)); find minimum d where sum<=threshold
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/find-the-smallest-divisor/1

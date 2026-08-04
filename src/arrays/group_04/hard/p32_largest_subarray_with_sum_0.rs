//! # Problem 32: Largest Subarray with Sum 0
//!
//! **Difficulty:** Hard
//! **Group:**      4
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given an array arr[] (may contain negatives), return the length of the longest subarray with sum 0.
//! 
//! Example 1:  arr = [15, -2, 2, -8, 1, 7, 10, 23]  →  5   ([-2,2,-8,1,7])
//! Example 2:  arr = [1, 2, 3]                       →  0
//! 
//! Constraints:
//!   1 <= arr.length <= 10^5
//!
//! ## Problem Link
//! <https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn max_len_zero_sum(arr: Vec<i32>) -> i32 {
        0
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
//  Key insight: prefix sum + hashmap of the FIRST index of each prefix; equal prefixes bound a zero-sum span.
//
//  ## Core Idea
//  Prefix sum + hashmap of first occurrence; equal prefixes bound a span that sums to 0
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

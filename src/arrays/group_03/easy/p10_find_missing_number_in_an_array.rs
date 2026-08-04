//! # Problem 10: Find Missing Number in an Array
//!
//! **Difficulty:** Easy
//! **Group:**      3
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given n distinct numbers taken from 0..n (exactly one missing), return the missing number.
//!
//! Example 1:  nums = [3, 0, 1]              →  2
//! Example 2:  nums = [9,6,4,2,3,5,7,0,1]    →  8
//!
//! Constraints:
//!   n == nums.length
//!   0 <= nums[i] <= n, all distinct.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/missing-number/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let all_xor = (1..=n).into_iter().reduce(|acc, e| acc ^ e).unwrap() as i32;

        let given_nums_xor = nums.into_iter().reduce(|acc, e| acc ^ e).unwrap();

        all_xor ^ given_nums_xor
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
//  Key insight: XOR all indices 0..n with all elements, or subtract the actual sum from n*(n+1)/2.
//
//  ## Core Idea
//  XOR all indices 0..n with all elements, or subtract the actual sum from n*(n+1)/2
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/missing-number/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

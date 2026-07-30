//! # Problem 12: Find the Number That Appears Once
//!
//! **Difficulty:** Easy
//! **Group:**      Missing / Duplicate / XOR
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Every element appears twice except one that appears once. Return the single one. O(n) time, O(1) space.
//!
//! Example 1:  nums = [2, 2, 1]        →  1
//! Example 2:  nums = [4, 1, 2, 1, 2]  →  4
//!
//! Constraints:
//!   1 <= nums.length <= 3*10^4
//!
//! ## Problem Link
//! <https://leetcode.com/problems/single-number/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.into_iter().reduce(|acc, x| acc ^ x).unwrap().to_owned()
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
//  Key insight: XOR of all elements — equal pairs cancel, leaving the unique value.
//
//  ## Core Idea
//  XOR every element; equal pairs cancel (a^a=0), leaving the unique value
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/single-number/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/element-appearing-once2552/1

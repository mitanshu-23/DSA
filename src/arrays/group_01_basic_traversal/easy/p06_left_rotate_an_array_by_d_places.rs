//! # Problem 06: Left Rotate an Array by D Places
//!
//! **Difficulty:** Easy
//! **Group:**      Basic Traversal & In-place
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Left-rotate the array by d places.
//!
//! Example 1:  arr = [1,2,3,4,5,6,7], d = 2  →  [3,4,5,6,7,1,2]
//! Example 2:  arr = [1,2,3], d = 4          →  [2,3,1]  (d may exceed n; use d % n)
//!
//! Constraints:
//!   1 <= arr.length <= 10^5
//!   0 <= d
//!
//! ## Problem Link
//! <https://leetcode.com/problems/rotate-array/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let len = nums.len();
        let k = k as usize % len;
        nums.reverse();
        nums[0..k].reverse();
        nums[k..len].reverse();
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
//  Key insight: reverse [0,d), reverse [d,n), then reverse the whole array. O(n) time, O(1) space.
//
//  ## Core Idea
//  Reversal trick: reverse [0,d), reverse [d,n), reverse the whole array; O(n) time O(1) space
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/rotate-array/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

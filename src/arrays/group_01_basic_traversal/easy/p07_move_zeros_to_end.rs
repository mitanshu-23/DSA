//! # Problem 07: Move Zeros to End
//!
//! **Difficulty:** Easy
//! **Group:**      Basic Traversal & In-place
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Move all zeros to the end while keeping the relative order of the non-zero elements. Do it in-place.
//! 
//! Example 1:  nums = [0,1,0,3,12]  →  [1,3,12,0,0]
//! Example 2:  nums = [0]            →  [0]
//! 
//! Constraints:
//!   1 <= nums.length <= 10^4
//!   -2^31 <= nums[i] <= 2^31 - 1
//!
//! ## Problem Link
//! <https://leetcode.com/problems/move-zeroes/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut zer_ptr = 0;
        let mut ptr = 0;

        while ptr < nums.len() {
            if nums[ptr] != 0 {
                nums[zer_ptr] = nums[ptr];
                nums[ptr] = 0;
                zer_ptr += 1;
            }

            ptr += 1;
        }
        
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
//  Two pointers: j finds the first zero, i the next non-zero after it, swap; both walk forward
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/move-zeroes/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

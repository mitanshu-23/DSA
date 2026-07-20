//! # Problem 01: Largest Element in an Array
//!
//! **Difficulty:** Easy
//! **Group:**      Basic Traversal & In-place
//! **Platform:**   ALL
//!
//! ## Problem Statement
//! Given an array arr[], return the largest element in it.
//!
//! Example 1:  arr = [3, 5, 1, 9, 2]  →  9
//! Example 2:  arr = [7]              →  7
//!
//! Constraints:
//!   1 <= arr.length <= 10^6
//!   -10^9 <= arr[i] <= 10^9
//!
//! ## Problem Link
//! <https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn largest_element(arr: Vec<i32>) -> i32 {
        let mut largest = std::i32::MIN;
        for ele in arr {
            largest = std::cmp::max(largest, ele);
        }

        largest
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
//  Single pass tracking the running maximum; O(n) time, O(1) space
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1

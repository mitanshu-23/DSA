//! # Problem 27: Kth Element of Two Sorted Arrays
//!
//! **Difficulty:** Hard
//! **Group:**      Binary Search on Answer Space
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given two sorted arrays arr1 and arr2 of sizes m and n, and an integer k (1-indexed),
//! return the kth smallest element in the merged sorted array.
//! 
//! Example 1:  arr1 = [2,3,6,7,9],  arr2 = [1,4,8,10],  k = 5  →  6
//! Example 2:  arr1 = [100,112,256,349,770],  arr2 = [72,86,113,119,265,445,893],  k = 7  →  256
//! 
//! Constraints:
//!   1 <= k <= m+n
//!   Both arrays are sorted.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/median-of-two-sorted-arrays/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn kth_element(arr1: Vec<i32>, arr2: Vec<i32>, k: i32) -> i32 {
        todo!()
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
//  Key insight: same binary search partition as Problem 26 but stop when the left
//  partition has exactly k elements.
//
//  ## Core Idea
//  BS cut on smaller array so combined left partition has exactly k elements; generalised median
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/median-of-two-sorted-arrays/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
//  - Coding Ninjas: https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164290

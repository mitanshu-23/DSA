//! # Problem 09: Find the Union of Two Sorted Arrays
//!
//! **Difficulty:** Easy
//! **Group:**      2
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given two sorted arrays a and b, return their union: all distinct elements in sorted order.
//! 
//! Example 1:  a = [1,2,3,4,5], b = [2,3,4,4,5,6]  →  [1,2,3,4,5,6]
//! Example 2:  a = [1,1,1], b = [1,1]              →  [1]
//! 
//! Constraints:
//!   1 <= a.length, b.length <= 10^5
//!   both arrays are sorted in non-decreasing order.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/intersection-of-two-arrays/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn find_union(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let mut ptr_1 = 0;
        let mut ptr_2 = 0;

        let mut ans = Vec::new();
        
        while ptr_1 < a.len() || ptr_2 < b.len() {
            if ptr_1 < a.len() && ptr_2 == b.len() {
                while ptr_1 < a.len() {
                    if Some(&a[ptr_1]) != ans.last() {
                        ans.push(a[ptr_1]);
                    }
                    ptr_1 += 1;
                }
            } else if ptr_1 == a.len() && ptr_2 < b.len() {
                while ptr_2 < b.len() {
                    if Some(&b[ptr_2]) != ans.last() {
                        ans.push(b[ptr_2]);
                    }
                    ptr_2 += 1;
                } 
            } else {
                if a[ptr_1] <= b[ptr_2] {
                    if Some(&a[ptr_1]) != ans.last() {
                        ans.push(a[ptr_1]);
                    }
                    ptr_1 += 1;
                } else {
                    if Some(&b[ptr_2]) != ans.last() {
                        ans.push(b[ptr_2]);
                    }
                    ptr_2 += 1;
                }
            }            
        }


        ans
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
//  Key insight: two-pointer merge; skip a value that equals the last one already added.
//
//  ## Core Idea
//  Two-pointer merge; advance the smaller side; skip a value equal to the last one added
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/intersection-of-two-arrays/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

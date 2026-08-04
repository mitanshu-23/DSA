//! # Problem 35: Merge Two Sorted Arrays Without Extra Space
//!
//! **Difficulty:** Hard
//! **Group:**      2
//! **Platform:**   LC
//!
//! ## Problem Statement
//! *(see problem link below)*
//!
//! ## Problem Link
//! <https://leetcode.com/problems/merge-sorted-array/>

#![allow(dead_code)]

use std::println;

pub struct Solution;

impl Solution {
    // pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
    //     let mut indx = 0;

    //     while indx as i32 < n {
    //         nums1[m as usize + indx] = nums2[indx];
    //         indx += 1;
    //     }

    //     nums1.sort();
    // }

    pub fn merge_optimal(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        // let mut indx = 0;
        let mut final_ptr = m + n - 1;
        let mut b_ptr = n - 1;
        let mut a_ptr = m - 1;

        while b_ptr >= 0 {
            if a_ptr < 0 {
                while b_ptr >= 0 {
                    nums1[final_ptr as usize] = nums2[b_ptr as usize];
                    b_ptr -= 1;
                    final_ptr -= 1;
                }
            } else {
                if nums1[a_ptr as usize] > nums2[b_ptr as usize] {
                    nums1[final_ptr as usize] = nums1[a_ptr as usize];
                    a_ptr -= 1;
                } else {
                    nums1[final_ptr as usize] = nums2[b_ptr as usize];
                    b_ptr -= 1;
                }
                final_ptr -= 1;
            }
        }

        println!("{:?}", nums1);
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
//  Gap method (shell-sort variant): gap=(m+n+1)/2, swap out-of-order pairs, halve the gap each round
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/merge-sorted-array/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115621/1

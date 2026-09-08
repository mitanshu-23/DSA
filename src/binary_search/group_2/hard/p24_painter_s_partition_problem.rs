//! # Problem 24: Painter's Partition Problem
//!
//! **Difficulty:** Hard
//! **Group:**      2
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given n boards of lengths boards[] and k painters, assign contiguous sections to painters
//! so that the maximum time any painter works is minimised.
//! Each painter paints at 1 unit of board per unit of time.
//!
//! Example 1:  boards = [10, 20, 30, 40],  k = 2  →  60
//!   (Painter 1: [10,20,30]=60, Painter 2: [40]=40; max=60)
//! Example 2:  boards = [10, 20, 30],  k = 3  →  30
//!
//! Constraints:
//!   1 <= k <= boards.length <= 10^5
//!   1 <= boards[i] <= 10^6
//!
//! ## Problem Link
//! <https://leetcode.com/problems/split-array-largest-sum/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn painter_partition(boards: Vec<i32>, k: i32) -> i32 {
        let mut lo = *boards.iter().max().unwrap();
        let mut hi = boards.iter().sum();
        let mut candidate = hi;

        while lo <= hi {
            let mid = lo + ((hi - lo) / 2);

            if Self::possible(&boards, k, mid) {
                candidate = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        candidate
    }

    fn possible(boards: &Vec<i32>, k: i32, max_len: i32) -> bool {
        let mut curr_len = 0;
        let mut curr_painter = 1;
        for b in boards {
            curr_len += b;

            if curr_len > max_len {
                curr_len = *b;
                curr_painter += 1;
                if curr_painter > k {
                    return false;
                }
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
//  ## Hints
//  Note: identical pattern to Book Allocation and Split Array Largest Sum.
//
//  ## Core Idea
//  Mirror of Book Allocation; minimise maximum time; assign contiguous boards to k painters
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/split-array-largest-sum/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
//  - Coding Ninjas: https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557

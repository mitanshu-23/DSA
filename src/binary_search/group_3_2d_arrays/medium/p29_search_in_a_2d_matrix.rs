//! # Problem 29: Search in a 2D Matrix
//!
//! **Difficulty:** Medium
//! **Group:**      Binary Search on 2D Arrays
//! **Platform:**   LC
//!
//! ## Problem Statement
//! You are given an m x n integer matrix with the following properties:
//!   - Each row is sorted in non-decreasing order.
//!   - The first integer of each row is greater than the last integer of the previous row.
//! Return true if target exists in the matrix.
//!
//! Example 1:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]],  target = 3   →  true
//! Example 2:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]],  target = 13  →  false
//!
//! Constraints:
//!   m, n >= 1
//!   -10^4 <= matrix[i][j], target <= 10^4
//!
//! ## Problem Link
//! <https://leetcode.com/problems/search-a-2d-matrix/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();

        let mut left = 0i32;
        let mut right = (m * n - 1) as i32;

        while left <= right {
            let mid = (left + ((right - left) / 2)) as usize;
            let row_indx = mid / n;
            let col_indx = mid % n;
            println!("{mid} {} {}", row_indx, col_indx);
            if matrix[row_indx][col_indx] == target {
                return true;
            } else if matrix[row_indx][col_indx] > target {
                right = mid as i32 - 1;
            } else {
                left = mid as i32 + 1;
            }
        }
        false
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
//  Key insight: the matrix is equivalent to a single sorted 1D array. Map virtual index i to (i/cols, i%cols).
//
//  ## Core Idea
//  Treat matrix as virtual 1D sorted array; map virtual index to (mid/cols, mid%cols)
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/search-a-2d-matrix/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1

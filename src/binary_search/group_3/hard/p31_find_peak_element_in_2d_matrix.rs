//! # Problem 31: Find Peak Element in 2D Matrix
//!
//! **Difficulty:** Hard
//! **Group:**      3
//! **Platform:**   LC
//!
//! ## Problem Statement
//! A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors
//! (left, right, top, bottom).
//! Given a 0-indexed m x n matrix mat, return the position of any peak element.
//! You must write an algorithm that runs in O(m log n) or O(n log m).
//!
//! Example 1:  mat = [[1,4],[3,2]]       →  [0,1]  (4 > 1,2; valid peak)
//! Example 2:  mat = [[10,20,15],[21,30,14],[7,16,32]]  →  [1,1]  (30 is a peak)
//!
//! Constraints:
//!   1 <= mat.length, mat[0].length <= 500
//!   No two adjacent cells are equal.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/find-a-peak-element-ii/>

#![allow(dead_code)]
pub struct Solution;

impl Solution {
    pub fn find_peak_grid(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let rows = mat.len();
        let cols = mat[0].len();

        let mut left = 0i32;
        let mut right = cols as i32 - 1;

        while left <= right {
            let mid = left + ((right - left) / 2);

            let mut row_n = 0;
            let mut max = std::i32::MIN;
            let mut left_move = false;
            while row_n < rows {
                let l_neighbour = if mid > 0 { mat[row_n][mid as usize - 1] } else { -1 };
                let r_neighbour = if mid < (cols as i32 - 1) { mat[row_n][mid as usize + 1] } else { -1 };
                let u_neighbour = if row_n > 0 { mat[row_n - 1][mid as usize] } else { -1 };
                let d_neighbour = if row_n < (rows - 1) { mat[row_n + 1][mid as usize] } else { -1 };
                let curr = mat[row_n][mid as usize];

                if (curr > l_neighbour) && (curr > r_neighbour) && (curr > d_neighbour) && (curr > u_neighbour) {
                    return vec![row_n as i32, mid as i32];
                } else {
                    if l_neighbour >= max && l_neighbour >= r_neighbour {
                        left_move = true;
                        max = l_neighbour
                    } else if r_neighbour >= max && r_neighbour >= l_neighbour {
                        left_move = false;
                        max = r_neighbour;
                    }
                }
                row_n += 1;
            }

            if left_move {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        vec![-1, -1]
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
//  BS on columns; for mid-col find row with global max; shift toward larger neighbour column
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/find-a-peak-element-ii/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/peak-element-in-2d-matrix/1

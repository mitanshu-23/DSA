//! # Problem 11: How Many Times Array Has Been Rotated
//!
//! **Difficulty:** Easy
//! **Group:**      Binary Search on 1D Arrays
//! **Platform:**   ALL
//!
//! ## Problem Statement
//! Given a sorted array that has been rotated k times (right rotation), find k.
//! k equals the index of the minimum element in the rotated array.
//! 
//! Example 1:  arr = [4, 5, 6, 7, 0, 1, 2]  →  4  (minimum 0 is at index 4)
//! Example 2:  arr = [1, 2, 3, 4, 5]        →  0  (not rotated)
//! Example 3:  arr = [3, 4, 5, 1, 2]        →  3  (minimum 1 is at index 3)
//! 
//! Constraints:
//!   All values are distinct.
//!   Array was originally sorted in ascending order.
//!
//! ## Problem Link
//! <https://www.geeksforgeeks.org/problems/rotation4723/1>
//!
//! ## All Links
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/rotation4723/1
//! - Coding Ninjas:  https://www.naukri.com/code360/problems/rotation_7449070
//!
//! ## Core Idea
//! Number of rotations equals index of the minimum element; reuse problem 10
//!
//! ## Your Approach
//! <!-- Write your approach / key observations here before coding -->
//!
//! ## Complexity
//! - **Time:**  O(?)
//! - **Space:** O(?)

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn how_many_times(arr: Vec<i32>) -> usize {
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

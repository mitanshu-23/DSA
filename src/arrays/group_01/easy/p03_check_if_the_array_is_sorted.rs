//! # Problem 03: Check if the Array is Sorted
//!
//! **Difficulty:** Easy
//! **Group:**      1
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given an array arr[], return true if it is sorted in non-decreasing order, else false.
//!
//! Example 1:  arr = [1, 2, 2, 3]  →  true
//! Example 2:  arr = [1, 3, 2]     →  false
//!
//! Constraints:
//!   1 <= arr.length <= 10^5
//!
//! ## Problem Link
//! <https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn check(arr: Vec<i32>) -> bool {
        let mut min_occur = false;
        let mut indx = 0;

        while indx < arr.len() {
            if (arr[indx] > arr[(indx + 1) % arr.len()]) {
                if min_occur {
                    return false;
                } else {
                    min_occur = true;
                }
            }

            indx += 1;
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
//  ## Core Idea
//  Scan adjacent pairs; if any arr[i] > arr[i+1] the array is not sorted
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1

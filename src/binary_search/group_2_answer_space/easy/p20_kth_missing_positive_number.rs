//! # Problem 20: Kth Missing Positive Number
//!
//! **Difficulty:** Easy
//! **Group:**      Binary Search on Answer Space
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given a strictly increasing array arr[] of positive integers and a positive integer k,
//! return the kth positive integer that is missing from the array.
//!
//! Example 1:  arr = [2, 3, 4, 7, 11],  k = 5  →  9
//!   (missing: 1, 5, 6, 8, 9 — 5th is 9)
//! Example 2:  arr = [1, 2, 3, 4],  k = 2  →  6
//!
//! Constraints:
//!   1 <= arr.length <= 1000
//!   1 <= k <= 1000
//!
//! ## Problem Link
//! <https://leetcode.com/problems/kth-missing-positive-number/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn find_kth_missing(arr: Vec<i32>, k: i32) -> i32 {
        let mut left = 0i32;
        let mut right = arr.len() as i32;
        let mut candidate = 0;

        while left <= right {
            let mid = left + ((right - left) / 2);
            println!("{mid}");

            if arr[mid as usize] == mid - 1 {
                left = mid + 1;
            } else {
                let diff = arr[mid as usize] - mid - 1;
                println!("Diff: {}", diff);
                if diff == k {
                    return arr[mid as usize];
                } else if diff < k {
                    left = mid + 1;
                    candidate = arr[mid as usize] + (k - diff);
                } else {
                    right = mid - 1;
                    candidate = arr[mid as usize] - diff + k;
                }
            }
        }

        candidate
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
//  Key insight: the count of positive integers missing before arr[i] is arr[i] - (i+1).
//  Binary search for the first index where this count >= k.
//
//  ## Core Idea
//  Missing before arr[i] = arr[i]-(i+1); find first index where that count >= k
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/kth-missing-positive-number/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/kth-missing-positive-number2913/1

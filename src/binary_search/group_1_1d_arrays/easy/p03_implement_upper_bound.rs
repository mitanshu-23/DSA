//! # Problem 03: Implement Upper Bound
//!
//! **Difficulty:** Easy
//! **Group:**      Binary Search on 1D Arrays
//! **Platform:**   GFG
//!
//! ## Problem Statement
//! Given a sorted array arr[] of size n and a value x, return the 0-based index of the first element strictly greater than x.
//! If every element is <= x, return n.
//!
//! Example 1:  arr = [1, 2, 4, 4, 7],  x = 4  →  4  (first index where arr[i] > 4)
//! Example 2:  arr = [1, 2, 4, 4, 7],  x = 0  →  0  (first index where arr[i] > 0)
//! Example 3:  arr = [1, 2, 4, 4, 7],  x = 7  →  5  (no element > 7, return n)
//!
//! Constraints:
//!   1 <= n <= 10^5
//!   arr is sorted in non-decreasing order.
//!
//! ## Problem Link
//! <https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1
//!
//! ## Core Idea
//! First index where arr[i] > x; similar to lower bound but condition is strictly greater
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
    pub fn upper_bound(nums: &[i32], x: i32) -> usize {
        // todo!()
        let n_len = nums.len();

        if nums[0] > x {
            return 0;
        }

        let mut left = 0;
        let mut right = n_len as i32 - 1;
        let mut candidate = n_len as i32;

        while left <= right {
            let mid = left + ((right - left) / 2);

            if nums[mid as usize] > x {
                candidate = std::cmp::min(candidate, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return candidate as usize;
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

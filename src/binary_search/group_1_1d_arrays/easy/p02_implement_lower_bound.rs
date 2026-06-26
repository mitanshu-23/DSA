//! # Problem 02: Implement Lower Bound
//!
//! **Difficulty:** Easy
//! **Group:**      Binary Search on 1D Arrays
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given a sorted array arr[] of size n and a value x, return the 0-based index of the first element >= x.
//! If every element is less than x, return n.
//!
//! Example 1:  arr = [1, 2, 4, 4, 7],  x = 4  →  2  (first index where arr[i] >= 4)
//! Example 2:  arr = [1, 2, 4, 4, 7],  x = 5  →  4  (first index where arr[i] >= 5)
//! Example 3:  arr = [1, 2, 4, 4, 7],  x = 8  →  5  (no element >= 8, return n)
//!
//! Constraints:
//!   1 <= n <= 10^5
//!   1 <= arr[i], x <= 10^9
//!   arr is sorted in non-decreasing order.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/search-insert-position/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/search-insert-position/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
//!
//! ## Core Idea
//! First index where arr[i] >= x; set hi=mid when condition met; track result
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
    pub fn lower_bound(nums: &[i32], x: i32) -> usize {
        let n_len = nums.len();

        if nums[n_len - 1] < x {
            return n_len;
        }

        let mut left = 0 as i32;
        let mut right = (n_len - 1) as i32;
        let mut candidate = n_len as i32;

        while left <= right {
            let mid = (left + ((left + right) / 2));

            if nums[mid as usize] >= x {
                candidate = std::cmp::min(candidate, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        candidate as usize
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

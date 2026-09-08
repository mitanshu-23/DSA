//! # Problem 01: Binary Search to Find X in Sorted Array
//!
//! **Difficulty:** Easy
//! **Group:**      1
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given an array of integers nums sorted in ascending order and an integer target, write an algorithm to determine if target exists in the array.
//! Return its index if found, or -1 if not found. You must write an algorithm with O(log n) runtime.
//!
//! Example 1:  nums = [-1, 0, 3, 5, 9, 12],  target = 9  →  4
//! Example 2:  nums = [-1, 0, 3, 5, 9, 12],  target = 2  →  -1
//!
//! Constraints:
//!   1 <= nums.length <= 10^4
//!   -10^4 < nums[i], target < 10^4
//!   All integers in nums are unique and sorted in ascending order.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/binary-search/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/binary-search/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/binary-search/
//!
//! ## Core Idea
//! Classic binary search — compare arr[mid] with target; shrink window each iteration
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
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut left = 0 as i32;
        let mut right = (nums.len() - 1) as i32;

        while left <= right {
            let mid = left + ((right - left) / 2);

            if nums[mid as usize] == target {
                return mid as i32;
            }

            if nums[mid as usize] > target {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        -1
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

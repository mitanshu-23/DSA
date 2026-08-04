//! # Problem 08: Search in Rotated Sorted Array I (No Duplicates)
//!
//! **Difficulty:** Medium
//! **Group:**      1
//! **Platform:**   LC
//!
//! ## Problem Statement
//! There is an integer array nums sorted in ascending order (with distinct values) that has been rotated at an unknown pivot.
//! Given nums and target, return the index of target or -1 if not found.
//! You must write an O(log n) algorithm.
//!
//! Example 1:  nums = [4, 5, 6, 7, 0, 1, 2],  target = 0  →  4
//! Example 2:  nums = [4, 5, 6, 7, 0, 1, 2],  target = 3  →  -1
//! Example 3:  nums = [1],                     target = 0  →  -1
//!
//! Key insight: at least one half of the array is always sorted.
//!
//! Constraints:
//!   1 <= nums.length <= 5000
//!   All values are distinct.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/search-in-rotated-sorted-array/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/search-in-rotated-sorted-array/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
//!
//! ## Core Idea
//! One half is always sorted; determine which; check if target lies there and move accordingly
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
        let n_len = nums.len();

        let mut left = 0;
        let mut right = n_len as i32 - 1;

        while left < right {
            let mid = left + ((right - left) / 2);

            if nums[mid as usize] > nums[right as usize] {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        let pivot = left;

        if target >= pivot && target <= nums[n_len - 1] {
            left = pivot;
            right = n_len as i32 - 1;

            while left < right {
                let mid = left + ((right - left) / 2);

                if nums[mid as usize] == target {
                    return mid;
                }

                if nums[mid as usize] < target {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        } else {
            right = pivot - 1;
            left = 0;

            while left < right {
                let mid = left + ((right - left) / 2);

                if nums[mid as usize] == target {
                    return mid;
                }

                if nums[mid as usize] < target {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
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

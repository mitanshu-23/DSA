//! # Problem 09: Search in Rotated Sorted Array II (With Duplicates)
//!
//! **Difficulty:** Medium
//! **Group:**      1
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Same as Problem 08 but nums may contain duplicates.
//! Return true if target exists, false otherwise.
//!
//! Example 1:  nums = [2, 5, 6, 0, 0, 1, 2],  target = 0  →  true
//! Example 2:  nums = [2, 5, 6, 0, 0, 1, 2],  target = 3  →  false
//!
//! Key insight: when arr[lo] == arr[mid] == arr[hi] you cannot determine which half is sorted;
//! do lo++, hi-- and retry.
//!
//! Constraints:
//!   1 <= nums.length <= 5000
//!   -10^4 <= nums[i], target <= 10^4
//!
//! ## Problem Link
//! <https://leetcode.com/problems/search-in-rotated-sorted-array-ii/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/search-in-rotated-array2624/1
//!
//! ## Core Idea
//! Duplicates cause ambiguity; when arr[lo]==arr[mid]==arr[hi] do lo++ hi-- and retry
//!
//! ## Your Approach
//! <!-- Write your approach / key observations here before coding -->
//!
//! ## Complexity
//! - **Time:**  O(?)
//! - **Space:** O(?)

#![allow(dead_code)]

use std::fmt::Alignment::Right;

pub struct Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        Self::solve_rotatd_search(&nums, 0, nums.len() as i32 - 1, target)
    }

    fn solve_rotatd_search(nums: &Vec<i32>, left: i32, right: i32, target: i32) -> bool {
        println!("{} {}", left, right);
        if left > right {
            return false;
        }

        let mid = left + ((right - left) / 2);

        if nums[mid as usize] == target {
            return true;
        }

        if nums[left as usize] < nums[mid as usize] {
            //left half is sorted
            if target >= nums[left as usize] && target < nums[mid as usize] {
                // binary search in left half
                Self::binary_search(&nums, left, mid, target)
            } else {
                // recursive search in right half
                Self::solve_rotatd_search(nums, mid + 1, right, target)
            }
        } else if nums[right as usize] > nums[mid as usize] {
            if target > nums[mid as usize] && target <= nums[right as usize] {
                // binary search in right half
                Self::binary_search(&nums, mid + 1, right, target)
            } else {
                // recursive search in left half
                Self::solve_rotatd_search(nums, left, mid - 1, target)
            }
        } else {
            // recursive search in both half
            Self::solve_rotatd_search(nums, left, mid - 1, target)
                || Self::solve_rotatd_search(nums, mid + 1, right, target)
        }
    }

    fn binary_search(nums: &Vec<i32>, mut left: i32, mut right: i32, target: i32) -> bool {
        println!("Binary Search {left} {right}");
        if left > right {
            return false;
        }

        while left <= right {
            let mid = left + ((right - left) / 2);

            if nums[mid as usize] == target {
                return true;
            }

            if nums[mid as usize] < target {
                left = mid + 1;
            } else {
                right = mid - 1;
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

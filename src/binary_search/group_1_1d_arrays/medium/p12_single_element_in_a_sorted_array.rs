//! # Problem 12: Single Element in a Sorted Array
//!
//! **Difficulty:** Medium
//! **Group:**      Binary Search on 1D Arrays
//! **Platform:**   LC
//!
//! ## Problem Statement
//! You are given a sorted array consisting of only integers where every element appears exactly twice,
//! except for one element which appears exactly once.
//! Return the single element. O(log n) time and O(1) space required.
//!
//! Example 1:  nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]  →  2
//! Example 2:  nums = [3, 3, 7, 7, 10, 11, 11]      →  10
//!
//! Key insight: before the single element, pairs occupy (even, odd) index slots;
//! after it, they occupy (odd, even) slots. Check if arr[mid] == arr[mid ^ 1].
//!
//! Constraints:
//!   1 <= nums.length <= 10^5
//!   Array is sorted.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/single-element-in-a-sorted-array/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/single-element-in-a-sorted-array/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1
//!
//! ## Core Idea
//! Pairs sit at even-odd index pairs; if arr[mid]==arr[mid^1] single is on the right else left
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
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let mut left = 0i32;
        let mut right = nums.len() as i32 - 1;

        while left < right {
            let mid = left + ((right - left) / 2);
            // println!("{} {} {}", left, right, mid);

            if nums[mid as usize - 1] != nums[mid as usize] && nums[mid as usize + 1] != nums[mid as usize] {
                return nums[mid as usize];
            }

            if mid % 2 == 0 {
                if nums[mid as usize + 1] != nums[mid as usize] {
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }
            } else {
                if nums[mid as usize - 1] != nums[mid as usize] {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        nums[left as usize]
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

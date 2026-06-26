//! # Problem 06: Find First and Last Occurrence
//!
//! **Difficulty:** Easy
//! **Group:**      Binary Search on 1D Arrays
//! **Platform:**   ALL
//!
//! ## Problem Statement
//! Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of target.
//! Return [-1, -1] if target is not present.
//! You must write an algorithm with O(log n) runtime.
//!
//! Example 1:  nums = [5, 7, 7, 8, 8, 10],  target = 8  →  [3, 4]
//! Example 2:  nums = [5, 7, 7, 8, 8, 10],  target = 6  →  [-1, -1]
//! Example 3:  nums = [],                    target = 0  →  [-1, -1]
//!
//! Constraints:
//!   0 <= nums.length <= 10^5
//!   -10^9 <= nums[i] <= 10^9
//!   nums is sorted in non-decreasing order.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
//!
//! ## Core Idea
//! Lower bound for first occurrence; upper_bound-1 for last; two independent binary searches
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
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let n_len = nums.len();

        if n_len == 0 || nums[n_len - 1] < target {
            return vec![-1, -1];
        }

        let mut left = 0 as i32;
        let mut right = n_len as i32 - 1;

        let mut left_candidate = -1;
        let mut right_candidate = -1;

        while left <= right {
            let mid = left + ((right - left) / 2);

            if nums[mid as usize] == target {
                left_candidate = mid;
                right = mid - 1;
                continue;
            }

            if nums[mid as usize] > target {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if left_candidate == -1 {
            return vec![left_candidate, -1];
        }

        if let Some(&l_right_candidate) = nums.get((left_candidate + 1) as usize) {
            if l_right_candidate == target {
                right_candidate = left_candidate + 1;
            }

            left = left_candidate + 1;
            right = n_len as i32 - 1;

            while left <= right {
                let mid = left + ((left - left) / 2);

                if nums[mid as usize] == target {
                    right_candidate = mid;
                    left = mid + 1;
                    continue;
                }

                if nums[mid as usize] > target {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        vec![left_candidate, right_candidate]
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

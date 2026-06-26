//! # Problem 13: Find Peak Element
//!
//! **Difficulty:** Medium
//! **Group:**      Binary Search on 1D Arrays
//! **Platform:**   LC
//!
//! ## Problem Statement
//! A peak element is an element that is strictly greater than its neighbors.
//! Given a 0-indexed integer array nums, find a peak element and return its index.
//! For boundary elements, consider nums[-1] = nums[n] = -infinity.
//! There may be multiple peaks; return any.
//! You must write an O(log n) algorithm.
//!
//! Example 1:  nums = [1, 2, 3, 1]          →  2
//! Example 2:  nums = [1, 2, 1, 3, 5, 6, 4] →  5  (or 1, both valid)
//!
//! Constraints:
//!   1 <= nums.length <= 1000
//!   nums[i] != nums[i+1] for all valid i
//!
//! ## Problem Link
//! <https://leetcode.com/problems/find-peak-element/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/find-peak-element/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/peak-element/1
//!
//! ## Core Idea
//! If arr[mid] < arr[mid+1] the peak is on the right; otherwise it is on the left or at mid
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
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = nums.len() as i32 - 1;

        while left < right {
            let mid = left + ((right - left) / 2);
            let mid_ele = nums[mid as usize];

            let mid_left = nums.get(mid as usize - 1);
            let mid_right = nums.get(mid as usize + 1);

            match (mid_left, mid_right) {
                (Some(mid_left), Some(mid_right)) => {
                    if *mid_left < mid_ele && *mid_right < mid_ele {
                        return mid;
                    }

                    if *mid_left < mid_ele {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                (None, Some(mid_right)) => {
                    if *mid_right < mid_ele {
                        return mid;
                    } else {
                        left = mid + 1;
                    }
                }
                (Some(mid_left), None) => {
                    if *mid_left < mid_ele {
                        return mid;
                    } else {
                        right = mid - 1;
                    }
                }
                _ => {}
            };
        }

        left
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

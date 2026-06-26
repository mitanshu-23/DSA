//! # Problem 07: Count Occurrences of a Number in Sorted Array
//!
//! **Difficulty:** Easy
//! **Group:**      Binary Search on 1D Arrays
//! **Platform:**   ALL
//!
//! ## Problem Statement
//! Given a sorted array arr[] and a target integer, count the number of times target appears in arr[].
//!
//! Example 1:  arr = [1, 1, 2, 2, 2, 3],  target = 2  →  3
//! Example 2:  arr = [1, 1, 2, 2, 2, 3],  target = 4  →  0
//!
//! Hint: count = last_occurrence_index - first_occurrence_index + 1.
//! Reuse your lower_bound / upper_bound implementations from problems 2 and 3.
//!
//! Constraints:
//!   1 <= arr.length <= 10^5
//!   arr is sorted in non-decreasing order.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
//!
//! ## Core Idea
//! count = last_occurrence - first_occurrence + 1; direct application of problem 6
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
    pub fn count_occurrences(nums: &[i32], target: i32) -> i32 {
        let n_len = nums.len();

        if n_len == 0 || nums[n_len - 1] < target {
            return 0;
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
            return 0;
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

        right_candidate - left_candidate + 1
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

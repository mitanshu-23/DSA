//! # Problem 10: Minimum in Rotated Sorted Array
//!
//! **Difficulty:** Medium
//! **Group:**      1
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
//! Find the minimum element. You must write an algorithm that runs in O(log n).
//!
//! Example 1:  nums = [3, 4, 5, 1, 2]     →  1
//! Example 2:  nums = [4, 5, 6, 7, 0, 1, 2]  →  0
//! Example 3:  nums = [11, 13, 15, 17]    →  11  (rotated 4 = 0 times)
//!
//! Constraints:
//!   n >= 1, all values are unique.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1
//!
//! ## Core Idea
//! Min is at the inflection point; sorted half leftmost is a candidate; move toward unsorted
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
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let mut left = 0i32;
        let mut right = nums.len() as i32 - 1;

        while left < right {
            if nums[left as usize] < nums[right as usize] {
                return nums[left as usize];
            }

            println!("{} {}", left, right);
            let mid = left + ((right - left) / 2);

            if nums[mid as usize] < nums[left as usize] {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left as usize];
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

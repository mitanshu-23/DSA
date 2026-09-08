//! # Problem 04: Search Insert Position
//!
//! **Difficulty:** Easy
//! **Group:**      1
//! **Platform:**   ALL
//!
//! ## Problem Statement
//! Given a sorted array of distinct integers and a target value, return the index if the target is found.
//! If not, return the index where it would be inserted to keep the array sorted.
//! You must write an algorithm with O(log n) runtime.
//!
//! Example 1:  nums = [1, 3, 5, 6],  target = 5  →  2
//! Example 2:  nums = [1, 3, 5, 6],  target = 2  →  1
//! Example 3:  nums = [1, 3, 5, 6],  target = 7  →  4
//!
//! Constraints:
//!   1 <= nums.length <= 10^4
//!   -10^4 <= nums[i] <= 10^4
//!   nums contains distinct values sorted in ascending order.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/search-insert-position/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/search-insert-position/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1
//!
//! ## Core Idea
//! Return index if found else insertion index — this is exactly the lower bound
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
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let n_len = nums.len();
        if target >= nums[n_len - 1] {
            return n_len as i32;
        }

        if target <= nums[0] {
            return 0;
        }

        let mut left = 0 as i32;
        let mut right = n_len as i32 - 1;
        let mut candidate = n_len as i32;

        // println!("{:?}", nums.binary_search(&target));

        while left <= right {
            let mid = left + ((right - left) / 2);

            if nums[mid as usize] == target {
                return mid;
            }

            if nums[mid as usize] >= target {
                candidate = std::cmp::min(mid, candidate);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return candidate;
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

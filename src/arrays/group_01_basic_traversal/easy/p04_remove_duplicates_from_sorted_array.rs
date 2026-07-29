//! # Problem 04: Remove Duplicates from Sorted Array
//!
//! **Difficulty:** Easy
//! **Group:**      Basic Traversal & In-place
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given a sorted array nums, remove duplicates in-place so each unique element appears once, keeping order.
//! Return k, the count of unique elements; the first k slots of nums must hold them.
//!
//! Example 1:  nums = [1, 1, 2]          →  2, nums = [1, 2, _]
//! Example 2:  nums = [0,0,1,1,1,2,2]   →  3, nums = [0, 1, 2, ...]
//!
//! Constraints:
//!   1 <= nums.length <= 3*10^4
//!   nums is sorted in non-decreasing order.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/remove-duplicates-from-sorted-array/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut indx = 1;
        let mut len = nums.len();
        let mut last_distinct = 0;

        while indx < len {
            while indx < len && (nums[indx] == nums[indx - 1] || nums[indx] < nums[last_distinct]) {
                indx += 1;
            }
            if indx < len {
                last_distinct += 1;
                nums[last_distinct] = nums[indx]
            }
        }

        last_distinct as i32 + 1
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

// ═══════════════════════════════════════════════════════════════════════════
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when you're stuck
// ═══════════════════════════════════════════════════════════════════════════
//
//  ## Core Idea
//  Two pointers: i is the write index, j scans; write when nums[j] != nums[i]
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1

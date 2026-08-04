//! # Problem 05: Floor and Ceil in Sorted Array
//!
//! **Difficulty:** Easy
//! **Group:**      1
//! **Platform:**   ALL
//!
//! ## Problem Statement
//! Given a sorted array arr[] and a value x, find:
//!   Floor  — the largest element in arr[] that is < x  (return -1 if none)
//!   Ceil   — the smallest element in arr[] that is >= x  (return -1 if none)
//!
//! Example 1:  arr = [1, 2, 8, 10, 10, 12, 19],  x = 5   →  floor = 2,  ceil = 8
//! Example 2:  arr = [1, 2, 8, 10, 10, 12, 19],  x = 20  →  floor = 19, ceil = -1
//! Example 3:  arr = [1, 2, 8, 10, 10, 12, 19],  x = 0   →  floor = -1, ceil = 1
//!
//! Constraints:
//!   1 <= arr.length <= 10^5
//!   arr is sorted in non-decreasing order.
//!
//! ## Problem Link
//! <https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1>
//!
//! ## All Links
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
//! - Coding Ninjas:  https://www.naukri.com/code360/problems/ceil-the-floor_893098
//!
//! ## Core Idea
//! Floor=largest<=x; Ceil=smallest>=x; both derivable from lower/upper bound templates
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
    pub fn floor(arr: &[i32], x: i32) -> i32 {
        // first find floor: as floor is expected to be last occurrence in case of multiple floors. Then obviously ceil is next to the floor.

        let n_len = arr.len();

        let mut left = 0 as i32;
        let mut right = n_len as i32 - 1;

        if arr[left as usize] > x {
            return -1;
        }

        let mut candidate = n_len as i32 - 1;
        while left <= right {
            let mid = left + ((right - left) / 2);

            if arr[mid as usize] > x {
                candidate = mid;
                right = mid - 1;
            } else if arr[mid as usize] == x {
                candidate = mid;
                left = mid + 1;
            } else {
                left = mid + 1;
            }
        }

        candidate
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

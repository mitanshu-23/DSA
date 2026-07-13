//! # Problem 26: Median of Two Sorted Arrays
//!
//! **Difficulty:** Hard
//! **Group:**      Binary Search on Answer Space
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given two sorted arrays nums1 and nums2 of sizes m and n, return the median of the two arrays.
//! Overall runtime must be O(log(min(m, n))).
//!
//! Example 1:  nums1 = [1, 3],  nums2 = [2]          →  2.0
//! Example 2:  nums1 = [1, 2],  nums2 = [3, 4]       →  2.5
//!
//! Constraints:
//!   nums1.length + nums2.length >= 1
//!   Both arrays are sorted.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/median-of-two-sorted-arrays/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn find_median_sorted_arrays(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> f64 {
        if nums1.len() > nums2.len() {
            let temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }

        let total_len = nums1.len() + nums2.len();
        let all_mid = (total_len + 1) / 2;

        let min_len = std::cmp::min(nums1.len(), nums2.len());

        let mut left = 0i32;
        let upper_limit = std::cmp::min(all_mid, min_len);
        let mut right = upper_limit as i32;

        println!("{} {} {}", left, right, all_mid);

        while left <= right {
            let nums1_left_ele_count = (left + ((right - left) / 2)) as usize;
            println!("{}", nums1_left_ele_count);
            let nums2_left_ele_count = all_mid - nums1_left_ele_count;

            let part_1_nums1 = if nums1_left_ele_count == 0 { &[] } else { &nums1[..nums1_left_ele_count] };
            let part_1_nums2 = if nums2_left_ele_count == 0 { &[] } else { &nums2[..nums2_left_ele_count] };

            let part_2_nums1 = if nums1_left_ele_count == nums1.len() { &[] } else { &nums1[nums1_left_ele_count..] };
            let part_2_nums2 = if nums2_left_ele_count == nums2.len() { &[] } else { &nums2[nums2_left_ele_count..] };

            println!("{} {} {:?} {:?} {:?} {:?}", nums1_left_ele_count, nums2_left_ele_count, part_1_nums1, part_1_nums2, part_2_nums1, part_2_nums2);

            let proceed = (part_1_nums1.last().unwrap_or(&std::i32::MIN) <= part_2_nums2.first().unwrap_or(&std::i32::MAX)) && (part_1_nums2.last().unwrap_or(&std::i32::MIN) <= part_2_nums1.first().unwrap_or(&std::i32::MAX));

            println!("Proceed : {proceed}");

            if proceed {
                let last = std::cmp::max(part_1_nums1.last().unwrap_or(&std::i32::MIN), part_1_nums2.last().unwrap_or(&std::i32::MIN));
                let first = std::cmp::min(part_2_nums1.first().unwrap_or(&std::i32::MAX), part_2_nums2.first().unwrap_or(&std::i32::MAX));
                println!("{} {} {} {}", nums1_left_ele_count, nums2_left_ele_count, last, first);
                if total_len % 2 == 0 {
                    return ((*last as f64) + (*first as f64)) / 2.0;
                } else {
                    return *last as f64;
                }
            } else if part_1_nums1.last().unwrap_or(&std::i32::MIN) > part_2_nums2.first().unwrap_or(&std::i32::MAX) {
                println!("Moving left..");
                right = nums1_left_ele_count as i32 - 1;
            } else {
                println!("Moving right...");
                left = nums1_left_ele_count as i32 + 1;
            }
        }

        0.0
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
//  ## Hints
//  Key insight: binary search a partition on the smaller array such that the
//  combined left partition has (m+n+1)/2 elements AND maxLeft1<=minRight2 AND maxLeft2<=minRight1.
//
//  ## Core Idea
//  BS partition on smaller array; ensure maxLeft1<=minRight2 and maxLeft2<=minRight1; O(log min)
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/median-of-two-sorted-arrays/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1

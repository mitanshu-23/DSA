//! # Problem 13 (variant): Minimum Size Subarray Sum — LeetCode 209
//!
//! **Difficulty:** Medium
//! **Group:**      4
//! **Platform:**   LC
//!
//! > NOTE: This is the closest LeetCode-available variant of sheet problem 13
//! > ("Longest Subarray with Sum K"), but it is a DIFFERENT question: it asks for
//! > the MINIMUM length of a subarray whose sum is >= target. The exact sheet
//! > problem is solved in the co-located
//! > `p13_longest_subarray_with_sum_k_positives.cpp` (GFG).
//!
//! ## Problem Statement
//! Given an array of positive integers `nums` and an integer `target`, return the
//! minimal length of a contiguous subarray whose sum is >= target. Return 0 if none.
//!
//! Example 1:  target = 7, nums = [2,3,1,2,4,3]      →  2   ([4,3])
//! Example 2:  target = 4, nums = [1,4,4]            →  1
//! Example 3:  target = 11, nums = [1,1,1,1,1,1,1,1] →  0
//!
//! Constraints:
//!   1 <= nums.length <= 10^5
//!   1 <= nums[i], target <= 10^4
//!
//! ## Problem Link
//! <https://leetcode.com/problems/minimum-size-subarray-sum/>

#![allow(dead_code)]

use core::num;

pub struct Solution;

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut ans = None;
        let mut first_indx = 0;
        let mut curr_indx = 0;

        for ele in &nums {
            if *ele >= target {
                return 1;
            }

            sum += ele;

            if sum >= target {
                while curr_indx > first_indx && sum >= target {
                    ans = if ans.is_none() { Some(curr_indx + 1) } else { Some(std::cmp::min(ans.unwrap(), curr_indx - first_indx + 1)) };
                    sum -= nums[first_indx];
                    first_indx += 1;
                }
            }

            curr_indx += 1;
        }

        return if ans.is_none() { 0 } else { ans.unwrap() as i32 };
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
//  Key insight: all values positive → sliding window; grow the window to add, then
//  shrink from the left while the sum stays >= target, tracking the minimum length.
//
//  ## Core Idea
//  Sliding window: expand right to reach sum >= target, then contract left as far as
//  the window still satisfies sum >= target; record the smallest width seen.
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/minimum-size-subarray-sum/

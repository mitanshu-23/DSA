//! # Problem 11: Maximum Consecutive Ones
//!
//! **Difficulty:** Easy
//! **Group:**      3
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given a binary array nums, return the maximum number of consecutive 1s.
//!
//! Example 1:  nums = [1,1,0,1,1,1]  →  3
//! Example 2:  nums = [1,0,1,1,0,1] →  2
//!
//! Constraints:
//!   1 <= nums.length <= 10^5
//!   nums[i] is 0 or 1.
//!
//! ## Problem Link
//! <https://leetcode.com/problems/max-consecutive-ones/>

#![allow(dead_code)]

pub struct Solution;

use std::cmp;

impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut cnt=0;
        for num in nums {
            if num == 0 {
                ans = cmp::max(ans, cnt);
                cnt = 0;
            }else{
                cnt+=1;
            }
        }

        cmp::max(ans,cnt)
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
//  Single scan: running count, reset to 0 on a zero, track the global max
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/max-consecutive-ones/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/maximum-consecutive-ones3234/1

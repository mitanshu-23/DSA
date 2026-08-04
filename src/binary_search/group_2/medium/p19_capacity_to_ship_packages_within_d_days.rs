//! # Problem 19: Capacity to Ship Packages Within D Days
//!
//! **Difficulty:** Medium
//! **Group:**      2
//! **Platform:**   LC
//!
//! ## Problem Statement
//! You are given an array weights where weights[i] is the weight of the ith package.
//! Packages must be loaded in order. Find the minimum weight capacity of a ship so that
//! all packages are shipped within days days.
//!
//! Example 1:  weights = [1,2,3,4,5,6,7,8,9,10],  days = 5  →  15
//! Example 2:  weights = [3,2,2,4,1,4],  days = 3  →  6
//! Example 3:  weights = [1,2,3,1,1],  days = 4   →  3
//!
//! Constraints:
//!   1 <= days <= weights.length <= 500
//!   1 <= weights[i] <= 500
//!
//! ## Problem Link
//! <https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn ship_within_days(weights: Vec<i32>, days: i32) -> i32 {
        let mut lo = *weights.iter().max().unwrap();
        let mut hi = weights.iter().sum();
        let mut candidate = hi;

        while lo <= hi {
            let mid = lo + ((hi - lo) / 2);

            if Self::possible(&weights, days, mid) {
                candidate = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        candidate
    }

    fn possible(weights: &Vec<i32>, days: i32, max_weight: i32) -> bool {
        let mut curr_weight = 0;
        let mut day = 1;
        for weight in weights {
            curr_weight += weight;

            if curr_weight > max_weight {
                curr_weight = *weight;
                day += 1;

                if day > days {
                    return false;
                }
            }
        }
        // println!("{} {}", max_weight, day);
        true
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
//  BS capacity in [max(weights),sum(weights)]; verify all packages ship within D days
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1

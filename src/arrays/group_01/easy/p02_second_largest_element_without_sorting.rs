//! # Problem 02: Second Largest Element Without Sorting
//!
//! **Difficulty:** Easy
//! **Group:**      1
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given an array arr[], return the second largest DISTINCT element, or -1 if it does not exist.
//!
//! Example 1:  arr = [12, 35, 1, 10, 34, 1]  →  34
//! Example 2:  arr = [10, 10, 10]            →  -1  (no distinct second largest)
//!
//! Constraints:
//!   1 <= arr.length <= 10^5
//!
//! ## Problem Link
//! <https://leetcode.com/problems/third-maximum-number/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn second_largest(arr: Vec<i32>) -> i32 {
        let mut largest = arr[0];
        let mut s_largest = None;
        let mut t_largest = None;

        for ele in arr {
            if ele > largest {
                if let Some(second) = s_largest {
                    t_largest = Some(second);
                }
                s_largest = Some(largest);
                largest = ele;
            } else if (ele != largest && s_largest.map(|sl| sl < ele).unwrap_or(true)) {
                if let Some(second) = s_largest {
                    t_largest = s_largest;
                }
                s_largest = Some(ele)
            } else if (ele != largest && (Some(ele) == s_largest) && t_largest.map(|tl| tl < ele).unwrap_or(true)) {
                t_largest = Some(ele);
            }
        }

        t_largest.unwrap_or(largest)
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
//  Key insight: track largest and second-largest in one pass; ignore values equal to the current largest.
//
//  ## Core Idea
//  Track largest and second-largest in one pass; the second must be strictly less than the largest
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/third-maximum-number/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/second-largest3735/1

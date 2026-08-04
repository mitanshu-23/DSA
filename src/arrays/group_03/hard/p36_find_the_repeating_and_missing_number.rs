//! # Problem 36: Find the Repeating and Missing Number
//!
//! **Difficulty:** Hard
//! **Group:**      3
//! **Platform:**   LC
//!
//! ## Problem Statement
//! The array arr[] of size n holds numbers from 1..n where one number repeats (twice) and one is missing.
//! Return [repeating, missing].
//!
//! Example 1:  arr = [3, 1, 2, 5, 3]  →  [3, 4]
//! Example 2:  arr = [1, 2, 2, 4]     →  [2, 3]
//!
//! Constraints:
//!   2 <= n <= 10^5
//!
//! ## Problem Link
//! <https://leetcode.com/problems/set-mismatch/>

#![allow(dead_code)]

use std::{println, vec};

pub struct Solution;

impl Solution {
    pub fn find_missing_repeating(arr: Vec<i32>) -> Vec<i32> {
        let given_nums_xor = arr.iter().fold(0, |acc, x| acc ^ x);
        let upto_n_xor = (1..=arr.len()).fold(0, |acc, x| acc ^ x as i32);
        let mut grp_1 = 0;
        let mut grp_2 = 0;
        let xor_ans = given_nums_xor ^ upto_n_xor;
        let mut first_set_bit = 0;
        for i in 0..32 {
            if (xor_ans & (1 << i)) != 0 {
                first_set_bit = i;
                break;
            }
        }

        // println!("{}", first_set_bit);

        for n in arr.iter() {
            if (n & (1 << first_set_bit)) != 0 {
                grp_1 ^= n;
            } else {
                grp_2 ^= n;
            }
        }

        for i in 1..=arr.len() {
            if (i & (1 << first_set_bit)) != 0 {
                grp_1 = grp_1 ^ i as i32;
            } else {
                grp_2 = grp_2 ^ i as i32;
            }
        }

        // println!("One of the number is: {grp_1}");
        // let ans_nums_xor = (1..=arr.len()).fold(given_nums_xor, |acc, x| acc ^ x as i32);

        // let w_o_ans_nums_xor = (1..=arr.len()).fold(ans_nums_xor, |acc, x| acc ^ x as i32);
        // let missing = w_o_ans_nums_xor ^ given_nums_xor;
        // let duplicate = ans_nums_xor ^ missing;

        // vec![duplicate, missing]
        if arr.iter().find(|x| **x == grp_1).is_some() {
            return vec![grp_1, grp_1 ^ xor_ans];
        }
        vec![grp_1 ^ xor_ans, grp_1]
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
//  Key insight: X = XOR of all elements with 1..n = repeat ^ missing; a differing bit separates the two.
//
//  ## Core Idea
//  XOR to get (repeat ^ missing), split by a set bit; or use sum and sum-of-squares equations
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/set-mismatch/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

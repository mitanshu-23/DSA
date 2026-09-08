//! # Problem 16: Koko Eating Bananas
//!
//! **Difficulty:** Medium
//! **Group:**      2
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Koko has n piles of bananas. The guards leave for h hours.
//! Each hour Koko picks one pile and eats up to k bananas from it. If the pile has < k bananas she eats all of them.
//! Find the minimum eating speed k (bananas/hour) such that she can eat all piles within h hours.
//!
//! Example 1:  piles = [3, 6, 7, 11],  h = 8   →  4
//! Example 2:  piles = [30, 11, 23, 4, 20],  h = 5   →  30
//! Example 3:  piles = [30, 11, 23, 4, 20],  h = 6   →  23
//!
//! Constraints:
//!   1 <= piles.length <= h
//!   1 <= piles[i] <= 10^9
//!
//! ## Problem Link
//! <https://leetcode.com/problems/koko-eating-bananas/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut lo = 1;
        let mut hi = *piles.iter().max().unwrap();
        let mut candidate = hi;

        while lo <= hi {
            let mid = lo + ((hi - lo) / 2);

            if Self::helper(&piles, mid, h) {
                candidate = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return candidate;
    }

    fn helper(piles: &Vec<i32>, k: i32, h: i32) -> bool {
        let mut curr_h = 0;
        for b in piles {
            let incomplete_h = if b % k == 0 { 0 } else { 1 };
            let req_h = (b / k) + incomplete_h;
            curr_h += req_h;
            if curr_h > h {
                return false;
            }
        }

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
//  BS on speed k in [1,max(piles)]; total=sum(ceil(pile/k)); find minimum k where total<=h
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/koko-eating-bananas/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

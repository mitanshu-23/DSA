//! # Problem 17: Minimum Days to Make M Bouquets
//!
//! **Difficulty:** Medium
//! **Group:**      Binary Search on Answer Space
//! **Platform:**   LC
//!
//! ## Problem Statement
//! You have n flowers. bloomDay[i] is the day flower i blooms.
//! To make one bouquet you need k adjacent bloomed flowers.
//! Return the minimum number of days needed to make m bouquets, or -1 if impossible.
//!
//! Example 1:  bloomDay = [1,10,3,10,2],  m = 3,  k = 1  →  3
//! Example 2:  bloomDay = [1,10,3,10,2],  m = 3,  k = 2  →  -1
//! Example 3:  bloomDay = [7,7,7,7,12,7,7],  m = 2,  k = 3  →  12
//!
//! Constraints:
//!   bloomDay.length == n
//!   1 <= n, m*k <= 10^9
//!   1 <= bloomDay[i] <= 10^9
//!
//! ## Problem Link
//! <https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn min_days(bloom_day: Vec<i32>, m: i32, k: i32) -> i32 {
        let mut lo = 1;
        let mut hi = *bloom_day.iter().max().unwrap();
        let mut candidate = -1;

        if (bloom_day.len() as i32) < (k * m) {
            return -1;
        }

        while lo <= hi {
            let mid = lo + ((hi - lo) / 2);
            // println!("{mid}");
            if Self::possible(&bloom_day, m, k, mid) {
                candidate = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        candidate
    }

    fn possible(bloom_day: &Vec<i32>, m: i32, k: i32, mid: i32) -> bool {
        let mut indx = 0;
        let mut current_k = 0;
        let mut tot_bloom = 0;

        while indx < bloom_day.len() {
            // If current bloom required days is greater than expected skip the streak
            if bloom_day[indx] > mid {
                current_k = 0;
            } else {
                // Take the current flower and attach to bouquet
                current_k += 1;

                if current_k == k {
                    // println!("bloomed flower: {}, mid: {mid}", indx);
                    tot_bloom += 1;
                    current_k = 0;
                }
            }

            if tot_bloom == m {
                return true;
            }

            indx += 1;
        }

        false
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
//  BS on day in [min,max](bloomDay); check if m bouquets of k consecutive bloomed flowers possible
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1

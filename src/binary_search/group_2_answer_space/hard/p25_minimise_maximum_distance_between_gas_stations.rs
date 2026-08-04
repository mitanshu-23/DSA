//! # Problem 25: Minimise Maximum Distance Between Gas Stations
//!
//! **Difficulty:** Hard
//! **Group:**      Binary Search on Answer Space
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given a sorted array of gas station positions along a highway and an integer k,
//! add k additional gas stations to minimise the maximum distance between any two adjacent stations.
//! Return the answer within an error of 10^-6.
//!
//! Example 1:  stations = [1,2,3,4,5,6,7,8,9,10],  k = 9  →  0.500000
//! Example 2:  stations = [23,24,36,39,46,56,57,65,84,98],  k = 1  →  14.000000
//!
//! Constraints:
//!   10 <= stations.length <= 2000
//!   0 <= stations[i] <= 10^8
//!   stations is sorted in increasing order
//!   1 <= k <= 10^6
//!
//! ## Problem Link
//! <https://leetcode.com/problems/minimize-max-distance-to-gas-station/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn min_max_gas_dist(stations: Vec<i32>, k: i32) -> f64 {
        let mut max_heap = std::collections::BinaryHeap::new();

        let mut dist = 0;
        let mut curr_indx = 1;

        while curr_indx < stations.len() {
            dist = stations[curr_indx] - stations[curr_indx - 1];
            max_heap.push((dist as f64).to_bits());
            curr_indx += 1;
        }

        let mut added = 0;

        while added < k {
            added += 1;
            let top = f64::from_bits(max_heap.pop().unwrap());
            let half = (top / 2.0).to_bits();
            max_heap.push(half);
            max_heap.push(half);
        }

        f64::from_bits(max_heap.pop().unwrap())
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
//  Floating-point BS on max gap d; count extra stations needed for each gap; stop when count<=k
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/minimize-max-distance-to-gas-station/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

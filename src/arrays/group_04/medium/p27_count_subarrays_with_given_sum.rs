//! # Problem 27: Count Subarrays with Given Sum
//!
//! **Difficulty:** Medium
//! **Group:**      4
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given an array nums and integer k, return the total number of contiguous subarrays whose sum equals k.
//!
//! Example 1:  nums = [1, 1, 1], k = 2   →  2
//! Example 2:  nums = [1, 2, 3], k = 3   →  2
//!
//! Constraints:
//!   1 <= nums.length <= 2*10^4
//!   -1000 <= nums[i] <= 1000
//!
//! ## Problem Link
//! <https://leetcode.com/problems/subarray-sum-equals-k/>

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut prefix_sum = Vec::new();
        let mut prefix_map = std::collections::HashMap::new();
        let mut sum = 0;
        let mut ans = 0;

        for ele in nums {
            sum += ele;
            prefix_sum.push(sum);
        }

        for ps in prefix_sum {
            let req = ps - k;
            if let Some(pre_req_sums) = prefix_map.get(&req) {
                ans += pre_req_sums;
            }

            *prefix_map.entry(req).or_insert(0) += 1;
        }

        ans
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
//  Key insight: prefix sum + hashmap of prefix->count; at each index add the count of (prefix - k) seen so far.
//
//  ## Core Idea
//  Prefix sum + hashmap of counts; at each index add the count of (prefix - k) seen so far
//
//  ## Your Approach
//  (write your approach / key observations here before coding)
//
//  ## Complexity
//  - Time:  O(?)
//  - Space: O(?)
//
//  ## All Links
//  - LeetCode:      https://leetcode.com/problems/subarray-sum-equals-k/
//  - GeeksForGeeks: https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

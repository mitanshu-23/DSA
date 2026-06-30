//! # Problem 14: Find Square Root of a Number (Floor)
//!
//! **Difficulty:** Easy
//! **Group:**      Binary Search on Answer Space
//! **Platform:**   LC
//!
//! ## Problem Statement
//! Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
//! The returned integer should be non-negative.
//! Do not use any built-in exponent function or operator (e.g. pow(x, 0.5) or x ** 0.5).
//!
//! Example 1:  x = 4   →  2
//! Example 2:  x = 8   →  2  (sqrt(8) ≈ 2.82, floor = 2)
//!
//! Constraints:
//!   0 <= x <= 2^31 - 1
//!
//! ## Problem Link
//! <https://leetcode.com/problems/sqrtx/>
//!
//! ## All Links
//! - LeetCode:       https://leetcode.com/problems/sqrtx/
//! - GeeksForGeeks:  https://www.geeksforgeeks.org/problems/square-root/1
//!
//! ## Core Idea
//! BS in [1,n]; if mid*mid<=n it is a candidate; move lo=mid+1; answer is hi at the end
//!
//! ## Your Approach
//! <!-- Write your approach / key observations here before coding -->
//!
//! ## Complexity
//! - **Time:**  O(?)
//! - **Space:** O(?)

#![allow(dead_code)]

pub struct Solution;

impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut lo = 0;
        let mut hi = x;
        let mut candidate = lo;

        while lo <= hi {
            let mid = (lo + ((hi - lo) / 2)) as u64;
            // println!("lo: {}, hi: {}, mid: {}", lo, hi, mid);

            if mid * mid == x as u64 {
                return mid as i32;
            }

            if (mid * mid) > x as u64 {
                hi = mid as i32 - 1;
            } else {
                candidate = mid as i32;
                lo = mid as i32 + 1;
            }
        }

        return candidate;
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

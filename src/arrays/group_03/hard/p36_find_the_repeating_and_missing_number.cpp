// Problem 36: Find the Repeating and Missing Number
//
// Difficulty: Hard
// Group:      3
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   The array arr[] of size n holds numbers from 1..n where one number repeats (twice) and one is missing.
//   Return [repeating, missing].
//   
//   Example 1:  arr = [3, 1, 2, 5, 3]  →  [3, 4]
//   Example 2:  arr = [1, 2, 2, 4]     →  [2, 3]
//   
//   Constraints:
//     2 <= n <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution {
public:
    // TODO: implement
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: X = XOR of all elements with 1..n = repeat ^ missing; a differing bit separates the two.
//
// Core Idea
//   XOR to get (repeat ^ missing), split by a set bit; or use sum and sum-of-squares equations
//
// Reference signature (Rust): fn find_missing_repeating(arr: Vec<i32>) -> Vec<i32>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/set-mismatch/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

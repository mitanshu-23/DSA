// Problem 15: Find the Nth Root of a Number
//
// Difficulty: Easy
// Group:      2
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given two numbers n and m, find the nth root of m.
//   If m does not have a perfect integer nth root, return -1.
//
//   Example 1:  n = 2, m = 9   →  3   (3^2 = 9)
//   Example 2:  n = 3, m = 27  →  3   (3^3 = 27)
//   Example 3:  n = 2, m = 5   →  -1  (no integer whose square is 5)
//
//   Hint: binary search in [1, m]; use a helper that computes mid^n carefully to avoid overflow.
//
//   Constraints:
//     1 <= n <= 30
//     1 <= m <= 10^
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
//
// All Links
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
//   Coding Ninjas: https://www.naukri.com/code360/problems/nth-root-of-m_1062679
//
// Core Idea
//   BS in [1,m]; helper computes mid^n and returns -1/0/1 for too-large/exact/too-small
//
// Reference signature (Rust): fn nth_root(n: u32, m: u64) -> i64
// Complexity — Time: O(?)  Space: O(?)

class Solution
{
public:
    int nthRoot(int n, int m)
    {
        // Code here
    }
};

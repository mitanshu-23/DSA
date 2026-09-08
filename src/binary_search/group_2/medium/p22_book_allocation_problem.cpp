// Problem 22: Book Allocation Problem
//
// Difficulty: Medium
// Group:      2
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given an array pages[] where pages[i] = pages in book i, and m students,
//   allocate all books to students such that:
//     - Each student gets a contiguous sequence of books.
//     - Every book is allocated to exactly one student.
//     - The maximum pages assigned to any student is minimised.
//   Return -1 if allocation is impossible (m > number of books).
//   
//   Example 1:  pages = [12, 34, 67, 90],  m = 2  →  113
//     (Student 1: [12,34,67]=113, Student 2: [90]=90; max=113)
//   Example 2:  pages = [15, 17, 20],  m = 2  →  32
//   
//   Constraints:
//     1 <= pages.length <= 10^5
//     1 <= pages[i] <= 10^3
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
class Solution {
    bool possible(vector<int> &arr, int k, long long pages) {  // long long here
        int students = 1;
        long long curr_page = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            if (arr[i] > pages) return false;
            if (curr_page + arr[i] <= pages) {
                curr_page += arr[i];
            } else {
                students++;
                curr_page = arr[i];
                if (students > k) return false;
            }
        }
        return true;
    }
public:
    int findPages(vector<int> &arr, int k) {
        if ((int)arr.size() < k) return -1;

        long long lo = *max_element(arr.begin(), arr.end());
        long long hi = accumulate(arr.begin(), arr.end(), 0LL);  // 0LL, not 0

        if ((int)arr.size() == k) return lo;
        if (k == 1) return hi;

        long long candidate = -1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (possible(arr, k, mid)) {
                candidate = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return (int)candidate;
    }
};
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Core Idea
//   BS on max pages in [max(pages),sum(pages)]; greedily assign contiguous books to m students
//
// Reference signature (Rust): fn allocate_books(pages: Vec<i32>, m: i32) -> i32
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
//   Coding Ninjas: https://www.naukri.com/code360/problems/allocate-books_1090540

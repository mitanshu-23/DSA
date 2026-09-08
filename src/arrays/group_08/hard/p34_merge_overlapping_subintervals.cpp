// Problem 34: Merge Overlapping Subintervals
//
// Difficulty: Hard
// Group:      8
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given a list of intervals [start, end], merge all overlapping intervals and
//   return the result.
//
//   Example 1:  intervals = [[1,3],[2,6],[8,10],[15,18]]  →
//   [[1,6],[8,10],[15,18]] Example 2:  intervals = [[1,4],[4,5]] →  [[1,5]]
//
//   Constraints:
//     1 <= intervals.length <= 10^4
//
// Problem Link
//   https://leetcode.com/problems/merge-intervals/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      vector<int> last = result.back();
      if (last[1] >= intervals[i][0]) {
        result[result.size() - 1][1] = std::max(last[1], intervals[i][1]);
      } else {
        result.push_back(intervals[i]);
      }
    }

    return result;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: sort by start; extend the last kept interval when it overlaps,
//   else start a new one.
//
// Core Idea
//   Sort by start; if the next interval overlaps the last kept one extend its
//   end, else push a new one
//
// Reference signature (Rust): fn merge_intervals(intervals: Vec<Vec<i32>>) ->
// Vec<Vec<i32>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/merge-intervals/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

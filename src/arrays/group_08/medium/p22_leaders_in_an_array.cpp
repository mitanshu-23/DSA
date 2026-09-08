// Problem 22: Leaders in an Array
//
// Difficulty: Medium
// Group:      8
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   An element is a leader if it is greater than every element to its right
//   (the last element is always a leader). Return all leaders, left to right.
//
//   Example 1:  arr = [16, 17, 4, 3, 5, 2]  →  [17, 5, 2]
//   Example 2:  arr = [1, 2, 3, 4]           →  [4]
//
//   Constraints:
//     1 <= arr.length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> leaders(vector<int> &arr) {
    // code here
    vector<int> ans;
    int indx = arr.size() - 2;
    ans.push_back(arr[indx + 1]);
    int greatest = arr[indx + 1];

    while (indx >= 0) {
      if (arr[indx] > greatest) {
        ans.push_back(arr[indx]);
        greatest = arr[indx];
      }
      indx -= 1;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: scan from the right keeping a running max.
//
// Core Idea
//   Scan from the right keeping a running max; a leader is greater than
//   everything to its right
//
// Reference signature (Rust): fn leaders(arr: Vec<i32>) -> Vec<i32>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

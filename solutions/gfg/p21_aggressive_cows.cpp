// Problem 21: Aggressive Cows
//
// Difficulty: Medium
// Group:      Binary Search on Answer Space
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given n stall positions (not necessarily sorted) and an integer k
//   representing the number of cows, place k cows in the stalls such that the
//   minimum distance between any two cows is maximised. Return that maximum
//   minimum distance.
//
//   Example 1:  stalls = [0, 3, 4, 7, 10, 9],  k = 4  →  3
//   Example 2:  stalls = [4, 2, 1, 3, 6],  k = 2  →  5
//
//   Constraints:
//     2 <= k <= n <= 10^5
//     0 <= stalls[i] <= 10^9
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/aggressive-cows/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool check(vector<int> &arr, int k, int dist) {
    int curr_dist = 0;
    int last_place = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      if ((arr[i] - last_place) >= dist) {
        k--;
        last_place = arr[i];
      }

      if (k == 0) {
        return true;
      }
    }
    return false;
  }

public:
  int aggressiveCows(vector<int> &arr, int k) {
    // code here
    sort(arr.begin(), arr.end());

    int len = arr.size();
    int lo = 0;
    int hi = arr[len - 1] - arr[0];
    int candidate = lo;

    if (k == 2) {
      return hi;
    }

    while (lo <= hi) {
      int mid = lo + ((hi - lo) / 2);

      if (check(arr, k, mid)) {
        candidate = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return candidate;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Core Idea
//   BS on min distance in [1,max-min stalls]; greedily check if all c cows can
//   be placed
//
// Reference signature (Rust): fn aggressive_cows(stalls: Vec<i32>, k: i32) ->
// i32 Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/aggressive-cows/1
//   Coding Ninjas:
//   https://www.naukri.com/code360/problems/aggressive-cows_1082559

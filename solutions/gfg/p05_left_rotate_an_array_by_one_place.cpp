// Problem 05: Left Rotate an Array by One Place
//
// Difficulty: Easy
// Group:      Basic Traversal & In-place
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Left-rotate the array by one place: each element moves one index left and
//   the first wraps to the end.
//
//   Example 1:  arr = [1, 2, 3, 4, 5]  →  [2, 3, 4, 5, 1]
//   Example 2:  arr = [9]              →  [9]
//
//   Constraints:
//     1 <= arr.length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void rotate(vector<int> &arr) {
    // code here
    int last = arr[arr.size() - 1];
    arr.pop_back();
    // 		debug(arr);
    std::reverse(arr.begin(), arr.end());
    arr.push_back(last);
    std::reverse(arr.begin(), arr.end());

    // while (indx < arr.size()) {
    //     int temp = arr[indx];
    //     arr[indx] = last;
    //     last = temp;
    //     indx++;
    // }

    // arr[0] = last;
  }

  void debug(vector<int> &vec) {
    for (int x : vec)
      std::cout << x << " ";
    cout << endl;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Core Idea
//   Store arr[0], shift everything left by one, place the stored value at the
//   end
//
// Reference signature (Rust): fn rotate_by_one(arr: &mut Vec<i32>)
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

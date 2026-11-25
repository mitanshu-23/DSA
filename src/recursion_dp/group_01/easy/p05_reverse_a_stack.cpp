// Problem 05: Reverse a Stack
//
// Difficulty: Easy
// Group:      1
// Platform:   ALL
// Language:   C++
//
// Problem Statement
//   Reverse a stack using recursion only — no loops and no additional data
//   structure besides the call stack.
//
//   Example 1:  stack (bottom→top) = [1,2,3,4]  →  [4,3,2,1]
//   Example 2:  stack = [5]                    →  [5]
//
//
// Problem Link
//   N/A

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // TODO: implement
  void reverse_stack(stack<int> &stack) {
    if (stack.size() == 0) {
      return;
    }
    int last = stack.top();
    stack.pop();
    reverse_stack(stack);
    insert_bottom(last, stack);
  }
  void insert_bottom(int last, stack<int> &stk) {
    if (stk.empty()) {
      stk.push(last);
      return;
    }
    int current = stk.top();
    stk.pop();
    insert_bottom(last, stk);
    stk.push(current);
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: pop the top, reverse the rest recursively, then insert the
//   popped element at the bottom with a second recursive helper.
//
// Core Idea
//   Pop the top, recursively reverse the rest, then insert the popped element
//   at the bottom via a second small recursion
//
// Reference signature (Rust): fn reverse_stack(stack: &mut Vec<i32>)
// Complexity — Time: O(?)  Space: O(?)
//
// All Links

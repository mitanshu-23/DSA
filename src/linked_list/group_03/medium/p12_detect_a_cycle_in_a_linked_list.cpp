// Problem 12: Detect a Cycle in a Linked List
//
// Difficulty: Medium
// Group:      3
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list, determine if it has a cycle (some node's
//   next eventually points back to a previously visited node).
//
//   Example 1:  list = [3,2,0,-4], tail connects to node index 1  →  true
//   Example 2:  list = [1,2], no cycle                              →  false
//
//   Constraints:
//     0 <= length <= 10^4
//
// Problem Link
//   https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>
using namespace std;

// /*
//   Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        return true;
      }
    }

    return false;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: Floyd's algorithm — a slow and a fast pointer must eventually
//   meet if the list has a cycle.
//
// Core Idea
//   Floyd's: slow and fast pointers necessarily meet somewhere inside the cycle
//   if one exists
//
// Reference signature (Rust): fn has_cycle(head: Option<Box<ListNode>>) -> bool
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/linked-list-cycle/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

// Problem 13: Find the Starting Point of a Cycle
//
// Difficulty: Medium
// Group:      3
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list that may contain a cycle, return the node
//   where the cycle begins, or None if there is no cycle.
//
//   Example 1:  list = [3,2,0,-4], tail connects to node index 1  →  the node
//   with val 2 Example 2:  list = [1], no cycle →  None
//
//   Constraints:
//     0 <= length <= 10^4
//
// Problem Link
//   https://leetcode.com/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        ListNode *temp = head;
        while (temp != slow) {
          temp = temp->next;
          slow = slow->next;
        }
        return temp;
      }
    }

    return nullptr;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: after Floyd's phase-1 meeting point, resetting one pointer to
//   head and advancing both by 1 step makes them meet exactly at the cycle's
//   entry.
//
// Core Idea
//   After Floyd's phase-1 meeting point, move one pointer back to head; both
//   advance 1 step and meet at the entry
//
// Reference signature (Rust): fn detect_cycle_start(head:
// Option<Box<ListNode>>) -> Option<Box<ListNode>> Complexity — Time: O(?)
// Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/linked-list-cycle-ii/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

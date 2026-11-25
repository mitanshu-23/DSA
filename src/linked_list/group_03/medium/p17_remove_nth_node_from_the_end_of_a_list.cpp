// Problem 17: Remove Nth Node from the End of a List
//
// Difficulty: Medium
// Group:      3
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list, remove the nth node from the end of the
//   list and return its head.
//
//   Example 1:  list = [1,2,3,4,5], n = 2  →  [1,2,3,5]
//   Example 2:  list = [1], n = 1           →  []
//
//   Constraints:
//     1 <= n <= length of the list
//
// Problem Link
//   https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <bits/stdc++.h>
using namespace std;

// /**
//   Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {

    ListNode *temp = head;
    int len = 0;
    // Cover first (n) nodes
    while (len < n) {
      len++;
      temp = temp->next;
    }

    // If list is already of size n -> first node is nth from the end
    if (temp == nullptr) {
      return head->next;
    }

    ListNode *prev = head;
    // Move previous ahead along with temp to maintain nth from end
    while (temp->next != nullptr) {
      temp = temp->next;
      prev = prev->next;
    }

    prev->next = prev->next->next;
    return head;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: move a fast pointer n steps ahead of slow, then advance both
//   together until fast falls off the end; slow then sits just before the
//   target. A dummy head cleanly handles removing the actual head.
//
// Core Idea
//   Move fast n steps ahead of slow, then advance both together until fast
//   falls off the end
//
// Reference signature (Rust): fn remove_nth_from_end(head:
// Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> Complexity — Time:
// O(?)  Space: O(?)
//
// All Links
//   LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

// Problem 10: Reverse a Linked List (Iterative)
//
// Difficulty: Medium
// Group:      4
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a singly linked list, reverse the list iteratively and
//   return the new head.
//
//   Example 1:  list = [1,2,3,4,5]  →  [5,4,3,2,1]
//   Example 2:  list = [1,2]         →  [2,1]
//
//   Constraints:
//     0 <= length <= 5000
//
// Problem Link
//   https://leetcode.com/problems/reverse-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *third = nullptr;
    ListNode *curr = head->next;
    ListNode *last_seen = head;

    while (curr != nullptr) {
      third = curr->next;
      curr->next = last_seen;
      last_seen = curr;
      curr = third;
    }
    head->next = nullptr;
    return last_seen;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: three-pointer iterative reversal — prev, curr, next — rewiring
//   curr.next = prev at every step.
//
// Core Idea
//   Classic three-pointer iterative reversal: prev, curr, next — rewire one
//   link per step
//
// Reference signature (Rust): fn reverse_list(head: Option<Box<ListNode>>) ->
// Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/reverse-linked-list/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

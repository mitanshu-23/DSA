// Problem 11: Reverse a Linked List (Recursive)
//
// Difficulty: Medium
// Group:      4
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a singly linked list, reverse the list recursively and
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
  ListNode *reverseHead = nullptr;
  ListNode *reverseRecursive(ListNode *curr) {
    if (curr == nullptr || curr->next == nullptr) {
      reverseHead = curr;
      return curr;
    }

    ListNode *reverse = reverseRecursive(curr->next);
    reverse->next = curr;
    return curr;
  }

  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *reverse = reverseRecursive(head);
    reverse->next = nullptr;
    return reverseHead;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: recurse on head.next first, then hook the old head onto the
//   tail of the reversed rest (head.next.next = head) and cut head.next.
//
// Core Idea
//   Reverse the rest recursively first, then hook head.next.next=head and cut
//   head.next
//
// Reference signature (Rust): fn reverse_list_recursive(head:
// Option<Box<ListNode>>) -> Option<Box<ListNode>> Complexity — Time: O(?)
// Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/reverse-linked-list/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

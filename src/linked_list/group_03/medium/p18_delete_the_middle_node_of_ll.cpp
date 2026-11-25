// Problem 18: Delete the Middle Node of LL
//
// Difficulty: Medium
// Group:      3
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a singly linked list, delete the middle node and return
//   the head of the modified list. For an even-length list, delete the second
//   of the two middle nodes.
//
//   Example 1:  list = [1,3,4,7,1,2,6]  →  [1,3,4,1,2,6]
//   Example 2:  list = [1,2,3,4]         →  [1,2,4]
//
//   Constraints:
//     1 <= length <= 10^5
//
// Problem Link
//   https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
  ListNode *deleteMiddle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *slow_prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
      slow_prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    if (slow_prev == nullptr) {
      return nullptr;
    }
    // cout << slow_prev->val << endl;
    slow_prev->next = slow->next;
    return head;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: start fast one step ahead of slow so slow naturally lands on
//   the node just before the middle.
//
// Core Idea
//   Start fast one step ahead of slow so slow lands on the node just before the
//   middle; splice it out
//
// Reference signature (Rust): fn delete_middle(head: Option<Box<ListNode>>) ->
// Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:
//   https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

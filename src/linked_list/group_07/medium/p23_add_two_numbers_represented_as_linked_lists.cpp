// Problem 23: Add Two Numbers Represented as Linked Lists
//
// Difficulty: Medium
// Group:      7
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   You are given two non-empty linked lists representing two non-negative
//   integers, digits stored in reverse order. Add the two numbers and return
//   the sum as a linked list in the same format.
//
//   Example 1:  l1 = [2,4,3], l2 = [5,6,4]  →  [7,0,8]   (342 + 465 = 807)
//   Example 2:  l1 = [9,9], l2 = [1]         →  [0,0,1]   (99 + 1 = 100)
//
//   Constraints:
//     1 <= length of each list <= 100
//     0 <= digit <= 9
//
// Problem Link
//   https://leetcode.com/problems/add-two-numbers/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverse(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *temp = head;
    ListNode *prev = nullptr;
    while (temp != nullptr) {
      ListNode *nxt = temp->next;
      temp->next = prev;
      prev = temp;
      temp = nxt;
    }

    return prev;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Same approach as add 1 to the number

    // Reverse a linked list
    // ListNode* reverse_head_1 = reverse(l1);
    // ListNode* reverse_head_2 = reverse(l2);
    ListNode *reverse_head_1 = l1;
    ListNode *reverse_head_2 = l2;
    // Add both numbers
    int carry = 0;
    ListNode *sum_head = nullptr;
    ListNode *prev = nullptr;

    while (reverse_head_1 != nullptr && reverse_head_2 != nullptr) {
      int s = reverse_head_1->val + reverse_head_2->val + carry;
      int n_val = s % 10;
      carry = s / 10;
      // cout << n_val << endl;
      ListNode *new_node = new ListNode(n_val);

      if (sum_head == nullptr) {
        sum_head = new_node;
      } else {
        prev->next = new_node;
      }
      prev = new_node;
      reverse_head_1 = reverse_head_1->next;
      reverse_head_2 = reverse_head_2->next;
    }

    while (reverse_head_1 != nullptr) {
      int s = reverse_head_1->val + carry;
      int n_val = s % 10;
      carry = s / 10;
      // cout << n_val << endl;
      ListNode *new_node = new ListNode(n_val);

      prev->next = new_node;

      prev = new_node;
      reverse_head_1 = reverse_head_1->next;
    }

    while (reverse_head_2 != nullptr) {
      int s = reverse_head_2->val + carry;
      int n_val = s % 10;
      carry = s / 10;
      // cout << n_val << endl;
      ListNode *new_node = new ListNode(n_val);

      prev->next = new_node;

      prev = new_node;
      reverse_head_2 = reverse_head_2->next;
    }

    if (carry > 0) {
      ListNode *new_node = new ListNode(carry);
      prev->next = new_node;
    }

    // Reverse it back
    // ListNode* ans_head = reverse(sum_head);

    return sum_head;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: walk both lists together, adding digits plus a running carry;
//   a dummy head keeps the output construction clean.
//
// Core Idea
//   Walk both lists together adding digits with a running carry; a dummy head
//   keeps the output construction clean
//
// Reference signature (Rust): fn add_two_numbers(l1: Option<Box<ListNode>>, l2:
// Option<Box<ListNode>>) -> Option<Box<ListNode>> Complexity — Time: O(?)
// Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/add-two-numbers/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

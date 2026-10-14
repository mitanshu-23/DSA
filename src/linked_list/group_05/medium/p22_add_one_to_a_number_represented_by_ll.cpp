// Problem 22: Add One to a Number Represented by LL
//
// Difficulty: Medium
// Group:      5
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list representing a non-negative integer (most
//   significant digit first), add one to the number and return the head of the
//   resulting list.
//
//   Example 1:  list = [1,2,3]  →  [1,2,4]
//   Example 2:  list = [9,9]     →  [1,0,0]
//
//   Constraints:
//     1 <= length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = nullptr;
  }
};

class Solution {
public:
  Node *reverse(Node *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr) {
      Node *nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }

    return prev;
  }

  Node *addOne(Node *head) {
    // code here
    // reverse a ll
    Node *reversed = reverse(head);
    // add one
    Node *curr = reversed;
    Node *prev = nullptr;
    bool create = true;
    while (curr != nullptr) {
      if (curr->data == 9) {
        curr->data = 0;
      } else {
        curr->data += 1;
        create = false;
        break;
      }
      prev = curr;
      curr = curr->next;
    }

    if (create) {
      Node *first = new Node(1);
      prev->next = first;
    }

    // reverse a ll
    Node *final = reverse(reversed);

    return final;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: reverse the list, add 1 propagating carry node by node, then
//   reverse back — or directly find the rightmost digit that isn't 9 and
//   increment it, zeroing everything after.
//
// Core Idea
//   Reverse, add 1 with carry propagation, reverse back — or find the rightmost
//   non-9 digit directly
//
// Reference signature (Rust): fn add_one(head: Option<Box<ListNode>>) ->
// Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

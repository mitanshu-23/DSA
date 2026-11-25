// Problem 08: Reverse a Doubly Linked List
//
// Difficulty: Medium
// Group:      2
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given the head of a doubly linked list, reverse it in place and return the
//   new head.
//
//   Example 1:  list = [1,2,3,4,5]  →  [5,4,3,2,1]
//   Example 2:  list = [1,2]         →  [2,1]
//
//   Constraints:
//     0 <= length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

/* Structure of Doubly Linked List Node*/
class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int val) {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

class Solution {
public:
  Node *reverse(Node *head) {
    // code here
    Node *temp = head;
    while (temp->next != nullptr) {
      Node *t = temp->next;
      temp->next = temp->prev;
      temp->prev = t;
      temp = t;
    }

    Node *t = temp->next;
    temp->next = temp->prev;
    temp->prev = t;

    return temp;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: swap each node's next and prev; the old tail becomes the new
//   head.
//
// Core Idea
//   Swap next and prev on every node; the old tail becomes the new head
//
// Reference signature (Rust): fn reverse_dll(head:
// Option<Rc<RefCell<DoublyListNode>>>) -> Option<Rc<RefCell<DoublyListNode>>>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

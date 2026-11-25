// Problem 07: Delete Head of Doubly Linked List
//
// Difficulty: Easy
// Group:      2
// Platform:   ALL
// Language:   C++
//
// Problem Statement
//   Given the head of a doubly linked list, delete the head node and return the
//   new head.
//
//   Example 1:  list = [1,2,3,4]  →  [2,3,4]
//   Example 2:  list = [7]         →  []
//
// Constraints:

// 2 ≤ size of linked list ≤ 105
// 1 ≤ node.data ≤ 10^9
//
// Problem Link
//   N/A

#include <bits/stdc++.h>
using namespace std;

/* Structure of doubly linked list Node */
class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int x) {
    data = x;
    next = nullptr;
    prev = nullptr;
  }
};

class Solution {
public:
  Node *deleteHead(Node *head) {
    // code here
    Node *nnode = head->next;
    nnode->prev = nullptr;
    return nnode;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: advance head to head.next, then clear the new head's prev
//   pointer.
//
// Core Idea
//   Advance head to head.next and clear its prev; handle the single-node case
//
// Reference signature (Rust): fn delete_head_dll(head:
// Option<Rc<RefCell<DoublyListNode>>>) -> Option<Rc<RefCell<DoublyListNode>>>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links

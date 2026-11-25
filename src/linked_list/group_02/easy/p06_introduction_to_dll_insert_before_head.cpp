// Problem 06: Introduction to DLL / Insert Before Head
//
// Difficulty: Easy
// Group:      2
// Platform:   GFG
// Language:   C++
//
// /Doubly Linked List from an Array
// Solved
// Difficulty: EasyAccuracy: 93.49%Submissions: 81K+Points: 2
// Given an array arr[] of integers, the goal is to create a Doubly Linked List
// (DLL) where each element of the array is represented as a node. The nodes
// must be linked in the same sequence as the array, maintaining both forward
// (next) and backward (prev) connections. Return the head of the constructed
// doubly linked list.
//   Constraints:
//     1 <= length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;
  Node(int d) {
    data = d;
    next = nullptr;
    prev = nullptr;
  }
};

class Solution {
public:
  Node *createDLL(vector<int> &arr) {
    // code here
    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++) {
      Node *nnode = new Node(arr[i]);
      nnode->prev = temp;
      temp->next = nnode;
      temp = nnode;
    }

    return head;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: wire both the new node's next (to the old head) and the old
//   head's prev (back to the new node).
//
// Core Idea
//   New node's next=head and head's prev points back to it; the new node
//   becomes head
//
// Reference signature (Rust): fn insert_before_head_dll(head:
// Option<Rc<RefCell<DoublyListNode>>>, val: i32) ->
// Option<Rc<RefCell<DoublyListNode>>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1

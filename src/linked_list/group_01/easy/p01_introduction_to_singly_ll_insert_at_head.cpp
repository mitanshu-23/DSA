// Problem 01: Introduction to Singly LL / Insert at Head
//
// Difficulty: Easy
// Group:      1
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given a linked list (or an empty one) and a value, insert a new node
//   holding that value at the head and return the new head.
//
//   Example 1:  list = [2,3,4], val = 1  →  [1,2,3,4]
//   Example 2:  list = [], val = 5        →  [5]
//
//   Constraints:
//     0 <= length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1

#include <bits/stdc++.h>
using namespace std;

// Linked List Node Structure
class Node {
public:
  int data;
  Node *next;
  Node(int d) {
    data = d;
    next = nullptr;
  }
};

class Solution {
public:
  Node *arrayToList(vector<int> &arr) {
    // code here
    Node *head = nullptr;
    Node *last = nullptr;
    for (int i = 0; i < arr.size(); i++) {
      Node *n = new Node(arr[i]);
      if (head == nullptr) {
        head = n;
      } else {
        last->next = n;
      }
      last = n;
    }

    return head;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: the new node's next points at the old head; it becomes the new
//   head in O(1).
//
// Core Idea
//   New node's next=head; the new node becomes the head in O(1)
//
// Reference signature (Rust): fn insert_at_head(head: Option<Box<ListNode>>,
// val: i32) -> Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1

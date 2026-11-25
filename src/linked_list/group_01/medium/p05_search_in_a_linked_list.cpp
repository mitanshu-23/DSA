// Problem 05: Search in a Linked List
//
// Difficulty: Medium
// Group:      1
// Platform:   ALL
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list and a target value, return true if the
//   target exists anywhere in the list.
//
//   Example 1:  list = [1,2,3,4], target = 3  →  true
//   Example 2:  list = [1,2,3], target = 9     →  false
//
//   Constraints:
//     0 <= length <= 10^5
//
// Problem Link
//   N/A

#include <bits/stdc++.h>
using namespace std;

/* Structure of Linked List Node*/
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
  bool searchKey(Node *head, int key) {
    // Code here
    Node *temp = head;

    while (temp != nullptr) {
      if (temp->data == key) {
        return true;
      }

      temp = temp->next;
    }

    return false;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Core Idea
//   Linear traversal; return true the moment a node's value matches target
//
// Reference signature (Rust): fn search_in_linked_list(head:
// Option<Box<ListNode>>, target: i32) -> bool Complexity — Time: O(?)  Space:
// O(?)
//
// All Links

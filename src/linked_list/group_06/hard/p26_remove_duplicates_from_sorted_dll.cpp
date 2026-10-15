// Problem 26: Remove Duplicates from Sorted DLL
//
// Difficulty: Hard
// Group:      6
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given the head of a sorted doubly linked list, delete all duplicate nodes
//   so each value appears only once, and return the new head.
//
//   Example 1:  list = [1,1,2]        →  [1,2]
//   Example 2:  list = [1,1,2,3,3]     →  [1,2,3]
//
//   Constraints:
//     0 <= length <= 300
//     list is sorted in non-decreasing order.
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

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
  Node *removeDuplicates(Node *headRef) {
    // code here
    int prevval = headRef->data;
    Node *curr = headRef->next;
    Node *prev = headRef;

    while (curr != nullptr) {
      while (curr->data == prevval) {
        curr = curr->next;
        if (curr == nullptr) {
          break;
        }
      }

      prev->next = curr;
      if (curr != nullptr) {
        curr->prev = prev;
        prev = curr;
        prevval = curr->data;
        curr = curr->next;
      }
    }

    return headRef;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: walk adjacent pairs; whenever curr.next repeats curr.val,
//   bypass it by rewiring both curr.next and the successor's prev.
//
// Core Idea
//   Walk adjacent pairs; bypass curr.next whenever it repeats curr.val,
//   rewiring prev on both sides
//
// Reference signature (Rust): fn delete_duplicates_dll(head:
// Option<Rc<RefCell<DoublyListNode>>>) -> Option<Rc<RefCell<DoublyListNode>>>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

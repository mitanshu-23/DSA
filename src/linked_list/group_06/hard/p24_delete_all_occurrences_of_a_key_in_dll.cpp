// Problem 24: Delete All Occurrences of a Key in DLL
//
// Difficulty: Hard
// Group:      6
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given the head of a doubly linked list and a key, delete every node whose
//   value equals key and return the new head.
//
//   Example 1:  list = [1,2,1,3,1], key = 1  →  [2,3]
//   Example 2:  list = [4,5,6], key = 9       →  [4,5,6]  (unchanged)
//
//   Constraints:
//     0 <= length <= 10^4
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

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
  Node *deleteAllOccurOfX(Node *head, int x) {
    // code here
    Node *curr = head;
    Node *newHead = nullptr;
    Node *prev = nullptr;

    while (curr != nullptr) {
      if (prev == nullptr && curr->data == x) {
        curr = curr->next;
        continue;
      } else if (curr->data == x) {
        prev->next = curr->next;
        if (curr->next != nullptr) {
          curr->next->prev = prev;
        }
        curr = curr->next;
      } else {
        if (newHead == nullptr) {
          newHead = curr;
          curr->prev = nullptr;
        } else {
          curr->prev = prev;
          prev->next = curr;
        }

        prev = curr;
        curr = curr->next;
      }
    }

    return newHead;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: for every match, rewire node.prev.next and node.next.prev
//   around it; update the head pointer whenever the head itself is deleted.
//
// Core Idea
//   Rewire prev.next and next.prev around every matching node; update head when
//   the head itself matches
//
// Reference signature (Rust): fn delete_all_occurrences_dll(head:
// Option<Rc<RefCell<DoublyListNode>>>, key: i32) ->
// Option<Rc<RefCell<DoublyListNode>>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

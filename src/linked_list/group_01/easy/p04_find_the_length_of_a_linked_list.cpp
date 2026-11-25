// Problem 04: Find the Length of a Linked List
//
// Difficulty: Easy
// Group:      1
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list, return the number of nodes in it.
//
//   Example 1:  list = [1,2,3,4,5]  →  5
//   Example 2:  list = []            →  0
//
//   Constraints:
//     0 <= length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

#include <bits/stdc++.h>
using namespace std;

// /* Structure of linked list Node
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
  int getCount(Node *head) {
    // Code here
    int len = 0;
    Node *temp = head;
    while (temp != nullptr) {
      temp = temp->next;
      len++;
    }

    return len;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Core Idea
//   Walk from head counting nodes until curr is null
//
// Reference signature (Rust): fn length_of_linked_list(head:
// Option<Box<ListNode>>) -> i32 Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

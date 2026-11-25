// Problem 29: Flatten a Linked List (Next + Down Pointers)
//
// Difficulty: Hard
// Group:      9
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given a linked list where every node has a next pointer and a child (down)
//   pointer to another sorted linked list, flatten it into a single sorted
//   linked list using only the next pointers.
//
//   Example 1:  1 -> 2 with 2 having a child list 3 -> 4  →  1 -> 2 -> 3 -> 4
//   (all sorted, merged)
//
//   Constraints:
//     Every individual list (main and child) is itself sorted.
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

/* Structure of Linked List Node*/
class Node {
public:
  int data;
  Node *next;
  Node *bottom;

  Node(int x) {
    data = x;
    next = nullptr;
    bottom = nullptr;
  }
};

class Solution {
public:
  // My Approach
  Node *flatten_two(Node *ll1, Node *ll2) {
    Node *smallest = ll1;
    smallest->next = nullptr;

    Node *flattened = ll1;

    ll1 = ll1->bottom;

    while (ll1 != nullptr && ll2 != nullptr) {
      if (ll1->data < ll2->data) {
        flattened->bottom = ll1;
        ll1 = ll1->bottom;
      } else {
        flattened->bottom = ll2;
        ll2 = ll2->bottom;
      }
      flattened = flattened->bottom;
      flattened->next = nullptr;
    }

    while (ll1 != nullptr) {
      flattened->bottom = ll1;
      ll1 = ll1->bottom;
      flattened = flattened->bottom;
      flattened->next = nullptr;
    }

    while (ll2 != nullptr) {
      flattened->bottom = ll2;
      ll2 = ll2->bottom;
      flattened = flattened->bottom;
      flattened->next = nullptr;
    }

    return smallest;
  }

  Node *flatten(Node *head) {
    int len = 0;
    Node *temp = head;
    stack<Node *> stk;
    while (temp != nullptr) {
      len++;
      stk.push(temp);
      temp = temp->next;
    }

    Node *result = head;

    for (int i = 1; i < len; i++) {
      Node *top = stk.top();
      stk.pop();
      Node *top2 = stk.top();
      stk.pop();

      result = flatten_two(top2, top);
      stk.push(result);
    }

    return result;
  }
};

/* Structure of Linked List Node
class Node {
        public:
        int data;
        Node* next;
        Node* bottom;

        Node(int x) {
                data = x;
                next = nullptr;
                bottom = nullptr;
        }
}; */

// LLM hinted to see it as Merge Sort problem
class Solution2 {
public:
  Node *flatten_two(Node *ll1, Node *ll2) {
    Node *smallest = ll1;
    smallest->next = nullptr;

    Node *flattened = ll1;

    ll1 = ll1->bottom;

    while (ll1 != nullptr && ll2 != nullptr) {
      if (ll1->data < ll2->data) {
        flattened->bottom = ll1;
        ll1 = ll1->bottom;
      } else {
        flattened->bottom = ll2;
        ll2 = ll2->bottom;
      }
      flattened = flattened->bottom;
      flattened->next = nullptr;
    }

    while (ll1 != nullptr) {
      flattened->bottom = ll1;
      ll1 = ll1->bottom;
      flattened = flattened->bottom;
      flattened->next = nullptr;
    }

    while (ll2 != nullptr) {
      flattened->bottom = ll2;
      ll2 = ll2->bottom;
      flattened = flattened->bottom;
      flattened->next = nullptr;
    }

    return smallest;
  }

  Node *flatten_dnq(Node *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;       // Moves 1 step along 'next'
      fast = fast->next->next; // Moves 2 steps along 'next'
    }

    prev->next = nullptr;
    // 		cout<<"List 1: from: "<<head->data<<" to: "<<prev->data<<endl;
    Node *left_sorted = flatten_dnq(head);
    Node *right_sorted = flatten_dnq(slow);

    return flatten_two(left_sorted, right_sorted);
  }

  Node *flatten(Node *head) { return flatten_dnq(head); }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: recursively flatten head.next first, then merge the current
//   column (head down to head.down) with the already-flattened rest — reusing
//   the merge-two-sorted routine.
//
// Core Idea
//   Recursively flatten next first, then merge the current child column into
//   the already-flattened rest
//
// Reference signature (Rust): fn flatten(head: Option<Box<MultiLevelNode>>) ->
// Option<Box<MultiLevelNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

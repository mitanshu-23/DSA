// Problem 20: Sort a LL of 0s, 1s, and 2s
//
// Difficulty: Medium
// Group:      5
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list containing only the values 0, 1, and 2,
//   sort it in-place by rearranging links only (not by changing node values).
//
//   Example 1:  list = [1,2,2,1,2,0,2,2]  →  [0,1,1,2,2,2,2,2]
//   Example 2:  list = [2,2,0,1]            →  [0,1,2,2]
//
//   Constraints:
//     1 <= length <= 10^5
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

#include <bits/stdc++.h>
using namespace std;

/* Node is defined as*/

class Node {
public:
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = nullptr;
  }
};

/* Node is defined as
class Node {
        public:
        int data;
        Node* next;

        Node(int x) {
                data = x;
                next = nullptr;
        }
};
*/
class Solution {
public:
  Node *segregate(Node *head) {
    // code here
    Node *zeroes = nullptr;
    Node *ones = nullptr;
    Node *twos = nullptr;

    Node *ones_head = nullptr;
    Node *twos_head = nullptr;
    Node *zeroes_head = nullptr;

    Node *temp = head;

    while (temp != nullptr) {
      // 			cout << temp->data << endl;
      Node *nxt = temp->next;
      temp->next = nullptr;
      switch (temp->data) {
      case 0: {
        if (zeroes == nullptr) {
          zeroes_head = temp;
          zeroes = temp;
        } else {
          zeroes->next = temp;
          zeroes = temp;
        }
        break;
      }
      case 1: {
        if (ones == nullptr) {
          ones_head = temp;
          ones = temp;
        } else {
          ones->next = temp;
          ones = temp;
        }
        break;
      }
      case 2: {
        if (twos == nullptr) {
          twos_head = temp;
          twos = temp;
        } else {
          twos->next = temp;
          twos = temp;
        }
        break;
      }
      default:
        break;
      }

      temp = nxt;
    }

    if (zeroes_head == nullptr) {
      if (ones_head == nullptr) {
        return twos_head;
      }
      ones->next = twos_head;
      return ones_head;
    } else if (ones_head == nullptr) {
      zeroes->next = twos_head;
      return zeroes_head;
    }

    zeroes->next = ones_head;
    ones->next = twos_head;

    return zeroes_head;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: a Dutch-flag-style three-chain partition — maintain separate
//   0/1/2 chains while traversing once, then splice 0-chain -> 1-chain ->
//   2-chain together.
//
// Core Idea
//   Three-chain partition (Dutch flag on a list); reconnect the 0-chain to the
//   1-chain to the 2-chain
//
// Reference signature (Rust): fn sort_zero_one_two_list(head:
// Option<Box<ListNode>>) -> Option<Box<ListNode>> Complexity — Time: O(?)
// Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

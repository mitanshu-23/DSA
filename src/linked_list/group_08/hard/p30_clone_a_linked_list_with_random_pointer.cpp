// Problem 30: Clone a Linked List with Random Pointer
//
// Difficulty: Hard
// Group:      8
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   A linked list of length n is given where each node has an additional random
//   pointer that could point to any node in the list, or null. Construct a deep
//   copy of the list.
//
//   Example 1:  list = [[7,null],[13,0],[11,4],[10,2],[1,0]]  →  a fully
//   independent deep copy with the same structure
//
//   Constraints:
//     0 <= n <= 1000
//
// Problem Link
//   https://leetcode.com/problems/copy-list-with-random-pointer/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
// Definition for a Node.*/
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }
    unordered_map<Node *, Node *> assc;
    Node *copy_head = new Node(head->val);
    Node *prev = copy_head;
    Node *given_temp = head->next;
    assc[head] = copy_head;
    // Create Copy list without random pointers
    while (given_temp != nullptr) {
      Node *new_node = new Node(given_temp->val);
      assc[given_temp] = new_node;
      prev->next = new_node;
      prev = new_node;

      given_temp = given_temp->next;
    }
    prev->next = nullptr;

    Node *temp = copy_head;
    given_temp = head;
    while (given_temp != nullptr) {
      Node *rndm = given_temp->random;
      Node *assc_rndm = assc[rndm];
      temp->random = assc_rndm;

      temp = temp->next;
      given_temp = given_temp->next;
    }

    return copy_head;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: interleave a clone after each original node, wire every
//   clone's random pointer off the interleaved pair, then split the two lists
//   apart. O(1) extra space.
//
// Core Idea
//   Interleave a clone after each original, wire random off the interleaved
//   pairs, then split the two lists apart
//
// Reference signature (Rust): fn copy_random_list(head:
// Option<Rc<RefCell<RandomListNode>>>) -> Option<Rc<RefCell<RandomListNode>>>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/copy-list-with-random-pointer/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

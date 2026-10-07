// Problem 14: Length of Loop in LL
//
// Difficulty: Medium
// Group:      3
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list that contains a cycle, return the number of
//   nodes in that cycle (0 if there is no cycle).
//
//   Example 1:  list = [1,2,3,4], tail connects to node index 1  →  3
//   Example 2:  list = [1,2,3], no cycle                            →  0
//
//   Constraints:
//     0 <= length <= 10^4
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/find-length-of-loop/1

#include <bits/stdc++.h>
using namespace std;

/* Structure of Linked List Node */
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
  int lengthOfLoop(Node *head) {
    // code here
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;

      if (slow == fast) {
        Node *temp = head;
        while (temp != slow) {
          temp = temp->next;
          slow = slow->next;
        }

        Node *start = temp;
        temp = temp->next;
        int len = 1;
        while (start != temp) {
          len++;
          temp = temp->next;
        }

        return len;
      }
    }

    return 0;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: once Floyd's phase 1 finds the meeting point, hold one pointer
//   fixed and count steps until the other pointer returns to it.
//
// Core Idea
//   From the phase-1 meeting point, hold one pointer fixed and count steps
//   until the other returns to it
//
// Reference signature (Rust): fn cycle_length(head: Option<Box<ListNode>>) ->
// i32 Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

// Problem 21: Find the Intersection of Two Linked Lists
//
// Difficulty: Medium
// Group:      8
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the heads of two singly linked lists, return the node at which the
//   two lists intersect, or None if they don't intersect. The two lists share
//   no cycle.
//
//   Example 1:  A = [4,1,8,4,5], B = [5,6,1,8,4,5], intersecting at the node
//   with val 8  →  that node Example 2:  A = [2,6,4], B = [1,5]  →  None
//
//   Constraints:
//     The intersected part (if any) has the same length in both lists from that
//     node onward.
//
// Problem Link
//   https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // HashMap solution
    // unordered_map<ListNode *, bool> exists;
    // ListNode *tempa = headA;
    // ListNode *tempb = headB;

    // while (tempa != nullptr && tempb != nullptr) {
    //   if (tempa == tempb) {
    //     return tempa;
    //   }

    //   if (exists[tempa]) {
    //     return tempa;
    //   }

    //   if (exists[tempb]) {
    //     return tempb;
    //   }

    //   exists[tempa] = true;
    //   exists[tempb] = true;
    // }

    // return nullptr;

    int a_len = 0;
    int b_len = 0;

    ListNode *tempA = headA;
    ListNode *tempB = headB;

    while (tempA != nullptr) {
      a_len++;
      tempA = tempA->next;
    }

    while (tempB != nullptr) {
      b_len++;
      tempB = tempB->next;
    }

    tempA = headA;
    tempB = headB;

    // Head Start
    if (a_len > b_len) {
      int diff = a_len - b_len;
      while (diff > 0) {
        tempA = tempA->next;
        diff--;
      }
    } else if (b_len > a_len) {
      int diff = b_len - a_len;
      while (diff > 0) {
        tempB = tempB->next;
        diff--;
      }
    }

    while (tempA != nullptr || tempB != nullptr) {
      if (tempA == tempB) {
        return tempA;
      }

      tempA = tempA->next;
      tempB = tempB->next;
    }

    return nullptr;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: two pointers redirect to the other list's head the moment they
//   run out; they meet after len(A)+len(B) steps because both traverse the same
//   total distance.
//
// Core Idea
//   Two pointers redirect to the other list's head when they run out; they meet
//   after len(A)+len(B) steps
//
// Reference signature (Rust): fn get_intersection_node(head_a:
// Option<Box<ListNode>>, head_b: Option<Box<ListNode>>) ->
// Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode: https://leetcode.com/problems/intersection-of-two-linked-lists/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

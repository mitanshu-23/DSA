// Problem 28: Rotate a Linked List
//
// Difficulty: Hard
// Group:      9
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list and an integer k, rotate the list to the
//   right by k places and return the new head.
//
//   Example 1:  list = [1,2,3,4,5], k = 2  →  [4,5,1,2,3]
//   Example 2:  list = [0,1,2], k = 4       →  [2,0,1]
//
//   Constraints:
//     0 <= length <= 500
//     0 <= k <= 2*10^9
//
// Problem Link
//   https://leetcode.com/problems/rotate-list/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.  */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *temp = head;
    int len = 0;
    while (temp != nullptr) {
      temp = temp->next;
      len++;
    }

    int k_normalized = k % len;

    if (k_normalized == 0) {
      return head;
    }

    // rotating k nodes to thr ight is same as joining 2 ll: first k nodes
    // from last and 2nd: (len - k) nodes from front and attaching first and
    // last take out (len - k) nodes from front
    int target_nodes_front = len - k_normalized;
    // int nodes_from_front = 0;
    ListNode *part_2 = head;
    ListNode *last = nullptr;
    while (target_nodes_front > 0) {
      last = part_2;
      part_2 = part_2->next;
      target_nodes_front--;
    }
    last->next = nullptr;
    ListNode *new_head = part_2;
    ListNode *part_1 = part_2;

    while (part_1->next != nullptr) {
      part_1 = part_1->next;
    }
    // cout << part_1->val << endl;
    // Join part1 and part2
    part_1->next = head;

    return new_head;
  }
};
// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: find the length and the tail, normalise k to k % length, then
//   cut the list at the new pivot and reconnect the old tail to the old head.
//
// Core Idea
//   Find length and tail, normalise k%length, cut at the new pivot and
//   reconnect the old tail to the old head
//
// Reference signature (Rust): fn rotate_right(head: Option<Box<ListNode>>, k:
// i32) -> Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/rotate-list/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

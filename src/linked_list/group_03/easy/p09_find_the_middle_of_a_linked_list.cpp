// Problem 09: Find the Middle of a Linked List
//
// Difficulty: Easy
// Group:      3
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a singly linked list, return the middle node. If there
//   are two middle nodes, return the second one.
//
//   Example 1:  list = [1,2,3,4,5]    →  node with val 3
//   Example 2:  list = [1,2,3,4,5,6]  →  node with val 4
//
//   Constraints:
//     1 <= length <= 100
//
// Problem Link
//   https://leetcode.com/problems/middle-of-the-linked-list/

#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    // Using fast and slow pointer
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: slow moves 1 step, fast moves 2; when fast reaches the end,
//   slow is at the middle.
//
// Core Idea
//   slow moves 1 step, fast moves 2; when fast runs out slow sits at the middle
//
// Reference signature (Rust): fn middle_node(head: Option<Box<ListNode>>) ->
// Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/middle-of-the-linked-list/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

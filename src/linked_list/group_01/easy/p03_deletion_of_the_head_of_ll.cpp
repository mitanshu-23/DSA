// Problem 03: Deletion of the Head of LL
//
// Difficulty: Easy
// Group:      1
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list, delete the head node and return the new
//   head.
//
//   Example 1:  list = [1,2,3,4]  →  [2,3,4]
//   Example 2:  list = [7]         →  []
//
//   Constraints:
//     0 <= length <= 10^5
//
// Problem Link
//   https://leetcode.com/problems/delete-node-in-a-linked-list/

// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. You will not be given access to
// the first node of head.

// All the values of the linked list are unique, and it is guaranteed that the
// given node node is not the last node in the linked list.

// Delete the given node. Note that by deleting the node, we do not mean
// removing it from memory. We mean:

// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.
// Custom testing:

// For the input, you should provide the entire linked list head and the node to
// be given node. node should not be the last node of the list and should be an
// actual node in the list. We will build the linked list and pass the node to
// your function. The output will be the entire list after calling your
// function.

//  * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
  void deleteNode(ListNode *node) {
    ListNode* curr = node;
    ListNode* next = node -> next;

    curr->val = next->val;
    curr->next = next->next;

  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Core Idea
//   head=head.next; handle the empty-list case
//
// Reference signature (Rust): fn delete_head(head: Option<Box<ListNode>>) ->
// Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/delete-node-in-a-linked-list/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/delete-a-node-in-singly-linked-list/1

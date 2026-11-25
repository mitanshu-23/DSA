// Problem 27: Reverse Nodes in K-Group
//
// Difficulty: Hard
// Group:      4
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list and an integer k, reverse the nodes of the
//   list k at a time and return the modified list. If the number of nodes
//   remaining is fewer than k, leave that final group as-is.
//
//   Example 1:  list = [1,2,3,4,5], k = 2  →  [2,1,4,3,5]
//   Example 2:  list = [1,2,3,4,5], k = 3  →  [3,2,1,4,5]
//
//   Constraints:
//     1 <= k <= length of the list
//
// Problem Link
//   https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h>
using namespace std;

/**/
//   Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverse(ListNode *head, int remaining) {
    if (remaining == 1) {
      return head;
    }

    ListNode *reversed = reverse(head->next, remaining - 1);
    reversed->next = head;
    return head;
  }
  
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *temp = head;
    ListNode *prev = nullptr;
    ListNode *first = nullptr;

    while (temp != nullptr) {
      int count = 0;
      ListNode *thead = temp;
      ListNode *ttail = temp;

      while (count < k) {
        ttail = temp;
        temp = temp->next;
        count++;

        if (count < k && temp == nullptr) {
          if (first == nullptr) {
            return head;
          } else {
            return first;
          }
        }

      }

      ListNode *reversed = reverse(thead, k);

      if (first == nullptr) {
        first = ttail;
      } else {
        prev->next = ttail;
      }

      prev = thead;
      thead->next = temp;
    }

    return first;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: check that k nodes are available before reversing them;
//   recurse on the rest and reconnect — the original head of each reversed
//   group becomes the tail that links to the next group.
//
// Core Idea
//   Check k nodes exist, reverse them, recurse on the rest, then reconnect;
//   leave a short final group untouched
//
// Reference signature (Rust): fn reverse_k_group(head: Option<Box<ListNode>>,
// k: i32) -> Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/reverse-nodes-in-k-group/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

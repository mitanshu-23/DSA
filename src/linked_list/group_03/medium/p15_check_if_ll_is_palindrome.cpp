// Problem 15: Check if LL is Palindrome
//
// Difficulty: Medium
// Group:      3
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a singly linked list, return true if it reads the same
//   forwards and backwards.
//
//   Example 1:  list = [1,2,2,1]  →  true
//   Example 2:  list = [1,2]       →  false
//
//   Constraints:
//     1 <= length <= 10^5
//
// Problem Link
//   https://leetcode.com/problems/palindrome-linked-list/

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
  bool isPalindrome(ListNode *head) {
    stack<int> stk;
    int len = 0;
    ListNode *temp = head;
    // Find the length of ll
    while (temp != nullptr) {
      temp = temp->next;
      len++;
    }

    int half = len / 2;

    int cnt = 0;
    temp = head;
    // put nums in stack (for reverse order out)
    while (cnt < half) {
      cnt++;
      stk.push(temp->val);
      temp = temp->next;
    }

    // skip middle element for odd length ll
    if (len % 2 != 0) {
      temp = temp->next;
    }

    // compare stack top and ll value
    while (temp != nullptr) {
      int top = stk.top();
      stk.pop();
      if (top != temp->val) {
        return false;
      }
      temp = temp->next;
    }

    return true;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: find the middle (slow/fast), reverse the second half in place,
//   then compare the two halves node by node.
//
// Core Idea
//   Find the middle, reverse the second half in place, then compare both halves
//   node by node
//
// Reference signature (Rust): fn is_palindrome(head: Option<Box<ListNode>>) ->
// bool Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/palindrome-linked-list/
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

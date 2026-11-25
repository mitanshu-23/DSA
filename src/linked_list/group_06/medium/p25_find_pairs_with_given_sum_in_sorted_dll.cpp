// Problem 25: Find Pairs with Given Sum in Sorted DLL
//
// Difficulty: Medium
// Group:      6
// Platform:   GFG
// Language:   C++
//
// Problem Statement
//   Given the head of a sorted (ascending) doubly linked list and a target sum,
//   return all pairs of values that add up to target.
//
//   Example 1:  list = [1,2,4,5,6,8,9], target = 7  →  [(1,6),(2,5)]
//   Example 2:  list = [1,2,3,4], target = 100       →  []
//
//   Constraints:
//     list is sorted in non-decreasing order.
//
// Problem Link
//   https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int x) {
    data = x;
    next = nullptr;
    prev = nullptr;
  }
};

class Solution {
public:
  vector<vector<int>> givenSumPairs(Node *head, int target) {
    // code here
    Node *last = head;

    while (last->next != nullptr) {
      last = last->next;
    }

    vector<vector<int>> result;

    while (head != last) {
      int sum = head->data + last->data;

      if (sum == target) {
        result.push_back({head->data, last->data});
        last = last->prev;

        if (last == head) {
          break;
        }

        head = head->next;
      } else if (sum > target) {
        last = last->prev;
      } else {
        head = head->next;
      }
    }

    return result;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: two pointers starting at head and tail, moving inward via
//   next/prev based on the sum comparison — only possible because a DLL allows
//   O(1) backward steps.
//
// Core Idea
//   Two pointers from both ends moving inward via next/prev; only possible
//   because a DLL allows O(1) backward steps
//
// Reference signature (Rust): fn pairs_with_given_sum(head:
// Option<Rc<RefCell<DoublyListNode>>>, target: i32) -> Vec<(i32, i32)>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   GeeksForGeeks:
//   https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

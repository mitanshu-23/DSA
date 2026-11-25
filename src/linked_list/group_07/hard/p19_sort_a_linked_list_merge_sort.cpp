// Problem 19: Sort a Linked List (Merge Sort)
//
// Difficulty: Hard
// Group:      7
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a linked list, sort it in ascending order and return the
//   sorted list.
//
//   Example 1:  list = [4,2,1,3]    →  [1,2,3,4]
//   Example 2:  list = [-1,5,3,4,0]  →  [-1,0,3,4,5]
//
//   Constraints:
//     0 <= length <= 5*10^4
//
// Problem Link
//   https://leetcode.com/problems/sort-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *merge(ListNode *l1, ListNode *l2, int left_count, int right_count) {
    // cout << "Merging: " << l1->val << " with count: " << left_count
    //   << " and " << l2->val << " with count: " << right_count << endl;

    ListNode *merged_head = nullptr;
    ListNode *prev = nullptr;

    int curr_left_count = 0;
    int curr_right_count = 0;

    while (curr_left_count < left_count && curr_right_count < right_count) {
      if (l1->val <= l2->val) {
        if (merged_head == nullptr) {
          merged_head = l1;
        } else {
          prev->next = l1;
        }
        prev = l1;
        l1 = l1->next;
        curr_left_count++;
      } else {
        if (merged_head == nullptr) {
          merged_head = l2;
        } else {
          prev->next = l2;
        }
        prev = l2;
        l2 = l2->next;
        curr_right_count++;
      }
    }

    while (curr_left_count < left_count) {
      if (merged_head == nullptr) {
        merged_head = l1;
      } else {
        prev->next = l1;
      }
      prev = l1;
      l1 = l1->next;
      curr_left_count++;
    }

    while (curr_right_count < right_count) {

      if (merged_head == nullptr) {
        merged_head = l2;
      } else {
        prev->next = l2;
      }
      prev = l2;
      l2 = l2->next;
      curr_right_count++;
    }

    prev->next = nullptr;

    return merged_head;
  }

  ListNode *merge_sort(ListNode *head, ListNode *last, int start, int end) {
    if (start == end) {
      return head;
    }

    ListNode *mid = head;
    int half = (end - start + 1) / 2;
    int explored = 1;
    
    while (explored < half) {
      mid = mid->next;
      explored++;
    }

    ListNode *right_start = mid->next;
    ListNode *left = merge_sort(head, mid, start, start + explored - 1);
    ListNode *right = merge_sort(right_start, last, start + explored, end);
    ListNode *new_head =
        merge(left, right, explored, (end - start - explored + 1));

    return new_head;
  }

  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *temp = head;
    ListNode *last = nullptr;
    int total = 0;

    while (temp != nullptr) {
      last = temp;
      temp = temp->next;
      total++;
    }

    ListNode *ans_head = merge_sort(head, last, 1, total);

    return ans_head;
  }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: find the middle (slow/fast), split into two halves,
//   recursively sort each, then merge the two sorted halves with a dummy-node
//   anchor.
//
// Core Idea
//   Find the middle, split into two halves, recursively sort each, then merge
//   the sorted halves
//
// Reference signature (Rust): fn sort_list(head: Option<Box<ListNode>>) ->
// Option<Box<ListNode>> Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/sort-list/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

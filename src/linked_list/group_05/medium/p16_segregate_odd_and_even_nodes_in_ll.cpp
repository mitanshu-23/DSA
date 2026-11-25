// Problem 16: Segregate Odd and Even Nodes in LL
//
// Difficulty: Medium
// Group:      5
// Platform:   LC
// Language:   C++
//
// Problem Statement
//   Given the head of a singly linked list, group all nodes at odd indices together followed by all nodes at even indices (1-indexed by position, not by value), and return the reordered list. Do it in O(1) extra space.
//   
//   Example 1:  list = [1,2,3,4,5]  →  [1,3,5,2,4]
//   Example 2:  list = [2,1,3,5,6,4,7]  →  [2,3,6,7,1,5,4]
//   
//   Constraints:
//     0 <= length <= 10^4
//
// Problem Link
//   https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr) {
            return head;
        }

        ListNode* odds = head;
        ListNode* evens = head->next;
        ListNode* evens_head = head->next;
        ListNode* curr = head->next->next;

        bool even = false;

        while (curr != nullptr) {
            ListNode* nxt = curr->next;
            if (even) {
                // cout << "Adding to even: " << curr->val << endl;
                evens->next = curr;
                evens = curr;
            } else {
                // cout << "Adding to odd: " << curr->val << endl;
                odds->next = curr;
                odds = curr;
            }
            even = !even;
            curr->next = nullptr;
            curr = nxt;
        }

        odds->next = evens_head;
        evens->next = nullptr;
        // cout << odds->next->next->val;
        return head;
    }
};

// ===========================================================================
//  SOLUTION NOTES  ·  hints & scratch space — peek here only when stuck
// ===========================================================================
//
// Hints
//   Key insight: maintain an odd-chain and an even-chain pointer, interleaving them while traversing, then append the even chain after the odd chain's tail.
//
// Core Idea
//   Two-chain partition by index parity; interleave odd/even while traversing, then append the even chain after the odd chain
//
// Reference signature (Rust): fn odd_even_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>>
// Complexity — Time: O(?)  Space: O(?)
//
// All Links
//   LeetCode:      https://leetcode.com/problems/odd-even-linked-list/
//   GeeksForGeeks: https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

# Striver's A2Z DSA Sheet — Step 6: Linked List

> **Source:** [takeuforward.org — Striver's A2Z DSA Sheet](https://takeuforward.org/prep-hub/strivers-a2z-dsa-sheet)
> **YouTube:** [takeUforward Channel](https://www.youtube.com/@takeUforward)
> **Total Problems:** 31
> **Sub-steps:** 6.1 Learn 1D LL (5) · 6.2 Learn Doubly LL (4) · 6.3 Medium Problems of LL (15) · 6.4 Medium Problems of DLL (3) · 6.5 Hard Problems of LL (4)

> **Note on moved problems:** LRU Cache has moved to Step 9 (Stack & Queues). Merge K Sorted Lists has moved to Step 11 (Heaps). Both are covered in those steps.

---

## Revision Tier Legend

| Tag | Meaning | When to revisit |
|---|---|---|
| 🔴 MUST | Core pointer technique. Interview staple. Skipping costs you downstream. | Every revision cycle. |
| 🟡 IMPORTANT | High-value problem with a reusable pattern. | Before interviews / contests. |
| 🟢 GOOD TO KNOW | Solve once. Lower frequency or derivable from a 🔴 problem. | Only when time allows. |

**Quick 🔴 revision list:** 5, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 21, 22, 24, 27, 28, 29, 30
That is 18 out of 31. Linked List is pointer-heavy — the majority of the weight is in 6.3 and 6.5.

---

## What Is New in Linked Lists vs Arrays?

Arrays give you random access via index. Linked Lists trade that for O(1) insert/delete at any node if you hold a pointer to it. The tradeoff forces a new way of thinking:

| Mental model | Arrays | Linked Lists |
|---|---|---|
| Access element i | `arr[i]` — O(1) | Walk from head — O(n) |
| Insert/delete at known point | Shift elements — O(n) | Rewire pointers — O(1) |
| Primary tool | Index arithmetic | Pointer manipulation |
| Key technique | Two pointers on indices | Slow/fast pointer on nodes |

**Five techniques cover ~90% of all LL problems you will ever see:**
1. **Pointer rewiring** — `prev.next = curr.next`
2. **Dummy node** — avoids edge cases on head deletion/insertion
3. **Slow / fast pointer** — cycle detection, find middle, nth from end
4. **In-place reversal** — `prev`, `curr`, `next` skeleton
5. **Merge (dummy anchor)** — merge two sorted lists cleanly

---

## Smart Solve Order — Correlation Clusters

```
CLUSTER 1 — 1D LL Basics (warm-up, in order)
  Intro to SLL, insert at head                🟢
  Deletion of head                            🟢
  Find length                                 🟢
  Search in LL                                🟢
  (insert/delete at kth is implied in basics) 🟢

CLUSTER 2 — Doubly LL Basics
  Intro to DLL, insert before head            🟢
  Delete head of DLL                          🟢
  Reverse a DLL                               🟡

CLUSTER 3 — Slow/Fast Pointer (do ALL together — same model)
  Middle of LL                                🔴  ← slow/fast anchor
  Detect cycle                                🔴  ← Floyd's
  Find starting point of cycle                🔴  ← Floyd's phase 2
  Length of cycle                             🟡  ← trivial after above
  Delete the middle node                      🔴  ← slow/fast application
  Remove Nth node from end                    🔴  ← fast N-ahead trick
  Check if LL is palindrome                   🔴  ← find mid + reverse + compare

CLUSTER 4 — Reversal (do ALL together — same skeleton)
  Reverse a LL (iterative)                    🔴  ← REVERSAL ANCHOR
  Reverse a LL (recursive)                    🟡  ← same, recursive style
  Reverse in K-Group                          🔴  ← hardest reversal variant

CLUSTER 5 — Partition / Segregation
  Segregate odd and even nodes                🔴  ← two-chain partition
  Sort LL of 0s, 1s, 2s                      🟡  ← three-chain partition
  Add one to a number represented by LL       🟡  ← reverse + carry trick

CLUSTER 6 — DLL Medium/Hard
  Delete all occurrences of a key in DLL      🟡
  Find pairs with given sum in DLL            🟡  ← two pointer on DLL
  Remove duplicates from sorted DLL           🟢

CLUSTER 7 — Merge / Sort
  Add two numbers as LLs                      🟡
  Sort LL (merge sort)                        🔴  ← find mid + merge

CLUSTER 8 — Intersection and Clone
  Intersection of two LLs                     🔴  ← redirect trick
  Clone LL with random pointer                🔴  ← interleave trick

CLUSTER 9 — Hard
  Rotate a LL                                 🟡
  Flattening a LL                             🔴  ← recursive merge pattern
```

---

## 6.1 — Learn 1D LinkedList

---

### 1. Introduction to Singly LL / Insert at Head  🟢

**Core Idea:** A node holds `val` and `next`. Insert at head: new node's `next = head`, update head pointer. Traversal: walk `curr = curr.next` until `curr == null`.

**Revise?** No — atomic building block. But internalize the dummy-head pattern here; it will be used constantly from problem 8 onward.

| Platform | Link |
|---|---|
| GFG | [GFG — Introduction to Linked List](https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/linked-list/linked-list-introduction) |

---

### 2. Insertion at the Head of a Linked List  🟢

**Core Idea:** Create new node, set `new_node.next = head`, return new_node as new head.

**Revise?** No — one operation.

| Platform | Link |
|---|---|
| Article | [takeUforward](https://takeuforward.org/linked-list/insert-at-the-head-of-a-linked-list) |

---

### 3. Deletion of the Head of LL  🟢

**Core Idea:** `head = head.next`. Handle empty list. This single pointer move is the atomic delete step used in LRU Cache (Step 9) and DLL problems.

**Revise?** No.

| Platform | Link |
|---|---|
| LeetCode | [LC 237 — Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/) |
| GFG | [GFG — Delete Node](https://www.geeksforgeeks.org/problems/delete-a-node-in-singly-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/delete-last-node-of-linked-list/) |

---

### 4. Find the Length of a Linked List  🟢

**Core Idea:** Walk from head counting nodes until `curr == null`. O(n).

**Revise?** No.

| Platform | Link |
|---|---|
| GFG | [GFG — Count Nodes in LL](https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/linked-list/find-the-length-of-a-linked-list) |

---

### 5. Search in a Linked List  🟢

**Core Idea:** Linear traversal, check each node's value. Return node or index when found.

**Revise?** No.

| Platform | Link |
|---|---|
| Article | [takeUforward](https://takeuforward.org/linked-list/search-an-element-in-a-linked-list) |

---

## 6.2 — Learn Doubly LinkedList

---

### 6. Introduction to DLL / Insert Before Head  🟢

**Core Idea:** Each node has `prev` and `next`. Insert before head: new node's `next = head`, `head.prev = new_node`, new_node is the new head.

**Revise?** No — but understand that DLL's `prev` pointer is what enables O(1) deletion in LRU Cache (Step 9).

| Platform | Link |
|---|---|
| GFG | [GFG — Introduction to DLL](https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/linked-list/introduction-to-doubly-linked-list) |

---

### 7. Delete Head of Doubly Linked List  🟢

**Core Idea:** `head = head.next`, then `head.prev = null`. Handle single-node edge case.

**Revise?** No — but this exact delete is the atomic step inside LRU Cache.

| Platform | Link |
|---|---|
| Article | [takeUforward](https://takeuforward.org/data-structure/delete-last-node-of-a-doubly-linked-list/) |

---

### 8. Reverse a Doubly Linked List  🟡

**Core Idea:** For each node, swap its `prev` and `next` pointers. After the loop, old tail becomes new head.

**Why revise:** Reversing a DLL requires swapping both pointers per node — different from SLL reversal where only `next` is touched. Easy to forget under pressure.

| Platform | Link |
|---|---|
| GFG | [GFG — Reverse DLL](https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/reverse-a-doubly-linked-list/) |

---

## 6.3 — Medium Problems of LL

---

### 9. Find the Middle of a Linked List  🔴

**Core Idea:** Slow/fast pointer. `slow` moves 1 step, `fast` moves 2 steps. When `fast` reaches end, `slow` is at the middle.

**Why revise:** SLOW/FAST ANCHOR. This exact setup is reused in cycle detection, palindrome check, delete middle, and sort LL. Must be automatic.

```
slow, fast = head, head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
# slow is now at middle
```

| Platform | Link |
|---|---|
| LeetCode | [LC 876 — Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) |
| GFG | [GFG — Finding Middle Element](https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/) |

---

### 10. Reverse a Linked List (Iterative)  🔴

**Core Idea:** Three-pointer iterative reversal — `prev = null`, `curr = head`. For each node: store `nxt`, set `curr.next = prev`, advance `prev = curr`, `curr = nxt`. When `curr == null`, `prev` is the new head.

**Why revise:** REVERSAL ANCHOR. This skeleton is directly reused in palindrome check, reverse between L-R, and reverse in K-group. Must be writable in under 60 seconds.

```
prev, curr = None, head
while curr:
    nxt = curr.next
    curr.next = prev
    prev = curr
    curr = nxt
return prev
```

| Platform | Link |
|---|---|
| LeetCode | [LC 206 — Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) |
| GFG | [GFG — Reverse a Linked List](https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/reverse-a-linked-list/) |

---

### 11. Reverse a Linked List (Recursive)  🟡

**Core Idea:** Base case: single node returns itself. Recursive case: reverse the rest, then `head.next.next = head`, `head.next = null`. Return new head from the deepest call.

**Why revise:** The recursive style is asked separately in interviews. The "hook the tail back" step (`head.next.next = head`) is the non-obvious part.

| Platform | Link |
|---|---|
| LeetCode | [LC 206 — Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) |
| GFG | [GFG — Reverse a Linked List](https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/reverse-a-linked-list/) |

---

### 12. Detect a Cycle in a Linked List  🔴

**Core Idea:** Floyd's cycle detection. Same slow/fast setup as problem 9. If `slow == fast` at any point, a cycle exists. If `fast` reaches null, no cycle.

**Why revise:** Floyd's is non-trivial — why do slow and fast necessarily meet inside the cycle? The mathematical proof is the insight. Problem 13 depends entirely on this.

```
slow, fast = head, head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
    if slow == fast: return True
return False
```

| Platform | Link |
|---|---|
| LeetCode | [LC 141 — Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) |
| GFG | [GFG — Detect Loop in LL](https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/) |

---

### 13. Find the Starting Point of a Cycle  🔴

**Core Idea:** Phase 1: detect meeting point using Floyd's (problem 12). Phase 2: move one pointer back to head, keep other at meeting point. Advance both 1 step at a time — they meet at the cycle entry node.

**Why revise:** Phase 2 is elegant but non-obvious. The proof — distance from head to entry equals distance from meeting point to entry — is what interviewers ask you to explain.

```
# After Floyd's phase 1 (slow == fast):
slow = head
while slow != fast:
    slow = slow.next
    fast = fast.next
# slow == fast == cycle entry node
```

| Platform | Link |
|---|---|
| LeetCode | [LC 142 — Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) |
| GFG | [GFG — First Node of Loop](https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/) |

---

### 14. Length of Loop in LL  🟡

**Core Idea:** After finding the meeting point (Floyd's phase 1), keep one pointer fixed and advance the other until they meet again. Count steps — that is the cycle length.

**Why revise:** Trivial extension of problem 12. Do immediately after 12 and 13 in one session.

| Platform | Link |
|---|---|
| GFG | [GFG — Length of Loop](https://www.geeksforgeeks.org/problems/find-length-of-loop/1) |
| Article | [takeUforward](https://takeuforward.org/linked-list/length-of-loop-in-linked-list) |

---

### 15. Check if LL is Palindrome  🔴

**Core Idea:** Three steps chained:
1. Find middle using slow/fast
2. Reverse the second half in-place
3. Compare first half and reversed second half node by node

**Why revise:** This is the first problem that chains multiple LL techniques. If any of the three steps is shaky, the whole thing breaks. Very common interview problem.

| Platform | Link |
|---|---|
| LeetCode | [LC 234 — Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) |
| GFG | [GFG — Check if LL is Palindrome](https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/) |

---

### 16. Segregate Odd and Even Nodes in LL  🔴

**Core Idea:** Two-chain partition using index parity (odd-indexed vs even-indexed nodes — NOT odd/even values). Maintain two pointers: `odd` chain and `even` chain. Interleave them as you traverse. Append even chain to the end of odd chain.

**Why revise:** Two-chain partition is a fundamental pattern — the same structure appears in Sort 0s/1s/2s (three chains) and Flattening (merge chains). The "reconnect at end" step is easy to forget.

```
if not head: return head
odd, even = head, head.next
even_head = even
while even and even.next:
    odd.next = even.next
    odd = odd.next
    even.next = odd.next
    even = even.next
odd.next = even_head
return head
```

| Platform | Link |
|---|---|
| LeetCode | [LC 328 — Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) |
| GFG | [GFG — Segregate Odd and Even Nodes](https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/segregate-even-and-odd-nodes-in-linkedlist) |

---

### 17. Remove Nth Node from the End of a List  🔴

**Core Idea:** Move `fast` pointer N steps ahead. Then advance both `slow` and `fast` together until `fast.next == null`. `slow` is now at the node before the target. Rewire `slow.next = slow.next.next`. Use a dummy head to handle removing the actual head.

**Why revise:** Fast-N-ahead technique is the clean O(n) one-pass solution. The dummy node for head-deletion edge case is the implementation detail that trips people up.

```
dummy = ListNode(0, head)
fast, slow = dummy, dummy
for _ in range(n): fast = fast.next
while fast.next:
    fast = fast.next
    slow = slow.next
slow.next = slow.next.next
return dummy.next
```

| Platform | Link |
|---|---|
| LeetCode | [LC 19 — Remove Nth Node From End](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) |
| GFG | [GFG — Nth Node from End](https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/) |

---

### 18. Delete the Middle Node of LL  🔴

**Core Idea:** Slow/fast pointer to find the node just before the middle. Set `prev.next = prev.next.next`. For even-length lists, delete the second of the two middle nodes (per LC definition).

**Why revise:** Direct slow/fast application but with a twist — you need the node BEFORE the middle, so start `fast` two steps ahead or maintain a `prev` pointer alongside `slow`.

```
dummy = ListNode(0, head)
slow, fast = dummy, head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
slow.next = slow.next.next
return dummy.next
```

| Platform | Link |
|---|---|
| LeetCode | [LC 2095 — Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) |
| GFG | [GFG — Delete Middle Node](https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/linked-list/delete-the-middle-node-of-the-linked-list) |

---

### 19. Sort LL  🔴

**Core Idea:** Merge sort on LL. Find middle (slow/fast), split into two halves, recursively sort each, merge the two sorted halves. O(n log n).

**Why revise:** Chains three techniques: find-middle + reversal understanding + merge-two-sorted-LLs. If any one is shaky, the whole thing breaks. Also directly asked in interviews that care about space complexity.

```
def sortList(head):
    if not head or not head.next: return head
    mid = findMid(head)         # slow/fast, break link at mid
    left = sortList(head)
    right = sortList(mid)
    return merge(left, right)
```

| Platform | Link |
|---|---|
| LeetCode | [LC 148 — Sort List](https://leetcode.com/problems/sort-list/) |
| GFG | [GFG — Sort a Linked List](https://www.geeksforgeeks.org/problems/sort-a-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/linked-list/sort-a-linked-list) |

---

### 20. Sort a LL of 0s, 1s, and 2s  🟡

**Core Idea:** Three-chain partition (Dutch Flag on LL). Maintain separate heads for 0s, 1s, 2s. Traverse once, append each node to its chain. Reconnect: `0_tail → 1_head`, `1_tail → 2_head`. Don't modify values, only rearrange links.

**Why revise:** The three-chain reconnection and handling empty chains (e.g., no 1s) are implementation details worth practising once.

| Platform | Link |
|---|---|
| LeetCode | [LC 148 variant](https://leetcode.com/problems/sort-list/) *(general sort, but use partition for 0/1/2)* |
| GFG | [GFG — Sort LL of 0s 1s 2s](https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/sort-a-linked-list-of-0s-1s-and-2s-by-changing-links) |

---

### 21. Find Intersection of Two Linked Lists  🔴

**Core Idea:** Two pointers `a` and `b`. When either reaches null, redirect to the other list's head. They meet at the intersection node (or both reach null simultaneously if no intersection). Works because both traverse `len(A) + len(B)` nodes total.

**Why revise:** The redirect trick is elegant and non-obvious. Frequently asked.

```
a, b = headA, headB
while a != b:
    a = a.next if a else headB
    b = b.next if b else headA
return a
```

| Platform | Link |
|---|---|
| LeetCode | [LC 160 — Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) |
| GFG | [GFG — Intersection of Two LL](https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/) |

---

### 22. Add One to a Number Represented by LL  🟡

**Core Idea:** Reverse the LL, add 1 with carry propagation, reverse back. Or: find the rightmost non-9 digit, increment it, set all digits after it to 0.

**Why revise:** The reverse-add-reverse pattern also appears in Add Two Numbers. The carry propagation across multiple nodes is the part that needs careful implementation.

| Platform | Link |
|---|---|
| GFG | [GFG — Add One to LL](https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/add-1-to-a-number-represented-by-ll) |

---

### 23. Add Two Numbers Represented as Linked Lists  🟡

**Core Idea:** Traverse both lists simultaneously, add digits with carry. Create new nodes for each result digit. If carry remains after both lists, add a final node.

**Why revise:** Simultaneous traversal of lists of different lengths + carry propagation. Use a dummy head for clean output construction.

| Platform | Link |
|---|---|
| LeetCode | [LC 2 — Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) |
| GFG | [GFG — Add Two Numbers as LL](https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/) |

---

## 6.4 — Medium Problems of DLL

---

### 24. Delete All Occurrences of a Key in DLL  🟡

**Core Idea:** Traverse the DLL. When a node with the target key is found, rewire both `prev.next` and `next.prev` around it, then delete the node. Handle head deletion by updating the head pointer.

**Why revise:** DLL deletion requires updating both direction pointers. Missing either one corrupts the list. The head-deletion edge case is the most common bug.

| Platform | Link |
|---|---|
| GFG | [GFG — Delete Occurrences in DLL](https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/delete-all-occurrences-of-a-key-in-dll) |

---

### 25. Find Pairs with Given Sum in Sorted DLL  🟡

**Core Idea:** Two pointers — `left` at head, `right` at tail. Move inward based on sum comparison. O(n) because DLL allows backward traversal with `prev`.

**Why revise:** DLL two-pointer mirrors the sorted array two-pointer. Only works because of the `prev` pointer — a good demonstration of why DLL beats SLL for certain problems.

| Platform | Link |
|---|---|
| GFG | [GFG — Pairs with Given Sum in DLL](https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/find-pairs-with-given-sum-in-doubly-linked-list) |

---

### 26. Remove Duplicates from Sorted DLL  🟢

**Core Idea:** Traverse pairs. If `curr.val == curr.next.val`, bypass `curr.next` by updating both `curr.next` and the successor's `prev`. Else advance.

**Revise?** No — same pattern as Remove Duplicates from Sorted Array/SLL, just with two-direction pointer updates.

| Platform | Link |
|---|---|
| GFG | [GFG — Remove Duplicates from Sorted DLL](https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/remove-duplicates-from-sorted-dll) |

---

## 6.5 — Hard Problems of LL

---

### 27. Reverse Nodes in K-Group  🔴

**Core Idea:** Check if at least K nodes remain. If yes: reverse K nodes (three-pointer skeleton), recurse on the rest, reconnect. If no: return head as-is (don't reverse incomplete group).

**Why revise:** The "check K nodes available before reversing" step and the reconnection logic (tail of reversed group points to head of next recursion) are both easy to get wrong. Asked at top-tier companies.

```
def reverseKGroup(head, k):
    node, count = head, 0
    while node and count < k: node = node.next; count += 1
    if count < k: return head
    prev, curr = None, head
    for _ in range(k):
        nxt = curr.next; curr.next = prev; prev = curr; curr = nxt
    head.next = reverseKGroup(curr, k)
    return prev
```

| Platform | Link |
|---|---|
| LeetCode | [LC 25 — Reverse Nodes in K-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) |
| GFG | [GFG — Reverse LL in Groups of K](https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/) |

---

### 28. Rotate a Linked List  🟡

**Core Idea:** Find length and tail. Effective rotation = `k % length`. Walk to node at position `length - k`, set it as new tail (cut link), connect old tail to head. Return new head.

**Why revise:** The `k % length` normalisation and "walk to pivot" step have easy off-by-one bugs. Finicky implementation.

| Platform | Link |
|---|---|
| LeetCode | [LC 61 — Rotate List](https://leetcode.com/problems/rotate-list/) |
| GFG | [GFG — Rotate a LL](https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/rotate-a-linked-list/) |

---

### 29. Flatten a Linked List (Next + Down Pointers)  🔴

**Core Idea:** Each node has `next` and `down`. Recursively flatten the `next` chain, then merge the current `down` column with the already-flattened result using merge-two-sorted-LLs. Result is always on the `down` axis.

**Why revise:** Combines recursion + merge-two-sorted in a 2D structure. The "flatten next first, then merge with current down" order is non-obvious. Pointer-heavy and appears in interviews.

| Platform | Link |
|---|---|
| GFG | [GFG — Flattening a LL](https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/flattening-a-linked-list/) |

---

### 30. Clone a Linked List with Random Pointer  🔴

**Core Idea — Interleave trick (O(1) space):**
1. Insert clone nodes between originals: `1→1'→2→2'→3→3'`
2. Wire `random` pointers: `clone.random = curr.random.next`
3. Separate the two lists

**Why revise:** The interleave approach is the space-optimal O(1) solution interviewers expect. The three-pass structure must be clean. Frequently asked.

```
# Pass 1: interleave clones
curr = head
while curr:
    clone = ListNode(curr.val, curr.next)
    curr.next = clone
    curr = clone.next

# Pass 2: wire random
curr = head
while curr:
    if curr.random:
        curr.next.random = curr.random.next
    curr = curr.next.next

# Pass 3: separate
dummy = ListNode(0)
clone_curr = dummy
curr = head
while curr:
    clone_curr.next = curr.next
    curr.next = curr.next.next
    curr = curr.next
    clone_curr = clone_curr.next
return dummy.next
```

| Platform | Link |
|---|---|
| LeetCode | [LC 138 — Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) |
| GFG | [GFG — Clone LL with Random Pointer](https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/) |

---

## Full Problem Table

| # | Problem | Sub-step | Difficulty | Tier | Pattern | LeetCode | GFG |
|---|---|---|---|---|---|---|---|
| 1 | Intro to SLL / Insert at Head | 6.1 | Easy | 🟢 | Pointer rewire | — | [GFG](https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1) |
| 2 | Insertion at Head | 6.1 | Easy | 🟢 | Pointer rewire | — | — |
| 3 | Deletion of Head | 6.1 | Easy | 🟢 | Pointer rewire | [LC 237](https://leetcode.com/problems/delete-node-in-a-linked-list/) | [GFG](https://www.geeksforgeeks.org/problems/delete-a-node-in-singly-linked-list/1) |
| 4 | Find Length of LL | 6.1 | Easy | 🟢 | Traversal | — | [GFG](https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1) |
| 5 | Search in LL | 6.1 | Medium | 🟢 | Traversal | — | — |
| 6 | Intro to DLL / Insert Before Head | 6.2 | Easy | 🟢 | DLL pointer rewire | — | [GFG](https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1) |
| 7 | Delete Head of DLL | 6.2 | Easy | 🟢 | DLL pointer rewire | — | — |
| 8 | Reverse a DLL | 6.2 | Medium | 🟡 | Swap prev/next | — | [GFG](https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1) |
| 9 | Find Middle of LL | 6.3 | Easy | 🔴 | Slow/fast pointer | [LC 876](https://leetcode.com/problems/middle-of-the-linked-list/) | [GFG](https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1) |
| 10 | Reverse a LL (Iterative) | 6.3 | Medium | 🔴 | Three-pointer reversal | [LC 206](https://leetcode.com/problems/reverse-linked-list/) | [GFG](https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1) |
| 11 | Reverse a LL (Recursive) | 6.3 | Medium | 🟡 | Recursive reversal | [LC 206](https://leetcode.com/problems/reverse-linked-list/) | [GFG](https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1) |
| 12 | Detect Cycle in LL | 6.3 | Medium | 🔴 | Floyd's algorithm | [LC 141](https://leetcode.com/problems/linked-list-cycle/) | [GFG](https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1) |
| 13 | Find Starting Point of Cycle | 6.3 | Medium | 🔴 | Floyd's phase 2 | [LC 142](https://leetcode.com/problems/linked-list-cycle-ii/) | [GFG](https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1) |
| 14 | Length of Loop in LL | 6.3 | Medium | 🟡 | Floyd's extension | — | [GFG](https://www.geeksforgeeks.org/problems/find-length-of-loop/1) |
| 15 | Check if LL is Palindrome | 6.3 | Medium | 🔴 | Mid + Reverse + Compare | [LC 234](https://leetcode.com/problems/palindrome-linked-list/) | [GFG](https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1) |
| 16 | Segregate Odd and Even Nodes | 6.3 | Medium | 🔴 | Two-chain partition | [LC 328](https://leetcode.com/problems/odd-even-linked-list/) | [GFG](https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1) |
| 17 | Remove Nth Node from End | 6.3 | Medium | 🔴 | Fast N-ahead trick | [LC 19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [GFG](https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1) |
| 18 | Delete Middle Node | 6.3 | Medium | 🔴 | Slow/fast + prev | [LC 2095](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) | [GFG](https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1) |
| 19 | Sort LL | 6.3 | Hard | 🔴 | Merge sort on LL | [LC 148](https://leetcode.com/problems/sort-list/) | [GFG](https://www.geeksforgeeks.org/problems/sort-a-linked-list/1) |
| 20 | Sort LL of 0s, 1s, 2s | 6.3 | Medium | 🟡 | Three-chain partition | — | [GFG](https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1) |
| 21 | Intersection of Two LLs | 6.3 | Medium | 🔴 | Redirect trick | [LC 160](https://leetcode.com/problems/intersection-of-two-linked-lists/) | [GFG](https://www.geeksforgeeks.org/problems/intersection-of-two-linked-list/1) |
| 22 | Add One to LL | 6.3 | Medium | 🟡 | Reverse + carry | — | [GFG](https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1) |
| 23 | Add Two Numbers as LLs | 6.3 | Medium | 🟡 | Carry + dummy node | [LC 2](https://leetcode.com/problems/add-two-numbers/) | [GFG](https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1) |
| 24 | Delete All Occurrences of Key in DLL | 6.4 | Hard | 🟡 | DLL traversal + rewire | — | [GFG](https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1) |
| 25 | Pairs with Given Sum in Sorted DLL | 6.4 | Medium | 🟡 | Two pointer (DLL) | — | [GFG](https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1) |
| 26 | Remove Duplicates from Sorted DLL | 6.4 | Hard | 🟢 | Traversal + skip | — | [GFG](https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1) |
| 27 | Reverse Nodes in K-Group | 6.5 | Hard | 🔴 | Count + Reverse + Recurse | [LC 25](https://leetcode.com/problems/reverse-nodes-in-k-group/) | [GFG](https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1) |
| 28 | Rotate a LL | 6.5 | Hard | 🟡 | Find tail + reconnect | [LC 61](https://leetcode.com/problems/rotate-list/) | [GFG](https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1) |
| 29 | Flatten a LL (next + down) | 6.5 | Hard | 🔴 | Recursive merge | — | [GFG](https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1) |
| 30 | Clone LL with Random Pointer | 6.5 | Hard | 🔴 | Interleave trick | [LC 138](https://leetcode.com/problems/copy-list-with-random-pointer/) | [GFG](https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1) |

> **Moved to other steps:**
> - Merge Two Sorted LLs → Step 11 Heaps (merge anchor covered there)
> - Merge K Sorted LLs → Step 11 Heaps
> - LRU Cache → Step 9 Stack & Queues

---

## Pattern Quick Reference

### Three-Pointer Reversal (Iterative)
```
prev, curr = None, head
while curr:
    nxt = curr.next
    curr.next = prev
    prev = curr
    curr = nxt
return prev   # new head
```

### Slow / Fast Pointer (Find Middle)
```
slow, fast = head, head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
# slow = middle node
```

### Floyd's Cycle Detection
```
# Phase 1 — find meeting point
slow, fast = head, head
while fast and fast.next:
    slow = slow.next; fast = fast.next.next
    if slow == fast: break

# Phase 2 — find entry node
slow = head
while slow != fast:
    slow = slow.next; fast = fast.next
# slow == fast == cycle entry
```

### Dummy Node Pattern
```
dummy = ListNode(0)
dummy.next = head
# operate freely, handles head-modification edge cases
return dummy.next
```

### Fast N-Ahead (Remove Nth from End)
```
dummy = ListNode(0, head)
fast = slow = dummy
for _ in range(n): fast = fast.next
while fast.next:
    fast = fast.next; slow = slow.next
slow.next = slow.next.next
return dummy.next
```

### Two-Chain Partition (Odd/Even Segregation)
```
odd, even = head, head.next
even_head = even
while even and even.next:
    odd.next = even.next; odd = odd.next
    even.next = odd.next; even = even.next
odd.next = even_head
return head
```

### Clone with Interleave (O(1) space)
```
# Pass 1: interleave
curr = head
while curr:
    curr.next = ListNode(curr.val, curr.next)
    curr = curr.next.next

# Pass 2: wire random
curr = head
while curr:
    if curr.random: curr.next.random = curr.random.next
    curr = curr.next.next

# Pass 3: separate
curr, clone = head, head.next
clone_head = clone
while curr:
    curr.next = curr.next.next
    clone.next = clone.next.next if clone.next else None
    curr = curr.next; clone = clone.next
```

---

## What These Patterns Unlock Later

| Pattern | Reappears in |
|---|---|
| Three-pointer reversal | Trees (BST rotation), Graph adjacency rewiring |
| Slow / fast pointer | Tree traversal (find Kth element in BST) |
| Floyd's cycle detection | Functional graphs, Step 15 Graphs |
| Dummy node | Trees (dummy root for BST insert), any list-building |
| Two-chain partition | Step 9 Stacks (monotonic stack partitioning) |
| Merge two sorted | Step 11 Heaps (external sort, merge K via heap) |
| DLL + O(1) operations | Step 9 Stack & Queues — LRU Cache, LFU Cache |

---

## Revision Sessions

### Before a Contest
Only 🔴: **9, 10, 12, 13, 15, 16, 17, 18, 19, 21, 27, 29, 30**
These are the patterns most likely to appear in disguise in contest problems.

### Before an Interview
All 🔴 + 🟡. Emphasis on: **27 (K-group reversal)**, **30 (clone with random)**, **29 (flatten)**, **16 (odd-even segregation)** — the four most commonly probed hard LL problems.

### Periodic Revision (every 2-3 weeks)
Problems where implementation details fade fastest: **13 (Floyd's phase 2)**, **27 (K-group reconnection)**, **30 (three-pass interleave)**, **16 (chain reconnect at end)**.

---

## Resources

| Resource | Link |
|---|---|
| Striver's A2Z Sheet (updated) | [takeuforward.org](https://takeuforward.org/prep-hub/strivers-a2z-dsa-sheet) |
| YouTube — LL Playlist | [takeUforward Channel](https://www.youtube.com/@takeUforward) |
| takeUforward LL Articles | [takeuforward.org/linked-list](https://takeuforward.org/blogs/linked-list) |
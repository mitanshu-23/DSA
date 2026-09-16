# Striver's A2Z DSA Sheet — Step 5: Strings (Basic & Medium)

> **Source:** [takeuforward.org — Striver's A2Z DSA Sheet](https://takeuforward.org/dsa/strivers-a2z-sheet-learn-dsa-a-to-z)
> **YouTube:** [takeUforward Channel](https://www.youtube.com/@takeUforward)
> **Total Problems:** 15 (7 Easy + 8 Medium)
> **Sub-steps:** 5.1 Basic and Easy (7) · 5.2 Medium (8)
> **Step 18 (Advanced Strings):** Deferred — do after Tries and DP

---

## Revision Tier Legend

| Tag | Meaning | When to revisit |
|---|---|---|
| 🔴 MUST | Core pattern. High interview frequency. Skipping costs you downstream. | Every revision cycle. |
| 🟡 IMPORTANT | Strong trick, reusable. Worth revisiting before interviews. | Before interviews / contests. |
| 🟢 GOOD TO KNOW | Solve once. Low frequency or derivable from a 🔴 problem. | Only when time allows. |

**Quick 🔴 revision list:** 2, 5, 6, 7, 11, 13
Only 6 out of 15 — Strings is a short step. The real weight comes in Step 18 later.

---

## What Is New in Strings vs Arrays?

Strings are character arrays with extra constraints. Almost every technique from Arrays carries over directly:

| Array technique | Strings version |
|---|---|
| Two pointers | Palindrome check, reverse words |
| HashMap / freq map | Anagram, isomorphic, sort by frequency |
| Sliding window | Substrings with K distinct chars |
| In-place reversal | Reverse words in string |
| Prefix + hashmap | Count substrings |

The one genuinely new thing in Step 5 is the **26-slot character frequency array** — a faster, fixed-size alternative to a hashmap when the alphabet is lowercase ASCII. Everything else is a string-flavoured application of what you already know.

> Step 18 (KMP, Z-function, Rabin-Karp) introduces truly new algorithms. That comes much later — after Tries and DP.

---

## Smart Solve Order — Correlation Clusters

```
CLUSTER 1 — Basic String Ops (warm-up)
  Remove outermost parentheses                🟢
  Largest odd number in a string              🟢
  Maximum nesting depth of parentheses        🟢  ← same depth counter as #1

CLUSTER 2 — Two Pointer / Reversal
  Reverse words in a string / Palindrome      🔴  ← two-pointer + reversal trick
  Reverse every word in a string              🟡  ← different from above, easy to confuse

CLUSTER 3 — Character Mapping / Hashing
  Isomorphic strings                          🔴  ← bijective mapping anchor
  Check if two strings are anagram            🔴  ← 26-slot freq array anchor
  Sort characters by frequency                🟡  ← freq + sort, extends above

CLUSTER 4 — String Identity / Rotation
  Longest common prefix                       🟡
  Check if one string is rotation of another  🔴  ← s+s concatenation trick

CLUSTER 5 — Parsing / Simulation
  Roman number to integer and vice versa      🟡
  Implement atoi                              🔴  ← edge-case heavy parsing

CLUSTER 6 — Substring Problems
  Count number of substrings (K distinct)     🟡  ← atmost K trick
  Longest palindromic substring               🔴  ← expand around center
  Sum of beauty of all substrings             🟢
```

### Why this order

- **Problems 1 and 9 (parenthesis depth)** use the same depth counter. Doing them together takes 10 minutes total.
- **Isomorphic (5) and Anagram (7)** are both character-mapping problems but with different structures — bijective map vs frequency array. Doing them back-to-back makes the difference clear.
- **Reverse word order (2) vs reverse each word (15)** are easy to confuse in an interview. Do them together so the distinction is sharp.
- **atoi (11)** is pure edge-case handling. Do it when your mind is fresh, not at the end of a session.

---

## 5.1 — Basic and Easy String Problems

---

### 1. Remove Outermost Parentheses  🟢

**Core Idea:** Track depth with a counter. Characters at depth > 0 when opening, or depth > 1 when closing, are not outermost — include them. Increment depth on `(`, decrement on `)`.

| Platform | Link |
|---|---|
| LeetCode | [LC 1021 — Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/) |
| GFG | [GFG — Remove Outermost Parentheses](https://www.geeksforgeeks.org/remove-outermost-parentheses/) |
| Article | [takeUforward](https://takeuforward.org/data-structure/remove-outermost-parentheses/) |

---

### 2. Reverse Words in a String / Palindrome Check  🔴

**Core Idea (Reverse word order):** Reverse the entire string, then reverse each word individually. Handles multiple spaces cleanly.
**Core Idea (Palindrome):** Two pointers from both ends — compare `s[lo]` and `s[hi]`, walk inward.

**Why revise:** The "reverse all, then reverse each word" trick reuses the Array reversal template and is an interview classic. Two-pointer palindrome is the building block for problem 13 (Longest Palindromic Substring).

```
Step 1: reverse entire string
Step 2: for each word boundary, reverse the word in-place
Step 3: clean up extra spaces
```

| Platform | Link |
|---|---|
| LeetCode | [LC 151 — Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) |
| LeetCode | [LC 125 — Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) |
| GFG | [GFG — Reverse Words in String](https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string1946/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/reverse-words-in-a-string/) |

---

### 3. Largest Odd Number in a String  🟢

**Core Idea:** Scan from the right. Return the prefix ending at the first odd digit found. If no odd digit exists, return empty string.

| Platform | Link |
|---|---|
| LeetCode | [LC 1903 — Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/) |
| GFG | [GFG — Largest Odd Number in String](https://www.geeksforgeeks.org/problems/largest-odd-number-in-string/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/largest-odd-number-in-string/) |

---

### 4. Longest Common Prefix  🟡

**Core Idea:** Take the first string as the candidate prefix. For each subsequent string, shrink the prefix until the string starts with it. O(n * m) where m is the current prefix length.

**Why revise:** LCP reappears in Trie problems (Step 17) — a Trie is essentially the optimal data structure for computing LCPs across many strings. Worth one revisit before that step.

| Platform | Link |
|---|---|
| LeetCode | [LC 14 — Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) |
| GFG | [GFG — Longest Common Prefix](https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/longest-common-prefix/) |

---

### 5. Isomorphic Strings  🔴

**Core Idea:** Maintain two maps: `s_char → t_char` and `t_char → s_char`. For each pair, enforce consistency in both directions. If a character maps to two different targets, return false.

**Why revise:** One-way mapping misses cases like `s="ab", t="aa"` (both chars map to 'a', but 'a' in t can only map back to one char). The bijective (two-way) check is the insight. Same pattern reappears in Word Pattern (LC 290).

```
For each (sc, tc) pair:
    if sc in s_map and s_map[sc] != tc: return False
    if tc in t_map and t_map[tc] != sc: return False
    s_map[sc] = tc
    t_map[tc] = sc
```

| Platform | Link |
|---|---|
| LeetCode | [LC 205 — Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/) |
| GFG | [GFG — Isomorphic Strings](https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/check-if-two-strings-are-isomorphic/) |

---

### 6. Check if One String is a Rotation of Another  🔴

**Core Idea:** `t` is a rotation of `s` if and only if `t` is a substring of `s + s`. Use any substring check. O(n).

**Why revise:** The `s + s` concatenation trick is non-obvious and elegant. It reappears in Repeated String Match (LC 686), circular array problems, and as an application problem for KMP/Z-function in Step 18.

```
t is rotation of s  ⟺  len(t) == len(s)  AND  t in (s + s)
```

| Platform | Link |
|---|---|
| LeetCode | [LC 796 — Rotate String](https://leetcode.com/problems/rotate-string/) |
| GFG | [GFG — Check if Strings are Rotations](https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/check-if-one-string-is-a-rotation-of-another-string/) |

---

### 7. Check if Two Strings are Anagram  🔴

**Core Idea:** 26-slot frequency array. Increment for each char in `s`, decrement for each char in `t`. If all 26 slots are 0 at the end, they are anagrams. O(n).

**Why revise:** The 26-slot array is the standard string hashing tool for lowercase ASCII — faster and simpler than a hashmap. This exact pattern is used in Group Anagrams, Find All Anagrams in a String (sliding window), and Minimum Window Substring.

```
freq = [0] * 26
for c in s: freq[ord(c) - ord('a')] += 1
for c in t: freq[ord(c) - ord('a')] -= 1
return all(f == 0 for f in freq)
```

| Platform | Link |
|---|---|
| LeetCode | [LC 242 — Valid Anagram](https://leetcode.com/problems/valid-anagram/) |
| GFG | [GFG — Check Anagrams](https://www.geeksforgeeks.org/problems/anagram-1587115620/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/check-if-two-strings-are-anagram-of-each-other/) |

---

## 5.2 — Medium String Problems

---

### 8. Sort Characters by Frequency  🟡

**Core Idea:** Build frequency map. Sort characters by frequency descending. Reconstruct string by repeating each character its count times.

**Why revise:** Frequency + sort is the same idea as Top K Frequent Elements (Arrays) and Reorganize String (Greedy). Worth revisiting before the Heaps chapter where bucket sort / priority queue becomes the preferred approach.

| Platform | Link |
|---|---|
| LeetCode | [LC 451 — Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/) |
| GFG | [GFG — Sort Characters by Frequency](https://www.geeksforgeeks.org/problems/sort-characters-by-frequency/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/sort-characters-by-frequency/) |

---

### 9. Maximum Nesting Depth of Parentheses  🟢

**Core Idea:** Same depth counter as problem 1. Increment on `(`, decrement on `)`. Track max depth reached.

**Revise?** No — if problem 1 is solid, this is a one-liner.

| Platform | Link |
|---|---|
| LeetCode | [LC 1614 — Maximum Nesting Depth of Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/) |
| GFG | [GFG — Max Nesting Depth](https://www.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/maximum-nesting-depth-of-parentheses/) |

---

### 10. Roman Number to Integer and Vice Versa  🟡

**Core Idea (Roman → Int):** Scan left to right. If current value < next value, subtract current (the subtractive case: IV, IX, XL, XC, CD, CM). Else add current.
**Core Idea (Int → Roman):** Greedy with a descending value-symbol table. Keep subtracting the largest fitting value and appending its symbol.

**Why revise:** Both are simulation problems. The subtractive case in Roman-to-Int is the only non-trivial part. Parsing/simulation problems show up in design and domain-specific interview rounds.

| Platform | Link |
|---|---|
| LeetCode | [LC 13 — Roman to Integer](https://leetcode.com/problems/roman-to-integer/) |
| LeetCode | [LC 12 — Integer to Roman](https://leetcode.com/problems/integer-to-roman/) |
| GFG | [GFG — Roman Number to Integer](https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/roman-number-to-integer-and-vice-versa/) |

---

### 11. Implement atoi  🔴

**Core Idea:** Four-step simulation:
1. Skip leading whitespace
2. Read optional `+` / `-` sign
3. Read digits until non-digit or end of string
4. Clamp result to `[INT_MIN, INT_MAX]`

**Why revise:** The edge cases ARE the problem — leading zeros, overflow before you finish reading, sign with no digits after it, empty string after trimming. A clean implementation demonstrates precise spec-following. Appears frequently in interviews testing attention to corner cases.

```
Overflow check (do this before multiplying):
  if result > INT_MAX // 10: return INT_MAX (or INT_MIN depending on sign)
  if result == INT_MAX // 10 and digit > 7: clamp
```

| Platform | Link |
|---|---|
| LeetCode | [LC 8 — String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/) |
| GFG | [GFG — Implement atoi](https://www.geeksforgeeks.org/problems/implement-atoi/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/implement-atoi/) |

---

### 12. Count Number of Substrings (with Exactly K Distinct Characters)  🟡

**Core Idea:** Directly counting "exactly K distinct" is hard. Use the identity:
`count(exactly K) = count(at most K) - count(at most K-1)`

"At most K distinct" is a standard sliding window. O(n).

**Why revise:** The `atmost(K) - atmost(K-1)` reduction is a reusable trick for any "exactly K" substring/subarray counting problem. Same idea appears in Count Subarrays with Exactly K Odd Numbers and Subarrays with K Different Integers (LC 992).

```
def atmost(s, k):
    freq = {}
    lo = 0
    result = 0
    for hi in range(len(s)):
        freq[s[hi]] = freq.get(s[hi], 0) + 1
        while len(freq) > k:
            freq[s[lo]] -= 1
            if freq[s[lo]] == 0: del freq[s[lo]]
            lo += 1
        result += hi - lo + 1
    return result

count_exactly_k = atmost(s, k) - atmost(s, k - 1)
```

| Platform | Link |
|---|---|
| LeetCode | [LC 992 — Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) *(same pattern)* |
| GFG | [GFG — Count Substrings with K Distinct](https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/count-substrings-with-k-different-characters/) |

---

### 13. Longest Palindromic Substring (Without DP)  🔴

**Core Idea:** Expand around center. For each index `i`, try two expansions — odd-length (center at `i`) and even-length (center between `i` and `i+1`). Expand outward while `s[lo] == s[hi]`. Track the widest window seen. O(n²) time, O(1) space.

**Why revise:** Expand-around-center is the preferred interview solution — simpler than Manacher's, no extra space unlike DP. The two-pass (odd + even) is easy to forget or implement incorrectly. This problem also connects directly to palindrome DP in the DP chapter.

```
best_lo, best_hi = 0, 0

def expand(lo, hi):
    while lo >= 0 and hi < n and s[lo] == s[hi]:
        lo -= 1
        hi += 1
    # palindrome is s[lo+1 .. hi-1]
    if hi - 1 - (lo + 1) > best_hi - best_lo:
        update best

for i in range(n):
    expand(i, i)      # odd length
    expand(i, i + 1)  # even length
```

| Platform | Link |
|---|---|
| LeetCode | [LC 5 — Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) |
| GFG | [GFG — Longest Palindromic Substring](https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/longest-palindromic-substring/) |

---

### 14. Sum of Beauty of All Substrings  🟢

**Core Idea:** For each starting index `i`, expand right maintaining a 26-slot frequency array. At each `j`, beauty = `max_freq - min_non_zero_freq`. Sum all beauties. O(n²) with O(26) space.

**Revise?** No — low interview frequency. Solve once to practice the character-frequency expansion pattern, then move on.

| Platform | Link |
|---|---|
| LeetCode | [LC 1781 — Sum of Beauty of All Substrings](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/) |
| GFG | [GFG — Sum of Beauty of All Substrings](https://www.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/sum-of-beauty-of-all-substrings/) |

---

### 15. Reverse Every Word in a String  🟡

**Core Idea:** Reverse each word's characters individually (not the word order). Split on spaces, reverse each token, rejoin. Or do it in-place using two pointers within each word boundary.

**Why revise:** Distinct from problem 2 which reverses word order. Confusing the two in an interview is common. Do problems 2 and 15 back to back and keep the distinction sharp.

| Platform | Link |
|---|---|
| LeetCode | [LC 557 — Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/) |
| GFG | [GFG — Reverse Each Word in String](https://www.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1) |
| Article | [takeUforward](https://takeuforward.org/data-structure/reverse-every-word-in-a-string/) |

---

## Full Problem Table

| # | Problem | Sub-step | Difficulty | Tier | Pattern | LeetCode | GFG |
|---|---|---|---|---|---|---|---|
| 1 | Remove Outermost Parentheses | 5.1 | Easy | 🟢 | Depth counter | [LC 1021](https://leetcode.com/problems/remove-outermost-parentheses/) | [GFG](https://www.geeksforgeeks.org/remove-outermost-parentheses/) |
| 2 | Reverse Words / Palindrome Check | 5.1 | Easy | 🔴 | Two pointer + Reversal | [LC 151](https://leetcode.com/problems/reverse-words-in-a-string/) [LC 125](https://leetcode.com/problems/valid-palindrome/) | [GFG](https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string1946/1) |
| 3 | Largest Odd Number in String | 5.1 | Easy | 🟢 | Right scan | [LC 1903](https://leetcode.com/problems/largest-odd-number-in-string/) | [GFG](https://www.geeksforgeeks.org/problems/largest-odd-number-in-string/1) |
| 4 | Longest Common Prefix | 5.1 | Easy | 🟡 | Shrink candidate | [LC 14](https://leetcode.com/problems/longest-common-prefix/) | [GFG](https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1) |
| 5 | Isomorphic Strings | 5.1 | Easy | 🔴 | Bijective mapping | [LC 205](https://leetcode.com/problems/isomorphic-strings/) | [GFG](https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1) |
| 6 | Rotate String (Rotation Check) | 5.1 | Easy | 🔴 | s+s concat trick | [LC 796](https://leetcode.com/problems/rotate-string/) | [GFG](https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1) |
| 7 | Check if Two Strings are Anagram | 5.1 | Easy | 🔴 | Freq array [26] | [LC 242](https://leetcode.com/problems/valid-anagram/) | [GFG](https://www.geeksforgeeks.org/problems/anagram-1587115620/1) |
| 8 | Sort Characters by Frequency | 5.2 | Medium | 🟡 | Freq + sort | [LC 451](https://leetcode.com/problems/sort-characters-by-frequency/) | [GFG](https://www.geeksforgeeks.org/problems/sort-characters-by-frequency/1) |
| 9 | Max Nesting Depth of Parentheses | 5.2 | Easy | 🟢 | Depth counter | [LC 1614](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/) | [GFG](https://www.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1) |
| 10 | Roman to Integer / Int to Roman | 5.2 | Medium | 🟡 | Greedy / Parsing | [LC 13](https://leetcode.com/problems/roman-to-integer/) [LC 12](https://leetcode.com/problems/integer-to-roman/) | [GFG](https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1) |
| 11 | Implement atoi | 5.2 | Medium | 🔴 | Parsing + edge cases | [LC 8](https://leetcode.com/problems/string-to-integer-atoi/) | [GFG](https://www.geeksforgeeks.org/problems/implement-atoi/1) |
| 12 | Count Substrings with K Distinct | 5.2 | Hard | 🟡 | AtMost K trick | [LC 992](https://leetcode.com/problems/subarrays-with-k-different-integers/) | [GFG](https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1) |
| 13 | Longest Palindromic Substring | 5.2 | Medium | 🔴 | Expand around center | [LC 5](https://leetcode.com/problems/longest-palindromic-substring/) | [GFG](https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1) |
| 14 | Sum of Beauty of All Substrings | 5.2 | Medium | 🟢 | O(n²) freq sweep | [LC 1781](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/) | [GFG](https://www.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings/1) |
| 15 | Reverse Every Word in a String | 5.2 | Medium | 🟡 | Per-word reversal | [LC 557](https://leetcode.com/problems/reverse-words-in-a-string-iii/) | [GFG](https://www.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1) |

---

## Pattern Quick Reference

### 26-Slot Frequency Array
```
freq = [0] * 26
for c in s: freq[ord(c) - ord('a')] += 1

Use instead of hashmap for lowercase-only strings.
Anagram check: build from s, decrement from t, check all zeros.
Window anagram: slide the window, update freq[out]-- and freq[in]++.
```

### Two-Pointer Palindrome
```
lo, hi = 0, len(s) - 1
while lo < hi:
    if s[lo] != s[hi]: return False
    lo += 1
    hi -= 1
return True
```

### Expand Around Center
```
for i in range(n):
    # odd length palindrome
    lo, hi = i, i
    while lo >= 0 and hi < n and s[lo] == s[hi]:
        lo -= 1; hi += 1
    # palindrome was s[lo+1 .. hi-1]

    # even length palindrome
    lo, hi = i, i + 1
    while lo >= 0 and hi < n and s[lo] == s[hi]:
        lo -= 1; hi += 1
    # palindrome was s[lo+1 .. hi-1]
```

### Rotation Check (s + s)
```
t is rotation of s  ⟺  len(t) == len(s)  AND  t in (s + s)
```

### Bijective Mapping (Isomorphic)
```
s_map, t_map = {}, {}
for sc, tc in zip(s, t):
    if s_map.get(sc, tc) != tc: return False
    if t_map.get(tc, sc) != sc: return False
    s_map[sc] = tc
    t_map[tc] = sc
return True
```

### AtMost K → Exactly K
```
count(exactly K distinct) = atmost(K) - atmost(K - 1)

def atmost(s, k):
    freq, lo, result = {}, 0, 0
    for hi in range(len(s)):
        freq[s[hi]] = freq.get(s[hi], 0) + 1
        while len(freq) > k:
            freq[s[lo]] -= 1
            if freq[s[lo]] == 0: del freq[s[lo]]
            lo += 1
        result += hi - lo + 1
    return result
```

### Reverse Word Order vs Reverse Each Word
```
"hello world"  →  "world hello"   # reverse word ORDER  (problem 2)
"hello world"  →  "olleh dlrow"   # reverse each WORD   (problem 15)
```

---

## What These Patterns Unlock Later

| Pattern | Reappears in |
|---|---|
| 26-slot freq array | Sliding Window step (Min Window Substring, Find All Anagrams) |
| Two-pointer palindrome | DP on strings (Palindromic Substrings, LCS variants) |
| Expand around center | DP chapter (palindrome DP), Manacher's (Step 18) |
| s+s rotation trick | Step 18 (KMP / Z-function applied to rotation) |
| AtMost K sliding window | Step 10 — Sliding Window & Two Pointer entire chapter |
| Bijective mapping | Word Pattern, Encode-Decode problems |
| Parsing (atoi, Roman) | Design rounds, OA rounds with spec-following problems |

---

## Revision Sessions

### Before a Contest
Only 🔴: **2 (reverse words), 5 (isomorphic), 6 (rotation), 7 (anagram), 11 (atoi), 13 (longest palindrome)**
These are the six patterns most likely to appear in a contest string problem.

### Before an Interview
All 🔴 + 🟡. Add emphasis on **13 (expand around center)** and **7 (freq array)** — the two most commonly asked string problems in product company interviews.

### Periodic Revision (while doing other topics)
Only the two that fade fastest under time pressure: **11 (atoi overflow logic)** and **13 (odd vs even center)**.

---

## What Comes Next

After Step 5 (Strings), the sheet goes:
- **Step 6 — Linked List** (31 problems)
- **Step 7 — Recursion & Backtracking** (25 problems)
- **Step 8 — Bit Manipulation** (18 problems)
- ...continuing until Step 17 (Tries)
- **Step 18 — Advanced Strings** (9 problems: KMP, Z-function, Rabin-Karp, Shortest Palindrome)

Step 18 is placed last intentionally — KMP and Z-function are most useful after you have seen Tries and understand prefix structures. When you reach Step 18, create a separate README for it.

---

## Resources

| Resource | Link |
|---|---|
| Striver's A2Z Sheet | [takeuforward.org](https://takeuforward.org/dsa/strivers-a2z-sheet-learn-dsa-a-to-z) |
| YouTube — Strings Playlist | [takeUforward Channel](https://www.youtube.com/@takeUforward) |
| takeUforward String Articles | [takeuforward.org/strings](https://takeuforward.org/category/data-structure/string/) |
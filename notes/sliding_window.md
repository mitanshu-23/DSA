# Sliding Window

## Non-Shrinking (Fixed-Width) Sliding Window

A variant of the sliding window for **maximum-length** problems with an "at most"
style constraint. Instead of a `while` loop that shrinks the window back to
validity, the left boundary moves **at most once per step** with a single `if`.
The window therefore **never shrinks** — it either grows by one or slides right by
one — and the answer is just the final window width.

### The idea

Classic (shrinking) window:

```text
for end in 0..n:
    include s[end]
    while window_invalid():      # <-- while: fully restore validity
        exclude s[start]; start += 1
    best = max(best, end - start + 1)
```

Non-shrinking window:

```text
for end in 0..n:
    include s[end]
    if window_invalid():         # <-- if: slide by exactly one, don't shrink
        exclude s[start]; start += 1
# answer = n - start             # final width == longest valid window
```

### Why it works (the key invariant)

Let `w = end - start + 1` be the current width.

- Every iteration does `end += 1` (+1 to width). We do `start += 1` (−1 to width)
  **only** on the `if` branch. So each step changes width by **+1** (no slide) or
  **0** (slide). ⇒ **`w` is monotonically non-decreasing — it never shrinks.**
- Width grows by 1 **only** on a no-slide step, and a no-slide step happens only
  when the window is **valid** after inclusion. So every time the width reaches a
  new maximum `W`, there is an actual *valid* window of width `W` witnessing it.
- Therefore the final width equals the **length of the longest valid window** ever
  seen. No separate `max` variable is needed, and — subtly — the *final* window
  doesn't even have to be valid; it just carries the best width forward.

Because we only ever need to *stop the window from shrinking* (not restore full
validity every step), a single `if` is enough — that's the whole trick versus the
`while`-based shrinking window.

### General template

C++:

```cpp
int start = 0;
for (int end = 0; end < n; ++end) {
    include(s[end]);            // update counts / state
    if (invalid()) {           // note: if, not while
        exclude(s[start]);
        ++start;
    }
}
return n - start;              // == longest valid window length
```

Rust:

```rust
let mut start = 0usize;
for end in 0..n {
    include(bytes[end]);       // update state
    if invalid() {             // if, not while
        exclude(bytes[start]);
        start += 1;
    }
}
(n - start) as i32
```

### Worked example — Maximum Length Substring With Two Occurrences (LC 3090)

Longest substring in which **every character appears at most twice**.

```cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> count;
        int start = 0;
        int invalid_chars = 0;               // how many chars currently exceed 2

        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
            if (count[s[i]] == 3)
                invalid_chars++;             // this char just became invalid (3)

            if (invalid_chars > 0) {         // slide right by one (don't shrink)
                count[s[start]]--;
                if (count[s[start]] == 2)
                    invalid_chars--;         // that char is back in range
                start++;
            }
        }
        return s.length() - start;           // final (max) window width
    }
};
```

Equivalent Rust (lowercase-letter alphabet):

```rust
impl Solution {
    pub fn maximum_length_substring(s: String) -> i32 {
        let s = s.as_bytes();
        let mut count = [0i32; 26];
        let mut start = 0usize;
        let mut invalid = 0i32;              // chars whose count reached 3
        for &b in s {
            let c = (b - b'a') as usize;
            count[c] += 1;
            if count[c] == 3 { invalid += 1; }
            if invalid > 0 {
                let sc = (s[start] - b'a') as usize;
                count[sc] -= 1;
                if count[sc] == 2 { invalid -= 1; }
                start += 1;
            }
        }
        (s.len() - start) as i32
    }
}
```

Trace on `s = "YXXX"` (constraint: each char ≤ 2):
`i=0 Y` → w1; `i=1 X` → w2; `i=2 X` → w3 (`"YXX"`, valid); `i=3 X` → X hits 3
(invalid), slide once (drop `Y`), `start=1`, width stays **3**. Return `4 - 1 = 3`.
Note the final window `"XXX"` is invalid, yet the returned width 3 is the correct
answer — exactly the invariant above.

### When to use it

- Good fit: **maximum length** of a window under an **"at most"** monotone
  constraint — at most K distinct chars, at most K of any char, at most K zeros to
  flip, etc. The constraint must be such that growing can only break it and
  removing from the left can only fix it (monotone).
- Related problems in this family: Longest Substring with At Most K Distinct
  Characters, Longest Repeating Character Replacement (LC 424), Max Consecutive
  Ones III (LC 1004), Fruit Into Baskets (LC 904).

### When **not** to use it

- You need the **minimum** length window, the **actual** substring/indices, or a
  **count of all** valid windows → use the standard shrinking (`while`) window, or
  prefix-sum + hashmap. The non-shrinking trick only reports the max *length*,
  because it deliberately lets the window carry a stale (possibly invalid) width.

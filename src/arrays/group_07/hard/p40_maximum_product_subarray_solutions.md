# p40 — Maximum Product Subarray · Standard Solutions

Reference collection of the well-known approaches and their ideas. No review here —
see `p40_maximum_product_subarray_approach.md` for that.

- Problem: https://leetcode.com/problems/maximum-product-subarray/
- Goal: largest product of any contiguous subarray.

---

## 1. Brute force — all subarrays

**Idea.** For every start index, extend the end index one at a time, carrying a
running product, and track the maximum seen. No cleverness about signs or zeros —
every subarray is examined directly.

```cpp
int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    for (int i = 0; i < (int)nums.size(); i++) {
        long long prod = 1;
        for (int j = i; j < (int)nums.size(); j++) {
            prod *= nums[j];
            ans = max<long long>(ans, prod);
        }
    }
    return ans;
}
```

- **Time** O(n²), **Space** O(1).
- Simplest to reason about; too slow for large `n`. Good as a correctness oracle.

---

## 2. Prefix & suffix products (two-pass scan)

**Idea.** The only thing that can ruin a product is a negative number or a zero.

- If the subarray has an even number of negatives, the full run is best.
- An odd negative is "cut" from exactly one end — so the best answer is visible
  either scanning **left→right** (prefix products) or **right→left** (suffix
  products); one direction always keeps the good half.
- A `0` breaks the array; reset the running product to `1` right after it.

Run one prefix pass and one suffix pass, resetting on zeros, and take the max of
every running value.

```cpp
int maxProduct(vector<int>& nums) {
    int n = nums.size(), ans = nums[0];
    long long pre = 1, suf = 1;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;              // reset after a zero
        if (suf == 0) suf = 1;
        pre *= nums[i];
        suf *= nums[n - 1 - i];
        ans = max<long long>({ (long long)ans, pre, suf });
    }
    return ans;
}
```

- **Time** O(n), **Space** O(1).
- Very intuitive once you see the "cut one end" insight; single loop, two directions.

---

## 3. Dynamic programming — track running max **and** min (optimal)

**Idea.** Keep the best (`hi`) and worst (`lo`) product of a subarray *ending at the
current index*. You need the min too, because multiplying the most-negative product
by another negative can produce the new maximum. Each step the candidates are the
element alone (`x`, i.e. start fresh — this also handles zeros), `hi*x`, and `lo*x`.

```cpp
int maxProduct(vector<int>& nums) {
    int hi = nums[0], lo = nums[0], ans = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        int x = nums[i];
        int h = hi * x, l = lo * x;
        hi  = max({x, h, l});
        lo  = min({x, h, l});
        ans = max(ans, hi);
    }
    return ans;
}
```

- **Time** O(n), **Space** O(1).
- The standard optimal answer. Zeros reset implicitly (`x` wins), sign-flips handled
  implicitly (`hi` and `lo` swap roles via the min/max).
- Overflow-safe under LeetCode's guarantee: every value held is a real subarray
  product, which is guaranteed to fit in 32 bits.

---

## Summary

| # | Approach | Time | Space | Notes |
|---|---|---|---|---|
| 1 | Brute force (all subarrays) | O(n²) | O(1) | correctness oracle |
| 2 | Prefix & suffix scan | O(n) | O(1) | intuitive; two directions |
| 3 | Running max/min DP | O(n) | O(1) | optimal; the one to submit |

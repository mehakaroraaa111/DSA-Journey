# Maximum Nesting Depth of the Parentheses (LeetCode 1614)

## Problem Statement

Given a valid parentheses string `s`, return the **maximum nesting depth** of the parentheses.

The nesting depth is the maximum number of open parentheses that are nested at any point in the string.

### Example

**Input:**

```text
s = "(1+(2*3)+((8)/4))+1"
```

**Output:**

```text
3
```

**Explanation:**
The deepest nested parentheses are `((8)/4)`, which have a nesting depth of **3**.

---

## Approach

We traverse the string character by character while maintaining a counter for the current nesting depth.

* When we encounter `'('`, we increase the current depth.
* When we encounter `')'`, we decrease the current depth.
* After every `'('`, we update the maximum depth reached so far.

Since the input string is guaranteed to be valid, the depth never becomes negative.

---

## Algorithm

1. Initialize two variables:

   * `p = 0` to store the current nesting depth.
   * `ans = 0` to store the maximum depth.
2. Traverse each character in the string.
3. If the character is `'('`, increment `p`.
4. If the character is `')'`, decrement `p`.
5. Update `ans` as the maximum of `ans` and `p`.
6. Return `ans`.

---

## Complexity Analysis

**Time Complexity:** `O(n)`

* We traverse the string only once.

**Space Complexity:** `O(1)`

* Only two integer variables are used.

---

## Key Concepts

* String Traversal
* Parentheses Matching
* Counter Technique
* Simulation

---

## C++ Solution

```cpp
class Solution {
public:
    int maxDepth(string s) {
        int p = 0;
        int ans = 0;

        for (char x : s) {
            if (x == '(')
                p++;
            else if (x == ')')
                p--;

            ans = max(ans, p);
        }

        return ans;
    }
};
```

---

## What I Learned

* A single counter is enough to track the current nesting depth.
* Updating the maximum depth after every opening parenthesis gives the answer in one pass.
* Parentheses-related problems often use counters or stacks, but in this case, a counter is sufficient because the input string is valid.

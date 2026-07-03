# Isomorphic Strings

## Problem Statement

Given two strings `s` and `t`, determine whether they are **isomorphic**.

Two strings are isomorphic if the characters in one string can be replaced to get the other string while preserving the order of characters.

### Rules
- Every character in `s` must map to exactly one character in `t`.
- No two different characters in `s` can map to the same character in `t`.
- A character can map to itself.
- The mapping must remain consistent throughout the strings.

---

## Examples

### Example 1

Input:
```
s = "egg"
t = "add"
```

Output:
```
true
```

Explanation:
```
e → a
g → d
```

---

### Example 2

Input:
```
s = "foo"
t = "bar"
```

Output:
```
false
```

Explanation:
```
The character 'o' cannot map to both 'a' and 'r'.
```

---

### Example 3

Input:
```
s = "paper"
t = "title"
```

Output:
```
true
```

Explanation:
```
p → t
a → i
e → l
r → e
```

---

## Approach

Instead of storing the actual character mappings, store the **last occurrence index** of each character in both strings.

For every index:
1. Compare the last occurrence of `s[i]` and `t[i]`.
2. If they differ, the mapping is inconsistent, so return `false`.
3. Otherwise, update both arrays with the current index (`i + 1`).

Using `i + 1` allows `0` to represent that a character has not been seen before.

---

## Algorithm

1. Initialize two arrays of size 256 with all values set to `0`.
2. Traverse both strings simultaneously.
3. Compare the stored values for the current characters.
4. If they are different, return `false`.
5. Update both arrays with `i + 1`.
6. If the traversal completes successfully, return `true`.

---

## C++ Solution

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (m1[s[i]] != m2[t[i]])
                return false;

            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }

        return true;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Takeaways

- Use two arrays (or hash maps) to maintain a one-to-one mapping.
- Comparing the last occurrence index is an efficient alternative to storing explicit mappings.
- Storing `i + 1` avoids ambiguity because `0` represents "not seen yet."
- This solution runs in linear time with constant extra space.

---

⭐ If you found this solution helpful, consider starring the repository!

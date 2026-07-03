# Rotate String

## Problem Statement

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after performing any number of left rotations.

A **left rotation** moves the first character of the string to the end.

---

## Examples

### Example 1

**Input**
```
s = "abcde"
goal = "cdeab"
```

**Output**
```
true
```

**Explanation**
```
abcde → bcdea → cdeab
```

---

### Example 2

**Input**
```
s = "abcde"
goal = "abced"
```

**Output**
```
false
```

**Explanation**
```
No sequence of rotations can transform "abcde" into "abced".
```

---

## Approach

A rotated version of a string will always be a substring of the original string concatenated with itself.

For example:

```
s = "abcde"

s + s = "abcdeabcde"
```

All possible rotations of `"abcde"` are present inside `"abcdeabcde"`:

```
abcde
bcdea
cdeab
deabc
eabcd
```

Therefore:

1. Check if both strings have the same length.
2. Concatenate `s` with itself.
3. Search for `goal` inside the concatenated string.
4. If found, return `true`; otherwise, return `false`.

---

## Algorithm

1. If the lengths of `s` and `goal` are different, return `false`.
2. Create a new string by concatenating `s` with itself.
3. Use the `find()` function to check whether `goal` exists in the new string.
4. Return the result.

---

## C++ Solution

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};
```

---

## Dry Run

### Input

```
s = "abcde"
goal = "cdeab"
```

### Step 1

```
Lengths are equal ✔
```

### Step 2

```
doubledS = "abcdeabcde"
```

### Step 3

Search for:

```
"cdeab"
```

It exists inside:

```
abcdeabcde
  ↑
```

Therefore,

```
Return true
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## Key Takeaways

- A rotation of a string is always a substring of the string concatenated with itself.
- Always verify that both strings have the same length before checking rotations.
- Using `find()` makes the solution simple and efficient.
- This is a common interview technique for solving string rotation problems.

---

⭐ If you found this solution helpful, consider starring the repository!

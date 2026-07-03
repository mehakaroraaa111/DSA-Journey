# Valid Anagram

## 📝 Problem Statement

Given two strings `s` and `t`, return **`true`** if `t` is an anagram of `s`, and **`false`** otherwise.

An **anagram** is a word or phrase formed by rearranging the letters of another word using all the original characters exactly once.

---

## 💡 Examples

### Example 1

**Input**
```text
s = "anagram"
t = "nagaram"
```

**Output**
```text
true
```

---

### Example 2

**Input**
```text
s = "rat"
t = "car"
```

**Output**
```text
false
```

---

## 🚀 Approach

Since the strings contain only lowercase English letters, we can use a **frequency array** of size `26`.

- First, check if both strings have the same length. If not, they cannot be anagrams.
- Traverse the first string and increment the frequency of each character.
- Traverse the second string and decrement the frequency of each character.
- Finally, check whether all frequencies are zero.
  - If yes, the strings are anagrams.
  - Otherwise, they are not.

This approach avoids sorting and runs in linear time.

---

## 📋 Algorithm

1. Compare the lengths of `s` and `t`.
2. If the lengths are different, return `false`.
3. Create a frequency array of size `26` initialized to `0`.
4. Traverse `s` and increment the frequency of each character.
5. Traverse `t` and decrement the frequency of each character.
6. Check every element of the frequency array.
7. If any value is not `0`, return `false`.
8. Otherwise, return `true`.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;

        for (int i = 0; i < t.length(); i++)
            freq[t[i] - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }

        return true;
    }
};
```

---

## 🧪 Dry Run

### Input

```text
s = "anagram"
t = "nagaram"
```

### Step 1

Count characters in `s`:

```text
a → +3
n → +1
g → +1
r → +1
m → +1
```

### Step 2

Subtract characters in `t`:

```text
a → -3
n → -1
g → -1
r → -1
m → -1
```

All frequencies become:

```text
0 0 0 0 0 ...
```

Hence,

```text
Return true
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 🎯 Key Takeaways

- Compare the lengths before processing.
- Use a frequency array of size `26` for lowercase English letters.
- Increment counts for the first string and decrement for the second.
- If every frequency becomes `0`, the strings are anagrams.
- This solution is more efficient than sorting (`O(n log n)`).

---

⭐ If you found this solution helpful, consider giving this repository a star!

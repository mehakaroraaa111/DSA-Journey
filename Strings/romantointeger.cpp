# Roman to Integer (LeetCode 13)

## Problem Statement

Given a Roman numeral, convert it into its corresponding integer value.

Roman numerals are represented by the following symbols:

| Symbol | Value |
| ------ | ----: |
| I      |     1 |
| V      |     5 |
| X      |    10 |
| L      |    50 |
| C      |   100 |
| D      |   500 |
| M      |  1000 |

Roman numerals are usually written from largest to smallest. However, there are six special cases where subtraction is used:

* IV = 4
* IX = 9
* XL = 40
* XC = 90
* CD = 400
* CM = 900

---

## Approach

### 1. Store Roman Values

Create a hash map (`unordered_map`) that maps each Roman numeral to its corresponding integer value.

### 2. Traverse the String

Iterate through the string from left to right, comparing the current character with the next character.

### 3. Apply Roman Numeral Rules

* If the current numeral is **smaller** than the next numeral, subtract its value from the result.
* Otherwise, add its value to the result.

### 4. Add the Last Character

Since the loop processes characters only up to the second-last position, add the value of the last character separately.

---

## Algorithm

1. Create a hash map for Roman numeral values.
2. Initialize the answer as `0`.
3. Traverse the string until the second-last character.
4. Compare the current and next numeral:

   * If the current value is smaller, subtract it.
   * Otherwise, add it.
5. Add the value of the last character.
6. Return the final result.

---

## Dry Run

### Input

```text
s = "MCMXCIV"
```

| Current     | Next     | Operation |   Result |
| ----------- | -------- | --------- | -------: |
| M (1000)    | C (100)  | +1000     |     1000 |
| C (100)     | M (1000) | -100      |      900 |
| M (1000)    | X (10)   | +1000     |     1900 |
| X (10)      | C (100)  | -10       |     1890 |
| C (100)     | I (1)    | +100      |     1990 |
| I (1)       | V (5)    | -1        |     1989 |
| Last: V (5) | —        | +5        | **1994** |

**Output:** `1994`

---

## Complexity Analysis

**Time Complexity:** `O(n)`

* Traverse the string once.

**Space Complexity:** `O(1)`

* The hash map contains only seven fixed Roman numeral symbols, so the extra space is constant.

---

## Key Concepts

* Hash Map (`unordered_map`)
* String Traversal
* Conditional Logic
* Greedy Approach

---

## C++ Solution

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        unordered_map<char, int> roman = {
            {'I',1}, {'V',5}, {'X',10},
            {'L',50}, {'C',100},
            {'D',500}, {'M',1000}
        };

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }

        return res + roman[s.back()];
    }
};
```

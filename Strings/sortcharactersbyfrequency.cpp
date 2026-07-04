# Sort Characters by Frequency (LeetCode 451)

## Problem Statement

Given a string `s`, sort its characters in **decreasing order of their frequency**. Return the sorted string. If multiple characters have the same frequency, any valid order is acceptable.

### Example

**Input:**

```
s = "tree"
```

**Output:**

```
"eert"
```

or

```
"eetr"
```

---

## Approach

### 1. Count Character Frequencies

* Use an `unordered_map<char, int>` to count how many times each character appears in the string.

### 2. Store Character-Frequency Pairs

* Copy the contents of the hash map into a `vector<pair<char, int>>`.
* Each pair contains:

  * `first` → Character
  * `second` → Frequency

### 3. Sort by Frequency

* Sort the vector in **descending order** based on the frequency using a custom comparator.

### 4. Build the Result

* Traverse the sorted vector.
* Append each character to the answer string according to its frequency using:

```cpp
ans.append(frequency, character);
```

---

## Algorithm

1. Create a hash map to store character frequencies.
2. Traverse the string and update the frequency of each character.
3. Copy the hash map into a vector.
4. Sort the vector in descending order of frequency.
5. Construct the answer string by repeating each character according to its frequency.
6. Return the final string.

---

## Complexity Analysis

**Time Complexity:** `O(n + k log k)`

* `O(n)` for counting frequencies.
* `O(k log k)` for sorting the distinct characters (`k` = number of unique characters).
* `O(n)` for building the output string.

**Space Complexity:** `O(k)`

* Used for the hash map and vector storing distinct characters.

---

## Key Concepts

* Hash Map (`unordered_map`)
* Sorting with Custom Comparator
* Vectors
* String Manipulation
* Greedy Construction

---

## C++ Solution

```cpp
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        string ans = "";

        for (auto &p : vec) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};
```

# Longest Palindromic Substring

## Problem Statement

Given a string `s`, return the **longest palindromic substring** in `s`.

A palindrome is a string that reads the same forward and backward.

## Approach

This solution uses the **Expand Around Center** technique.

### Steps:

1. Treat each character as the center of a palindrome (odd-length palindrome).
2. Also treat every pair of adjacent characters as the center (even-length palindrome).
3. Expand outward while the characters on both sides are equal.
4. Keep track of the longest palindrome found during the process.
5. Return the longest palindromic substring.

This approach efficiently checks all possible palindrome centers without generating every substring.

## Time Complexity

* **O(n²)**, where `n` is the length of the string.

## Space Complexity

* **O(1)** (excluding the space used for the returned substring).

## Concepts Used

* Strings
* Two Pointers
* Expand Around Center
* Substring Manipulation

## Learning Outcomes

Through this problem, I learned:

* How to identify palindromes by expanding from the center.
* The difference between odd-length and even-length palindromes.
* Efficiently finding the longest palindrome without checking every possible substring.
* Improving brute-force solutions using a center expansion approach.

## Example

**Input:**

```text
s = "babad"
```

**Output:**

```text
"bab"
```





  ##code

class Solution {
public:
    string longestPalindrome(string s) {
         if (s.empty()) return "";
        string LPS=string(1,s[0]);
        int n =s.size(),low,high;
        for(int i=1;i<n;i++){
low = i;
high=i;
while((low>=0 && high <n) && s[low]==s[high]){
    low--;
    high++;
}
string palindrome=s.substr(low+1,high-low-1);
if(palindrome.size()>LPS.size()){
    LPS=palindrome;
}
low=i-1;
high=i;
while((low>=0 && high<n)&& s[low]==s[high]){
    low--;
    high++;
}
palindrome=s.substr(low+1,high-low-1);
if(palindrome.size()>LPS.size()){
    LPS=palindrome;
}

        }
       return LPS;

    }
};
  

**Explanation:**
Both `"bab"` and `"aba"` are valid longest palindromic substrings.

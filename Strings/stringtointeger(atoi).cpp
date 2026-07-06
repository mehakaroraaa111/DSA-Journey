# String to Integer (atoi)

## Problem Statement

Implement the `myAtoi()` function that converts a string into a 32-bit signed integer. The function should:

* Ignore leading whitespace.
* Determine the sign (`+` or `-`) if present.
* Read consecutive numeric digits.
* Stop parsing when a non-digit character is encountered.
* Clamp the result within the 32-bit signed integer range:

  * `INT_MAX = 2147483647`
  * `INT_MIN = -2147483648`

## Approach

1. Skip all leading whitespace characters.
2. Check for an optional `+` or `-` sign.
3. Traverse the string while the current character is a digit.
4. Convert each digit into an integer and build the final number.
5. Handle integer overflow by returning `INT_MAX` or `INT_MIN` when necessary.
6. Return the final signed integer.

## Time Complexity

* **O(n)**, where `n` is the length of the string.

## Space Complexity

* **O(1)**, as only a few variables are used.

## Concepts Used

* Strings
* Character manipulation
* Conditional statements
* Integer overflow handling
* Two-pointer/index traversal

## code:
class Solution {
public:
    int myAtoi(string s) {
        int i = 0 ;
        while(i<s.length() && s[i]== ' '){
            i++;
        }
        int sign=1;
        if(i<s.length() && (s[i]=='+' || s[i] == '-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        long result=0;
        while(i < s.length() && s[i] >= '0' && s[i] <= '9' ){
            result = result * 10 + (s[i] -'0');
            if(result*sign> INT_MAX){
                return INT_MAX;
            }
            if(result*sign < INT_MIN ){
                return INT_MIN;
            } 
            i++;
        }
        return (result*sign);
    }
};


## Learning Outcomes

Through this problem, I learned:

* How to parse strings character by character.
* Handling optional signs and leading whitespace.
* Safely converting characters to integers.
* Managing overflow conditions for 32-bit integers.
* Writing robust edge-case handling logic.

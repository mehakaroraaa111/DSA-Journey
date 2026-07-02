🚀 **Solved: Largest Odd Number in String (C++)**


### 💡 Approach

* Traversed the string from right to left to find the **last odd digit**.
* As soon as an odd digit was found, returned the substring from the beginning of the string up to that index.
* If no odd digit exists, returned an empty string.

The key observation is that the **largest odd number** is simply the **longest prefix ending with an odd digit**. This makes the solution both simple and efficient.

### ✅ Time Complexity

**O(n)** – The string is traversed at most once.

### ✅ Space Complexity

**O(1)** – No extra space is used apart from the returned substring.

Every problem I solve helps me strengthen my understanding of string manipulation, pattern recognition, and writing optimized solutions.

#CPP #DSA #LeetCode #Strings #ProblemSolving #CodingJourney #SoftwareEngineering #100DaysOfCode

class Solution {
public:
    string largestOddNumber(string num) {
        int ind = -1;
        int i ;
        for(i = num.length() - 1 ; i>=0;i--) {
            if((num[i]-'0')%2==1){
                ind = i;
                break;

            }
        }
        i = 0;
        while(i<=ind && num[i] == '0')
        i++;

        return num .substr(i,ind-i+1);
    }
};
  

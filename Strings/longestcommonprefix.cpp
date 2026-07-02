🚀 **Solved: Longest Common Prefix (C++)**



### 💡 Approach

* First, checked if the input vector was empty.
* Sorted the array of strings lexicographically.
* Compared only the **first** and **last** strings after sorting.
* Since these two strings are the most different lexicographically, their common prefix represents the common prefix of the entire array.
* Traversed both strings character by character until a mismatch was found and built the answer.

This approach avoids comparing every string with every other string and leverages sorting to simplify the solution.

### ✅ Time Complexity

**O(n log n × m)**

* Sorting `n` strings takes **O(n log n)** comparisons.
* Each comparison can take up to **m** characters, where **m** is the average string length.

### ✅ Space Complexity

**O(1)** *(excluding the output string and the space used internally by the sorting algorithm).*

This problem highlighted how choosing the right strategy—sorting and comparing only the boundary strings—can lead to a clean and efficient solution.

#CPP #DSA #LeetCode #Strings #Algorithms #ProblemSolving #CodingJourney #SoftwareEngineering #100DaysOfCode

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end());
        string first= strs[0];
        string last = strs[strs.size()-1];
        string ans="";
        int minLength = min(first.size(),last.size());
        for(int i = 0 ;i <minLength;i++){
            if(first[i] != last[i]) break;
            ans += first[i];
        }
        return ans;
    }
};

  

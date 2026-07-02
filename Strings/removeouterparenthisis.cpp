🚀 **Solved: Remove Outer Parentheses (C++)**


### 💡 Approach

* Used a variable `level` to keep track of the current nesting depth of parentheses.
* While traversing the string:

  * Add `'('` only if we're already inside another valid group (`level > 0`).
  * Decrease the nesting level when encountering `')'`, and append it only if we're still inside a nested group.
* This efficiently removes the outermost parentheses from every primitive valid parentheses string.

### ✅ Time Complexity

**O(n)** – We traverse the string only once.

### ✅ Space Complexity

**O(n)** – For storing the resulting string.

Every problem I solve helps me strengthen my understanding of string manipulation, stack-like logic, and problem-solving in C++.

#CPP #DSA #LeetCode #ProblemSolving #CodingJourney #SoftwareEngineering #100DaysOfCode


  class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int level = 0;
        for(char ch :s){
            if (ch == '('){
                if(level>0) result += ch;
                level++;
            }
            else if (ch == ')'){
                level--;
                if (level>0) result += ch ;
            }

        }
        return result;
    }
}; content for this ques

🚀 **Solved: Reverse Words in a String (C++)**

T

### 💡 Approach

* Started traversing the string from the end.
* Skipped any extra spaces between words.
* Identified each word by finding its start and end indices.
* Extracted each word using `substr()` and appended it to the result.
* Added a single space between words to ensure there were no leading, trailing, or multiple spaces in the final output.

This approach efficiently reverses the order of words while handling unnecessary spaces without using additional data structures like stacks.

### ✅ Time Complexity

**O(n)** – Each character is processed at most once.

### ✅ Space Complexity

**O(n)** – Extra space is used to store the resulting reversed string.

Every DSA problem is an opportunity to strengthen my understanding of string manipulation, two-pointer techniques, and writing optimized solutions.


class Solution {
public:
    string reverseWords(string s) {
        
        string result ="";
        int i = s.size()-1;
        while(i>=0){
            while(i>=0 && s[i] == ' '){
                i--;
            }
                if(i<0) break;
                int end = i;
                while(i>=0 && s[i] != ' ') {
                    i--;

                }
                string word =  s.substr(i+1,end-i);
                if(!result.empty()){
                    result += " ";

                }
                result += word;
            }
            return result;
        }
    
};
  

#CPP #DSA #LeetCode #Strings #ProblemSolving #CodingJourney #SoftwareEngineering #100DaysOfCode

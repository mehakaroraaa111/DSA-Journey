Problem Statement

Given a string s, the beauty of a substring is defined as the difference between the highest frequency and the lowest frequency of characters present in that substring.

Return the sum of beauty values of all possible substrings.

Approach

This solution uses a brute-force with frequency counting approach.

Steps:

Generate all substrings using two nested loops.

Maintain a frequency map for characters in the current substring.

After adding a new character, compute:

Maximum frequency among characters.

Minimum frequency among characters.

Add (maxi - mini) to the final answer.

Since the string contains only lowercase English letters, scanning the frequency map is efficient.

Time Complexity

O(n² × 26) ≈ O(n²)

Space Complexity

O(26) ≈ O(1)

Concepts Used

Strings

Hash Map / Frequency Array

Nested Loops

Maximum and Minimum Frequency Tracking

Substring Enumeration

Learning Outcomes

Through this problem, I learned:

How to generate all possible substrings.

How to maintain character frequencies incrementally.

How to compute max/min frequencies efficiently.

How to optimize brute-force solutions using running frequency counts.

##code
class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum=0;
        for(int i = 0 ; i<n ; i++){
            unordered_map<char,int>freq;
            for(int j = i ; j <n ; j++){
                freq[s[j]]++;
                int maxi= INT_MIN;
                int mini=INT_MAX;
                for(auto it:freq){
                    mini =min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                sum +=(maxi-mini);
            }
        }
        return sum;
    }
};
  
Explanation:

The beauty values of all substrings are calculated and summed, resulting in 5

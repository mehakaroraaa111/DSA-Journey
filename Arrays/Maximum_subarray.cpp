// LeetCode 53 - Maximum Subarray
// Approach: Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
    
        long long maxi = LLONG_MIN; 
        

        long long sum = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            
            
            sum += nums[i]; 
            
            if (sum > maxi) {
                maxi = sum;
            }
            if (sum < 0) {
                sum = 0; 
            }
        }
        
        return maxi;
    }
};

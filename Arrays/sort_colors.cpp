Sort Colors (LeetCode 75)
Approach

This problem is solved using the Dutch National Flag Algorithm.

Maintain three pointers:

low → position for the next 0
mid → current element being processed
high → position for the next 2
Rules
If nums[mid] == 0, swap with low and move both pointers forward.
If nums[mid] == 1, simply move mid.
If nums[mid] == 2, swap with high and decrement high.

This sorts the array in a single traversal without using extra space.

Complexity Analysis
Time Complexity: O(n)
Space Complexity: O(1)
Key Learning
Dutch National Flag Algorithm
Three-pointer technique
In-place sorting in a single 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0 , mid = 0 , high = nums.size() -1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else {
                swap(nums[mid],nums[high]);
                high--;
            }
            

        }
        
        
    }
};


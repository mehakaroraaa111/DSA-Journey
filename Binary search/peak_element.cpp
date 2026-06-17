Implemented an efficient Binary Search solution for the Find Peak Element problem.

Approach:
- Compare the middle element with its next element.
- If nums[mid] > nums[mid + 1], the peak lies on the left side (including mid).
- Otherwise, the peak lies on the right side.
- Continue until low == high.

Time Complexity: O(log n)
Space Complexity: O(1)

 class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0 , high = nums.size() -1;
        while(low< high){
            int mid = (low + high )/2 ;
            if(nums[mid] > nums[mid+1]){
                high = mid;
               } else{
                low = mid+1;


                
            }
        }
        return low ;
        
    }
}; 

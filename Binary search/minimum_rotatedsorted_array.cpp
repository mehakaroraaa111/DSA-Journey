### Find Minimum in Rotated Sorted Array

Used Binary Search to efficiently locate the minimum element in a rotated sorted array.

#### Approach
- Compare the middle element with the rightmost element.
- If `nums[mid] > nums[high]`, the minimum lies in the right half.
- Otherwise, the minimum lies in the left half (including `mid`).
- Continue narrowing the search space until `low == high`.

#### Complexity
- Time Complexity: O(log n)
- Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = nums.size()-1 ;
        while(low<high){
            int mid = low+(high - low) / 2;
            if (nums[mid] > nums[high]){
                low= mid+1;

            } else{
                high = mid;

            }
            
        }
        return nums[low];
    }
};
  

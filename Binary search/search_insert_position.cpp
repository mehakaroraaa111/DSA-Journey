# Search Insert Position (LeetCode 35)

## Approach

The problem can be solved using Binary Search by finding the first position where the element is greater than or equal to the target.

- If the target exists, return its index.
- Otherwise, return the position where it should be inserted.

This is equivalent to finding the lower bound of the target.

## Complexity Analysis

- Time Complexity: O(log₂ n)
- Space Complexity: O(1)

## Key Learning

- Binary Search
- Lower Bound
- Search Space Reduction

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n= nums.size();
        int low=0 , high=n-1;
        int ans=n;
        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid] >= target){

            
            ans = mid;
            high=mid-1;

        }else{
            low= mid+1;

        }

    }
    return ans ;
    }
};

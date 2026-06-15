Binary Search (LeetCode 704)
Approach

Since the array is sorted, Binary Search can be used to efficiently find the target element.

Compare the target with the middle element.
If they are equal, return the index.
If the target is greater, search in the right half.
Otherwise, search in the left half.
Continue until the element is found or the search space becomes empty.
Complexity Analysis
Time Complexity: O(log₂ n)
Space Complexity: O(1)
Key Learning
Binary Search on sorted arrays
Reducing search space by half in each iteration
Efficient searching compared to linear search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 ; 
        int high = n - 1;
        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid]== target) return mid;
            else if ( target>nums[mid]) low = mid+1;
            else high= mid-1;
        }
        return -1;
        
    }
};

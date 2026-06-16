### Search in Rotated Sorted Array II

Used a modified Binary Search approach to search for the target in a rotated sorted array containing duplicates.

#### Approach
- Find the middle element.
- If the middle element matches the target, return true.
- Handle duplicate values by shrinking the search space when `low`, `mid`, and `high` are equal.
- Determine which half is sorted.
- Check whether the target lies in the sorted half and eliminate the other half.

#### Complexity
- Time Complexity: O(log n) average, O(n) worst case
- Space Complexity: O(1)


  class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

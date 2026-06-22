# Median of Two Sorted Arrays

## Problem
Given two sorted arrays `nums1` and `nums2`, return the median of the combined sorted array in `O(log(min(m, n)))` time.

## Approach
- Apply Binary Search on the smaller array.
- Partition both arrays such that the left half contains `(m + n + 1) / 2` elements.
- Check if the partition is valid:
  - `l1 <= r2`
  - `l2 <= r1`
- If valid:
  - Odd length → Median = `max(l1, l2)`
  - Even length → Median = `(max(l1, l2) + min(r1, r2)) / 2`

## Complexity
- **Time Complexity:** `O(log(min(m, n)))`
- **Space Complexity:** `O(1)`

## Key Learning
- Binary Search on partitions instead of values.
- Handling edge cases using `INT_MIN` and `INT_MAX`.
- Efficiently finding the median without merging arrays.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n){
            return findMedianSortedArrays (nums2,nums1);

        }
        int total = m+n;
        int left = (total+1)/2 ;
        int low = 0;
        int high = m;
        while(low<=high){
            int mid1=(low+high) >> 1;
            int mid2 = left - mid1;
             int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < m) ? nums1[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? nums2[mid2] : INT_MAX;
            if (l1 <= r2 && l2 <= r1) {

    if (total % 2 == 1) {
                    return max(l1, l2);
                }
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
 else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
        }
    }
    return 0.0;
    }

};

  

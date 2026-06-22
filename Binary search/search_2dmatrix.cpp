Problem Statement

Given an m x n integer matrix with the following properties:

Integers in each row are sorted in ascending order.
The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if the target exists in the matrix, otherwise return false.

Approach

Instead of performing binary search on every row, the entire matrix can be treated as a single sorted 1D array.

Key Observation

For a matrix with m columns:

Row index = mid / m
Column index = mid % m

This allows direct access to any element while performing binary search on the virtual 1D array.

Algorithm
Calculate total elements: n * m.
Apply binary search on indices from 0 to n*m - 1.
Convert the middle index into corresponding row and column.
Compare the element with the target:
If equal, return true.
If smaller, search the right half.
If larger, search the left half.
If the target is not found, return false.
  Complexity Analysis
Time Complexity: O(log(n * m))
Space Complexity: O(1)


  class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0 , high = n * m -1;
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid / m ;
            int col = mid%m;
            if(matrix[row][col] == target)
            return true;
            else if (matrix[row][col]<target)
            low= mid+1;
            else
            high = mid - 1;

        }
        return false;
    }
};

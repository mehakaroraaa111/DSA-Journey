# Search a 2D Matrix II

## Problem
Given a matrix where each row is sorted from left to right and each column is sorted from top to bottom, determine whether a target value exists in the matrix.

## Approach
- Start from the top-right corner.
- If the current element equals the target, return `true`.
- If the current element is smaller than the target, move down.
- If the current element is greater than the target, move left.
- Continue until the target is found or the search space is exhausted.

## Complexity
- **Time Complexity:** `O(n + m)`
- **Space Complexity:** `O(1)`

## Key Learning
- Efficient matrix searching using row and column sorting properties.
- Eliminating one row or one column in each step.
- Alternative to Binary Search for sorted 2D matrices.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0 ;
        int col = m-1;
        while(row<n && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if (matrix[row][col]<target) {
                row++;



            }
            else{
                col--;

            }
        }
        return false;
        
    }
};
  

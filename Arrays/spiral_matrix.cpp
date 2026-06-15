Problem Statement

Given an m x n matrix, return all elements of the matrix in spiral order.

Example

Input:

matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]

Output:

[1,2,3,6,9,8,7,4,5]
Approach

The idea is to traverse the matrix layer by layer using four boundaries:

top → first unvisited row
bottom → last unvisited row
left → first unvisited column
right → last unvisited column
Traversal Order
Traverse the top row from left to right.
Traverse the right column from top to bottom.
Traverse the bottom row from right to left.
Traverse the left column from bottom to top.

After each traversal, update the corresponding boundary to move inward.

Continue until all elements are visited.

Algorithm
Initialize top, bottom, left, and right.
While top <= bottom and left <= right:
Traverse the top row.
Increment top.
Traverse the right column.
Decrement right.
Traverse the bottom row if top <= bottom.
Decrement bottom.
Traverse the left column if left <= right.
Increment left.
Return the result vector.
Complexity Analysis
Time Complexity: O(m × n)
Each element is visited exactly once.
Space Complexity: O(1)
Excluding the output vector.
Key Learning
Matrix traversal using boundary pointers.
Handling edge cases for single rows and single columns.
Efficient simulation of spiral movement without extra space.

LeetCode Problem: Spiral Matrix


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        int top = 0 ;
        int bottom = matrix.size()-1;
        int left = 0 ;
        int right = matrix[0].size()-1;
        while(top<= bottom && left<= right){
            for(int i = left ; i <= right ; i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top;i<= bottom;i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i = right;i >=left;i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i = bottom ; i >= top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};







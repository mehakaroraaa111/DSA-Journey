
Set Matrix Zeroes (LeetCode 73)
Approach

Instead of using extra row and column arrays, use the first row and first column as markers.

First, check whether the first row or first column originally contains a zero.

Traverse the matrix and mark rows and columns that need to be zeroed by setting:

matrix[i][0] = 0;
matrix[0][j] = 0;
Traverse the matrix again and set cells to zero based on these markers.
Finally, update the first row and first column if they originally contained zeros.

This achieves the task in-place with constant extra space.

Complexity Analysis
Time Complexity: O(m × n)
Space Complexity: O(1)
Key Learning
In-place matrix manipulation
Space optimization using matrix boundaries as markers
Handling special cases for the first row and first column

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero=false;
        bool firstColZero=false;
        for(int j = 0 ; j<n ; j++){
            if(matrix[0][j]==0){
                firstRowZero=true;
                break;
            }
        }
        for(int i = 0 ; i<m ; i++){
            if(matrix[i][0]==0){
                firstColZero= true;
                break;
            }
        }
        for(int i = 1 ;i <m ;i++){
            for(int j = 1 ; j<n; j++){
                if(matrix[i][j]==0){
                    matrix [i][0]=0;
                    matrix [0][j]=0;
                }
            }
        }
        for(int i = 1;i<m;i++){
            for(int j = 1; j<n;j++){
                if(matrix[i][0] ==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstRowZero){
            for(int j = 0 ; j<n ; j++){
                matrix[0][j]=0;
            }
        }
        if(firstColZero){
            for(int i = 0 ; i<m ; i++){
                matrix[i][0]=0;
            }
        }
        
    }
};


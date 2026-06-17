Generated Pascal's Triangle using a 2D vector.

Approach:
- Each row starts and ends with 1.
- Middle elements are computed using the sum of two adjacent elements from the previous row.
- Build the triangle row by row and store the result.

Time Complexity: O(n²)
Space Complexity: O(n²)


  class Solution {
public:
vector<vector<int>> generate(int numRows){
    vector<vector<int>> triangle;
    for(int i = 0 ; i<numRows ; i++){
        vector<int>row(i+1,1);

        for(int j = 1;j<i;j++){
            row [j]= triangle[i-1][j-1]+ triangle[i-1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
   }  
};

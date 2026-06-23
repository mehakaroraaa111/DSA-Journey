# Find Peak Element in a 2D Grid

## Problem Statement

Given an `m x n` matrix `mat`, find a peak element and return its position `[row, col]`.

A peak element is an element that is **strictly greater than its left and right neighbors**.

The solution uses **Binary Search on Columns** to achieve an efficient time complexity.

---

## Approach

### Key Idea

Instead of searching every element, we perform Binary Search on the columns.

1. Select the middle column.
2. Find the row containing the maximum element in that column.
3. Compare the element with its left and right neighbors.
4. If it is greater than both, it is a peak.
5. Otherwise, move towards the larger neighbor because a peak must exist in that direction.

---

## Algorithm

1. Initialize `low = 0` and `high = m - 1`.
2. While `low <= high`:

   * Find the middle column.
   * Find the row having the maximum element in that column.
   * Check left and right neighbors.
   * If current element is greater than both neighbors, return its coordinates.
   * Move Binary Search towards the larger neighbor.
3. Return `[-1, -1]` if no peak is found.

---

## Code Features

* Uses Binary Search for optimization.
* Avoids brute-force traversal of all cells.
* Efficient handling of boundary columns using `INT_MIN`.
* Returns the coordinates of any valid peak element.

---

## Time Complexity

* Finding maximum element in a column: **O(n)**
* Binary Search on columns: **O(log m)**

Overall Time Complexity:

O(n × log m)

where:

* `n` = number of rows
* `m` = number of columns

---

## Space Complexity

O(1)

No extra space is used apart from a few variables.

---

## Example

Input:

```cpp
[
 [1, 4],
 [3, 2]
]
```

Output:

```cpp
[0, 1]
```

Explanation:

* Element `4` is greater than its left neighbor `1`.
* Therefore, it is a valid peak element.

---

## Concepts Used

* Binary Search
* Matrix Traversal
* Peak Element Problem



class Solution {
public:
   int maxElement(vector<vector<int>>& arr,int col){
    int n = arr.size();
    int max_val=INT_MIN;
    int index=-1;
    for(int i = 0 ;i<n;i++){
        if(arr[i][col] > max_val){
            max_val = arr[i][col];
            index = i ;

        }
    }
    return index;

   }
   vector<int> findPeakGrid(vector<vector<int>>& arr){
    int n = arr.size();
    int m = arr[0].size();
    int low = 0 ;
    int high = m-1;
    while(low<= high){
        int mid = (low+high)/2;
        int row = maxElement(arr,mid);
        int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
              int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;
              if(arr[row][mid] > left && arr[row][mid] >right){
                return{row,mid};

              } else if (left > arr[row][mid]){
                high=mid-1;

              } else {
                low = mid+1;

              }
    }
    return{-1,-1};
   }
};  write readme for github
* Optimization Techniques
* DSA Interview Preparation

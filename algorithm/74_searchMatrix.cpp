/*
74. Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
    int left=0;
    int right = m*n-1;
    while (left <= right){
      int mid = (left + right) / 2;
      int row = mid / m;
      int col = mid % m;
      
      if (matrix[row][col] < target)
        left = mid + 1;
      else if (matrix[row][col] > target)
        right = mid -1;
      else
        return true;
    }
    return false;
  }
};
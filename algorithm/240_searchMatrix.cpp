/*
240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m=matrix[0].size();
    int row=n-1, col=0;
    while (row >= 0 && col < m){
      int cur = matrix[row][col];
      if (cur < target)
        col++;
      else if (cur > target)
        row--;
      else
        return true;
    }
    return false;
  }
};
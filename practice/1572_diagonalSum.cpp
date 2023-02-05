/*
1572. Matrix Diagonal Sum
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
*/
class Solution {
public:
  int diagonalSum(vector<vector<int>>& mat) {
    int sum=0;
    int n=mat.size();
    for (int i=0; i<n; i++){
      sum += mat[i][i];
      int col = n - i - 1;
      if (col != i)
        sum += mat[i][col];
    }
    return sum;
      
    
  }
};

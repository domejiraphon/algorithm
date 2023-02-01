/*
766. Toeplitz Matrix
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
*/
class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    bool toep=true;
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (i+1 <n && j+1 < m)
          toep = toep && (matrix[i][j] == matrix[i+1][j+1]);
          if (!toep)
            return false;
      }
    }
    
    return true;
  }
};

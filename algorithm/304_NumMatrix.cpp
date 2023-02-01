/*
304. Range Sum Query 2D - Immutable

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
*/
class NumMatrix {
  vector<vector<int>> prefixSum;
public:
  NumMatrix(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    prefixSum.resize(n+1, vector<int>(m+1, 0));
   
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        prefixSum[i+1][j+1] = matrix[i][j] + prefixSum[i+1][j] + prefixSum[i][j+1] - prefixSum[i][j];
       
      }
    }
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    
    return prefixSum[row2+1][col2+1] -prefixSum[row1][col2+1] - prefixSum[row2+1][col1] + prefixSum[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

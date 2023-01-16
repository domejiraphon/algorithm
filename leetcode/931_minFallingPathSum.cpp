/*
931. Minimum Falling Path Sum
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/
class Solution {
  int dirs[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int minPath = INT_MAX;
    vector<vector<int>> memo(n, vector<int> (m, -1));
    for (int i=0; i<m; i++){
      minPath = min(minPath, pathSum(matrix, n-1, i, n, m, memo));
    }
    return minPath;
  }
private:
  int pathSum(vector<vector<int>>& matrix, int i, int j, int& n, int& m, vector<vector<int>>& memo){
    if (i < 0 || j < 0 || j >= m)
      return INT_MAX;
    if (i == 0)
      return matrix[i][j];
    if (memo[i][j] != -1)
      return memo[i][j];
    int minCost=INT_MAX/2;
    for (auto dir: dirs){
      int x = i + dir[0];
      int y = j + dir[1];
      minCost = min(minCost, pathSum(matrix, x, y, n, m, memo));
    }
    return memo[i][j] = minCost + matrix[i][j]; 
  }
};

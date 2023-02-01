/*
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
class Solution {
  int dirs[2][2]={{0, 1}, {1, 0}};
public:
  int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> memo(n, vector<int>(m , -1));
    return path(grid, 0, 0, n, m, memo);
  }
private:
  int path(vector<vector<int>>& grid, int i, int j, int& n, int& m, vector<vector<int>>& memo){
    if (i==n-1 && j == m -1)
      return grid[i][j];
    if (memo[i][j] != -1)
      return memo[i][j];
    int out=INT_MAX;
    for (auto dir: dirs){
      int newI = i + dir[0];
      int newJ = j + dir[1];
      if (0 <= newI && newI < n && 0 <= newJ && newJ< m){
        out = min(out, grid[i][j] + path(grid, newI, newJ, n, m, memo));
      }
    }
    return memo[i][j] = out;
  }
};
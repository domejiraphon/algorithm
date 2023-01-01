/*
329. Longest Increasing Path in a Matrix

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
*/
class Solution {
  vector<vector<bool>> visited;
  vector<vector<int>> nums;
  vector<vector<int>> memo;
  int n, m;
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int maxVal=0;
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    n=matrix.size();
    m = matrix[0].size();
    nums = matrix;
    visited.resize(n, vector<bool> (m, false));
    memo.resize(n, vector<int> (m, -1));
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        visited[i][j] = true;
        DFS(i, j);
        visited[i][j] = false;
      }
    }
    return maxVal + 1;
  }
private:
  int DFS(int i, int j){
    if (memo[i][j] != -1){
      return memo[i][j];
    }
    int dist=0;
    for (auto dir: dirs){
      int x = i + dir[0];
      int y = j + dir[1];
      
      if (x >= 0 && x <n && y>=0 && y<m 
          && !visited[x][y] && nums[x][y] > nums[i][j]){
        visited[x][y] = true;
        dist = max(dist, 1 + DFS(x, y));
        visited[x][y] = false;
        maxVal = max(dist, maxVal);
      }
    }
    return memo[i][j] = dist;
  }
};
/*
695. Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/
class Solution {
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    int m = grid[0].size();
    int island=0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (grid[i][j] == 1 && !visited[i][j]){
          visited[i][j] = true;
          island = max(island, 1 + dfs(grid, i, j, n, m, visited));
        }
      }
    }
    return island;
  }
private:
  int dfs(vector<vector<int>>& grid, int i, int j, int& n, int& m, vector<vector<bool>>& visited){
    int out=0;
    for (auto dir: dirs){
      int newI = i + dir[0];
      int newJ = j + dir[1];
      if (newI >=0 && newI < n && newJ >=0 && newJ < m && grid[newI][newJ] == 1 && !visited[newI][newJ]){
        visited[newI][newJ] = true;
        out += 1 + dfs(grid, newI, newJ, n, m, visited);
      }
    }
    return out;
  }
};
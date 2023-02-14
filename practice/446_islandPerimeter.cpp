/*
463. Island Perimeter
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
*/
class Solution {
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int out =0 ;
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (grid[i][j] == 1){
          visited[i][j] = true;
          dfs(grid, i, j, n, m, visited, out);
          return out;
        }
      }
    }
    return out;
  }
private:
  void dfs(vector<vector<int>>& grid, int i, int j, int& n, int& m, vector<vector<bool>>& visited, int& num){
    int peri=4;
    
    for (auto dir: dirs){
      int newI = i + dir[0];
      int newJ = j + dir[1];
      
      
      if (0 <= newI && newI <n && 0 <= newJ && newJ < m && grid[newI][newJ] == 1){
        peri--;
        if (!visited[newI][newJ]){
          visited[newI][newJ] = true;
          dfs(grid, newI, newJ, n, m, visited, num);
        }
      }
    }
    num += peri;
  }
};

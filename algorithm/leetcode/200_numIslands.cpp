/* 200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/
class Solution {
private:
  int dirs[4][2] =  {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<vector<bool>> visited;
  vector<vector<char>> grids;
  int n, m;
public:
  int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    visited.resize(n, (vector<bool> (m, false)));
    grids = grid;
    int out(0);
    for (int i=0; i < n; i++){
      for (int j=0; j < m; j++){
        if (!visited[i][j] && grid[i][j] == '1'){
          visited[i][j] = true;
          DFS(i, j);
          out++;
        }
      }
    }
    return out;
  }
private:
  void DFS(int i, int j){
    for (auto ele: dirs){
      int x = i + ele[0], y = j + ele[1];
      
      if (x >= 0 && x < n && 
          y >= 0 && y < m &&
          !visited[x][y] &&
          grids[x][y] == '1'){
        visited[x][y] = true;
        DFS(x, y);
      }
    }
  }
};
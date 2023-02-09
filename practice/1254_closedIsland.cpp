/*
1254. Number of Closed Islands
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
*/
class Solution {
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
  int closedIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    for (int j=0; j<m; j++){
      if (grid[0][j] == 0)
        mark(grid, 0, j, n, m);
      if (grid[n-1][j] == 0)
        mark(grid, n-1, j, n, m);
    }
    
    for (int i=0; i<n; i++){
      if (grid[i][0] == 0)
        mark(grid, i, 0, n, m);
      if (grid[i][m-1] == 0)
        mark(grid, i, m-1, n, m);
    }
    int res=0;
    for (int i=1; i<n-1; i++){
      for (int j=1; j<m-1; j++){
        if (grid[i][j] == 0){
          mark(grid, i, j, n, m);
          res++;
        }
      }
    }
    return res;
  }
private:
  void mark(vector<vector<int>>& grid, int i, int j, int& n, int& m){
    grid[i][j] = -1;
    for (auto dir: dirs){
      int newI = i + dir[0];
      int newJ = j + dir[1];
      if (newI >= 0 && newI <n && newJ >=0 && newJ < m && grid[newI][newJ] == 0)
        mark(grid, newI, newJ, n, m);
    }
  }
};

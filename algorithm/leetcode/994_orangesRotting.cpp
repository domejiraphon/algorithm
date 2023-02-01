/*
994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/
class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int, int>> Q;
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (grid[i][j] == 2)
          Q.push({i, j});
      }
    }
    int steps = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!Q.empty()){
      int len = Q.size();
      for (int i=0; i<len; i++){
        pair<int, int> cur = Q.front();
        grid[cur.first][cur.second] = 2;
        Q.pop();
        for (auto dir: dirs){
          int x = cur.first + dir[0];
          int y = cur.second + dir[1];
          if (0<=x && x<n && y>=0 && y<m && ! visited[x][y] && grid[x][y] == 1){
            visited[x][y] = true;
            Q.push({x, y});
          }
        }
      }

      steps += (!Q.empty());
    }
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (grid[i][j] == 1)
          return -1;
      }
    }
    return steps;
  }
};
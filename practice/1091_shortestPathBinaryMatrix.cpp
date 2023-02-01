/* 
1091. Shortest Path in Binary Matrix
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    if (grid[0][0] == 1)
      return -1;
    if (n == 1 && m == 1)
      return (grid[0][0] == 0) ? 1 : -1;
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    vector<vector<bool>> visited (n, vector<bool>(m, false));
    int dirs[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    visited[0][0] = true;
    int cost=2;
    while (!Q.empty()){
      int len = Q.size();
      for (int i=0; i<len; i++){
        pair<int, int> cur = Q.front();
        Q.pop();
        for (auto dir: dirs){
          int x = cur.first + dir[0];
          int y = cur.second + dir[1];
          if (x == n - 1 && y == m - 1)
            return grid[x][y] == 0 ? cost : -1;
          if (x >= 0 && x< n && y>= 0 && y<m &&
              !visited[x][y] && grid[x][y] == 0){
            visited[x][y] = true;
            Q.push({x, y});
          }
        }
      }
      cost++;
    }
    return -1;
  }
};

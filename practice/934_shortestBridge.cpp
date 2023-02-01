/* 934. Shortest Bridge
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.
*/
class Solution {
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int n, m;
  vector<vector<int>> lands;
  vector<vector<bool>> visited;
public:
  int shortestBridge(vector<vector<int>>& grid) {
    n=grid.size();
    m=grid[0].size();
    lands = grid;
    int res=INT_MAX;
    //visited.resize(n, vector<bool>(m, false));
   
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){

        if (check(i, j) && grid[i][j] == 1){
          visited.resize(n, vector<bool>(m, false));
          cout<< i<<">>"<<j<< endl;
          res = min(res, BFS(i, j));
        }
          
      }
    }
    return res;
  }
private:
  bool check(int st_i, int st_j){
    bool isolated=true;
    for (int i=0; i<4 && isolated; i++){
      int x = st_i + dirs[i][0];
      int y = st_j + dirs[i][1];
      
      if (0 <= x && x < n && 0 <= y && y < m && lands[x][y] == 1)
        isolated = false;
    }
    return isolated;
  }
  int BFS(int i, int j){
    queue<pair<int, int>> Q;
    Q.push({i, j});
    int count=0;
    while (!Q.empty()){
      int len = Q.size();
      for (int i=0; i<len; i++){
        pair<int, int> cur = Q.front();
        Q.pop();
        visited[cur.first][cur.second] = true;
        for (int i=0; i<4; i++){
          int x = cur.first + dirs[i][0];
          int y = cur.second + dirs[i][1];
          if (0 <= x && x < n && 0 <= y && y < m && !visited[x][y]){
            visited[x][y] = true;
            if (lands[x][y] == 1){
              return count;
            }
            else 
              Q.push({x, y});
          }
        }
      }
      count++;
    }
    return count;
  }
};

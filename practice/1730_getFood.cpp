class Solution {
public:
  int getFood(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int visited[n][m];
    queue<pair<int, int>> Q;
    memset(visited, false, sizeof(int)*n*m);
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (grid[i][j] == '*'){
          Q.emplace(i, j);
          visited[i][j] = true;
          break;
        }
      }
    }
    
    
    int dist(0);
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    while (!Q.empty()){
      int nm=Q.size();
      for (int it=0; it<nm; it++){
        pair<int, int> cur = Q.front(); Q.pop();
        
        int i=cur.first, j=cur.second;
        
        if(grid[i][j] == '#') return dist;
      
        
        for (auto dir: dirs){
          int newI = i+dir[0];
          int newJ = j+dir[1];
          if (newI >=0 && newI<n && newJ>=0 && newJ<m && grid[newI][newJ] != 'X'
              && !visited[newI][newJ]){
            
            Q.emplace(newI, newJ);
            visited[newI][newJ] = true;
          } 
        }
      }
      dist++;
    }
    return -1;
  }
};

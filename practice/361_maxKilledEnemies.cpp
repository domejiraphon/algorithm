class Solution {
  int dirs[2] = {-1, 1};
public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int maxVal=0;
    vector<vector<vector<int>>> memo1(n, vector<vector<int>>(m, vector<int>(2, -1)));
    vector<vector<vector<int>>> memo2(n, vector<vector<int>>(m, vector<int>(2, -1)));
    
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        int row = numberKilledRow(grid, i, j, -1, n, m, memo1) + 
                  numberKilledRow(grid, i, j, 1, n, m, memo1);
        int col = numberKilledCol(grid, i, j, -1, n, m, memo2) +
                  numberKilledCol(grid, i, j, 1, n, m, memo2);
        maxVal = max(maxVal,  col);
      }
    }
    return maxVal;
  }
private:
  int numberKilledRow(vector<vector<char>>& grid, int i, int j, int dir, int& n, int& m, vector<vector<vector<int>>>& memo){
    
    if (i==0 || i==n-1)
      return grid[i][j] == 'E';
  
    if (memo[i][j][dir+1] != -1)
      return memo[i][j][dir+1];
    int num=0;
    
    if (grid[i][j] == 'E')
      num += 1 + numberKilledRow(grid, i + dir, j, dir, n, m, memo);
    else if (grid[i][j] == '0')
      num += numberKilledRow(grid, i + dir, j, dir, n, m, memo);
    
    return memo[i][j][dir+1] = num;
  }
  int numberKilledCol(vector<vector<char>>& grid, int i, int j, int dir, int& n, int& m, vector<vector<vector<int>>>& memo){
      if (j==0 || j==m-1)
        return grid[i][j] == 'E';
     
      if (memo[i][j][dir] != -1)
        return memo[i][j][dir+1];
      int num=0;
    
      if (grid[i][j] == 'E')
        num += 1 + numberKilledCol(grid, i, j+dir, dir, n, m, memo);
      else if (grid[i][j] == '0')
        num += numberKilledCol(grid, i, j+dir, dir, n, m, memo);
    
      return memo[i][j][dir+1] = num;
    
    }
};

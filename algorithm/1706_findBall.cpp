/*
1706. Where Will the Ball Fall
You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.
*/
class Solution {
public:
  vector<int> findBall(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int> res;
    vector<vector<int>> memo (n, vector<int>(m, INT_MIN));
    for (int i=0; i<m; i++)
      res.push_back(dfs(0, i, n, m, grid, memo));
   
    return res;
  }
private:
  int dfs(int i, int j, int& n, int& m, vector<vector<int>>& grid, vector<vector<int>>& memo){
    if (i==n)
      return j;
    if (memo[i][j] != INT_MIN)
      return memo[i][j];
    int k=-1;
    if (j < m - 1 && grid[i][j] == 1 && grid[i][j+1] == 1)
      k = dfs(i+1, j+1, n, m, grid, memo);
    else if (j > 0 && grid[i][j] == -1 && grid[i][j-1] == -1)
      k =dfs(i+1, j-1, n, m, grid, memo);
   
    return memo[i][j] = k;
  }
};
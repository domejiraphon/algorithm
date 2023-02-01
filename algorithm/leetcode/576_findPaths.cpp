/*
576. Out of Boundary Paths

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
*/
class Solution {
  int mod = pow(10, 9) + 7;
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int memo[51][51][51]={};
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
    memset(memo, -1, sizeof(memo));
    return helper(m, n, maxMove, startRow, startColumn);
  }
private:
  int helper(int m, int n, int maxMove, int startRow, int startColumn) {
    if (startRow < 0 || startRow >= m || startColumn <0 || startColumn >= n)
      return 1;
    if (memo[startRow][startColumn][maxMove] != -1)
      return memo[startRow][startColumn][maxMove];
    if (maxMove==0)
      return 0;
    int out=0;
    for (auto dir: dirs)
      out = (out + helper(m, n, maxMove - 1, startRow + dir[0], startColumn + dir[1])) % mod;
    
    return memo[startRow][startColumn][maxMove] = out;
  }
};
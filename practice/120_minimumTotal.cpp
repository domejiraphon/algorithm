/*
120. Triangle
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/
class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    int m=triangle[n-1].size();
    vector<vector<int>> memo(n, vector<int> (m, -1));
    return pathSum(triangle, 0, 0, n, memo);
  }
private:
  int pathSum(vector<vector<int>>& triangle, int i, int j, int& n, vector<vector<int>>& memo){
    if (i==n)
      return 0;
    if (memo[i][j] != -1)
      return memo[i][j];
    int left = pathSum(triangle, i+1, j, n, memo);
    int right = pathSum(triangle, i+1, j+1, n, memo);
    int out = triangle[i][j] + min(left, right);
    return memo[i][j] = out;
  }
};
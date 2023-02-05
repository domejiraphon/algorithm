/*
1039. Minimum Score Triangulation of Polygon
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.
*/
class Solution {
public:
  int minScoreTriangulation(vector<int>& values) {
    int dp[50][50] = {};
    return helper(values, 0, values.size() - 1, dp);
  }
private:
  int helper(vector<int>& values, int i, int j, int dp[50][50]){
    if (j - i < 2)
      return 0;
    if (dp[i][j] != 0)
      return dp[i][j];
    int out=INT_MAX;
    for (int k=i+1; k<j; k++){
      out = min(out, values[i] * values[j] * values[k] + 
                helper(values, i, k, dp) +
                helper(values, k, j, dp));
    }
    return dp[i][j] = out;
  }
};

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int n=matrix.size(), m=matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    int res(0);
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (matrix[i][j] == '1'){
          dp[i][j] = j == 0 ? 1 : 1 + dp[i][j-1];
          int width = dp[i][j];
          for (int height=0; height <= i; height++){
            width = min(width, dp[i-height][j]);
            res = max(res, width*(height+1));
          }
        }
        
      }
    }
    return res;
  }
};

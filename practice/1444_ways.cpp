/*
1444. Number of Ways of Cutting a Pizza
Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.
*/
class Solution {
  int mod=pow(10, 9) + 7;
public:
  int ways(vector<string>& pizza, int k) {
    int n=pizza.size(), m=pizza[0].size();
    vector<vector<int>> prefixSum(n+1, vector<int>(m+1, 0));
    vector<vector<vector<int>>> memo(k+1, vector<vector<int>>(n, vector<int>(m, -1)));
    for (int i=n-1; i>=0; i--){
      for (int j=m-1; j>=0; j--){
        prefixSum[i][j] = (pizza[i][j] == 'A') + prefixSum[i+1][j] + prefixSum[i][j+1] - prefixSum[i+1][j+1];
      }
    }
    return dp(pizza, k, 0, 0, n, m, prefixSum, memo);
  }
private:
  int dp(vector<string>& pizza, int k, int r, int c, int& n, int& m, vector<vector<int>>& prefixSum, vector<vector<vector<int>>>& memo){
    
    if (prefixSum[r][c] == 0)
      return 0;
    if (k == 1)
      return 1;
    if (memo[k][r][c] != -1)
      return memo[k][r][c];
    int out=0;
    for (int i=r+1; i<n; i++){
      if (prefixSum[r][c] - prefixSum[i][c] > 0)
        out = (out + dp(pizza, k-1, i, c, n, m, prefixSum, memo)) % mod;
    }
    for (int i=c+1; i<m; i++){
      if (prefixSum[r][c] - prefixSum[r][i] > 0)
        out = (out + dp(pizza, k-1, r, i, n, m, prefixSum, memo)) % mod;
    }
    return memo[k][r][c] = out % mod;
  }
};

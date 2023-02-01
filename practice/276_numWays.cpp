/*
276. Paint Fence
You are painting a fence of n posts with k different colors. You must paint the posts following these rules:

Every post must be painted exactly one color.
There cannot be three or more consecutive posts with the same color.
Given the two integers n and k, return the number of ways you can paint the fence.
*/
class Solution {
public:
  int numWays(int n, int k) {
    int ans = 0;
    vector<vector<vector<int>>> memo(n, vector<vector<int>> (k, vector<int> (2, -1)));
    for (int i=0; i<k; i++)
      ans += count(1, n, k, 1, i, memo);
    return ans;
  }
private:
  int count(int i, int n, int k, int numPrev, int prevColor, vector<vector<vector<int>>>& memo){
    if (i == n)
      return 1;
    if (memo[i-1][prevColor][numPrev - 1] != -1)
      return memo[i-1][prevColor][numPrev - 1];
    int out=0;
    for (int it=0; it<k; it++){
      if (prevColor == it){
        if (numPrev == 1)
          out += count(i+1, n, k, 2, it, memo);
      }
      else 
        out += count(i+1, n, k, 1, it, memo);
    }
    return memo[i-1][prevColor][numPrev - 1] = out;
  }
};


class Solution {
public:
  int numWays(int n, int k) {
    int memo[2];
    memo[0] = k;
    memo[1] = k*k;
    if (n == 1)
      return memo[0];
    else if (n==2)
      return memo[1];
    for (int i=3; i<=n; i++){
      int cur = (k-1)*memo[1] + (k-1)* memo[0];
      memo[0] = memo[1];
      memo[1] = cur;
    }
    return memo[1];
  }
};
/*
70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution {
public:
  int climbStairs(int n) {
    int dp[2];
    dp[0] = 1; dp[1] = 1;
    int tmp;
    for (int i=2; i<=n; i++){
      tmp = dp[1];
      dp[1] += dp[0];
      dp[0] = tmp;
    }
    return dp[1];
  }
};
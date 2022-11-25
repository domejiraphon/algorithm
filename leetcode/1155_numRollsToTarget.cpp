class Solution {
  int K;
  int mod = pow(10, 9) + 7;
  vector<vector<int>> dp;
public:
  int numRollsToTarget(int n, int k, int target) {
    K = k;
    dp.resize(n + 1, vector<int>(target + 1, -1));
    return numRolls(n, target);
  }
private:
  int numRolls(int n, int target){
    if (target < 0){return 0;}
    if (target == 0){return (n == 0);}
    if (n == 0){return (target == 0);}
    if (dp[n][target] != -1){return dp[n][target];}
    long ans(0);
    for (int i=1; i <=K; i++){
      int cur = numRolls(n - 1, target - i) % mod;
      ans += cur;
    }
    return dp[n][target] = ans % mod;
  }
};

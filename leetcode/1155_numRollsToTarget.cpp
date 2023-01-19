/*
You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
*/
class Solution {
  int mod = pow(10, 9) + 7;
public:
  int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
    return ways(n, k, target, memo);
  }
private:
  int ways(int n, int k, int target, vector<vector<int>>& memo){
    if (target == 0)
      return n == 0;
    if (n==0)
      return 0;
    if (memo[n][target] != -1)
      return memo[n][target];
    int out=0;
    for (int i=1; i<=min(k, target); i++){
      out = (out + ways(n - 1, k, target - i, memo)) % mod;
    }
    return memo[n][target] = out;
  }
};
/*
1223. Dice Roll Simulation
A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.

Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls. Since the answer may be too large, return it modulo 109 + 7.

Two sequences are considered different if at least one element differs from each other.
*/
class Solution {
  int mod = pow(10, 9) + 7;
public:
  int dieSimulator(int n, vector<int>& rollMax) {
    vector<vector<vector<int>>> memo(n, vector<vector<int>> (7, vector<int>(n, -1)));
    return count(n, rollMax, 0, 0, 0, memo);
  }
private:
  int count(int n, vector<int>& rollMax, int cur, int prev, int prevCount, vector<vector<vector<int>>>& memo){
    if (cur == n)
      return 1;
    if (memo[cur][prev][prevCount] != -1)
      return memo[cur][prev][prevCount];
    int sum=0;
    for (int i=1; i<=6; i++){
      if (i == prev){
        if (prevCount < rollMax[i])
          sum = (sum + count(n, rollMax, cur + 1, prev, prevCount + 1, memo)) % mod;
      }
      else
        sum = (sum + count(n, rollMax, cur + 1, i, 1, memo)) % mod;
    }
    return memo[cur][prev][prevCount] = sum;
  }
};

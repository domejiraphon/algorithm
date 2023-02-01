/*
322. Coin Change
You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> memo(amount+1, INT_MAX/10);
    sort(coins.rbegin(), coins.rend());
    memo[0] = 0;
    for (int i=1; i<=amount; i++){
      for (auto coin: coins){
        if (i >= coin)
          memo[i] = min(memo[i], 1 + memo[i - coin]);
      }
    }
    return memo[amount] == INT_MAX / 10 ? -1 : memo[amount];
  }
};
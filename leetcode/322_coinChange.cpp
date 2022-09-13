#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;
void print(vector<int> cur){
  for (auto it : cur){cout << it<<", ";}
  cout << endl;
}
class Solution {
public:
  int coinChange(const vector<int>& coins, int amount) {
    vector<int> memo(amount+1, INT_MAX);
    memo[0] = 0;
    for (int i=0; i != amount +1; i++){
      for (auto change: coins){
        if (i < change) {continue;}
        if (memo[i - change] == INT_MAX){continue;}
        memo[i] = min(memo[i], 1 + memo[i - change]);
      }
    }
    return (memo[amount] ==  INT_MAX) ? -1 : memo[amount];
  }
};

int main()
{
  vector<int> coins = {1,4, 8, 9};
  
  Solution sol;
  cout << sol.coinChange(coins, 12)<<endl;
  coins = vector<int> {2};
  cout << sol.coinChange(coins, 3)<<endl;
  return 0;
}
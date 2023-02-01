/*
256. Paint House
There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
Return the minimum cost to paint all houses.
*/
class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    int n=costs.size();
    int minCost=INT_MAX;
    vector<vector<int>> memo(n, vector<int>(3, -1));
    for (int i=0; i<3; i++){
      minCost = min(minCost, costs[0][i] + cost(costs, 1, i, n, memo));
    }
    return minCost;
  }
private:
  int cost(vector<vector<int>>& costs, int row, int prev, int& n, vector<vector<int>>& memo){
    if(row == n)
      return 0;
    if (memo[row][prev] != -1)
      return memo[row][prev];
    int ans=INT_MAX;
    for (int i=0; i<3; i++){
      if (i == prev)
        continue;
      ans = min(ans, costs[row][i] + cost(costs, row + 1, i, n, memo));
    }
    return memo[row][prev] = ans;
  }
};

/*
1029. Two City Scheduling
A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
*/
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
       if (a[0] - a[1] == b[0] - b[1])
         return a[0] < b[0];
      else
        return a[0] - a[1] < b[0] - b[1];
    });
    int minCost=0;
    int n=costs.size();
    for (int i=0; i<n; i++){
      //cout << costs[i][0] <<", "<<costs[i][1]<<endl;
      if (i < n /2)
        minCost += costs[i][0];
      else
        minCost += costs[i][1];
    }
    return minCost;
  }
};
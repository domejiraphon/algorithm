bool sortby(const vector<int>& a, const vector<int>& b){
  return a[2] < b[2];
}
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int n=costs.size();
    for (int i=0; i<n; i++){
      costs[i].push_back(costs[i][0] - costs[i][1]);
    }
    sort(costs.begin(), costs.end(), sortby);
    int cost(0);
    for (int i=0; i< n; i++){
      cost = (i < (int) n /2) ? cost + costs[i][0] : cost + costs[i][1];
    }
    return cost;
  }
};

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    int n=cost.size();
    int prev = cost[0], cur = cost[1], tmp;
    for (int i=2; i<n; i++){
      tmp = cost[i] + min(prev, cur);
      prev = cur;
      cur = tmp;
    }
    return cur;
  }
};

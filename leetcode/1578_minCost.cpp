class Solution {
public:
  int minCost(string colors, vector<int>& neededTime) {
    int cost(0);
    char prev=colors[0];
    int prev_cost = neededTime[0];
    int n(colors.size());
    for (int i=1; i < n; i++){
      if (colors[i] == prev){
        if (prev_cost < neededTime[i]){
          cost += prev_cost; prev_cost = neededTime[i];
        }
        else {
          cost += neededTime[i];
        }
      }
      else{
        prev = colors[i];
        prev_cost = neededTime[i];
      }
    }
    return cost;
  }
};

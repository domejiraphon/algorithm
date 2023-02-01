class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<unordered_set<int>> adj(n);
    int m=roads.size();
    for (auto road: roads){
      adj[road[0]].insert(road[1]);
      adj[road[1]].insert(road[0]);
    }
    int count(INT_MIN);
    for (int i=0; i<n; i++){
      for (int j=i+1; j<n;j++){
        int cur = adj[i].size() + adj[j].size();
        if (adj[i].count(j)){
          cur--;
        }
        count = max(count, cur);
      }
    }
    return count;
  }
};

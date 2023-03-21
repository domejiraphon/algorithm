/*
1466. Reorder Routes to Make All Paths Lead to the City Zero
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.
*/
class Solution {
  int out=0;
public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto road: connections){
      adj[road[0]].push_back({road[1], 1});
      adj[road[1]].push_back({road[0], 0});
    }
    dfs(adj, 0, -1);
    return out;
  }
private:
  void dfs(vector<vector<pair<int, int>>>& adj, int cur, int parent){
    for (auto [next, sign]: adj[cur]){
      if (next != parent){
        out += sign;
        dfs(adj, next, cur);
      }
    }
  }
};

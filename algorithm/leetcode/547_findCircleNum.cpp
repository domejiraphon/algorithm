/*
547. Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 
*/
class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    vector<vector<int>> adj(n+1);
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        if (i == j)
          continue;
        if (isConnected[i][j])
          adj[i+1].push_back(j+1);
      }
    }
    vector<bool> visited(n+1, false);
    int res=0;
    for (int i=1; i<=n; i++){
      if (!visited[i]){
        visited[i] = true;
        dfs(adj, i, visited);
        res++;
      }
    }
    return res;
  }
private:
  void dfs(vector<vector<int>>& adj, int i, vector<bool>& visited){
    for (auto neigh: adj[i]){
      if (!visited[neigh]){
        visited[neigh] = true;
        dfs(adj, neigh, visited);
      }
    }
    
  }
};
/*
797. All Paths From Source to Target
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
*/
class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<vector<int>> res;
    vector<int> cur = {0};
    dfs(graph, 0, n, res, cur);
    return res;
  }
private:
  void dfs(vector<vector<int>>& graph, int i, int& n, vector<vector<int>>& res, vector<int>& cur){
    if (i == n-1){
      res.push_back(cur);
      return;
    }
    for (auto neigh: graph[i]){
      cur.push_back(neigh);
      dfs(graph, neigh, n, res, cur);
      cur.pop_back();
    }
  }
};
class Solution {
private:
  vector<vector<int>> adj;
  int n;
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    n = graph.size() - 1;
    adj = graph;
    vector<int> path{0};
    vector<vector<int>> res;
    backtrack(0, path, res);
    return res;
  }
private:
  void backtrack(int idx, vector<int>& cur, vector<vector<int>>& res){
    if (idx == n){res.push_back(cur); return;}
    for (auto node: adj[idx]){
      cur.push_back(node);
      backtrack(node, cur, res);
      cur.pop_back();
    }
  }
};

/*
399. Evaluate Division
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
*/
class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> var;
    int n=equations.size();
    for (int i=0; i<n; i++){
      var[equations[i][0]].push_back({equations[i][1], values[i]});
      var[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
    }
    vector<double> res;
    for (auto query: queries){
      unordered_set<string> visited={};
      res.push_back(dfs(query[0], query[1], visited, var));
    }
    return res;
  }
private:
  double dfs(string& a, string& b, unordered_set<string>& visited, unordered_map<string, vector<pair<string, double>>> var){
    if (!var.count(a))
      return -1;
    if (a ==b)
      return 1;
    double out=-1;
    for (auto neigh: var[a]){
      if (visited.count(neigh.first))
        continue;
      visited.insert(neigh.first);
      out = dfs(neigh.first, b, visited, var);
      if (out != -1)
        return out * neigh.second;
    }
    return out;
  }
};
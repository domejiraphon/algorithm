/*
886. Possible Bipartition
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.
*/
class Solution {
public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(n+1);
  
    int m=dislikes.size();
    for (int i=0; i<m; i++){
      graph[dislikes[i][0]].push_back(dislikes[i][1]);
      graph[dislikes[i][1]].push_back(dislikes[i][0]);
    }
    vector<int> colors(n+1, -1);
    
    for (int i=1; i<=n; i++){
      if (colors[i] == -1){
        if (!bfs(graph, colors, i))
          return false;
      }
    }
    return true;
  }
private:
  bool bfs(vector<vector<int>>& graph, vector<int>& colors, int source){
    queue<int> Q;
    Q.push(source);
    colors[source] = 0;
    while (!Q.empty()){
      
      int len = Q.size();
      for (int i=0; i<len; i++){
        int cur = Q.front();
        Q.pop();
        for (auto neigh: graph[cur]){
          
          if (colors[neigh] == colors[cur])
            return false;
          if (colors[neigh] == -1){
            colors[neigh] = 1 - colors[cur];
            Q.push(neigh);
          }
         
        }
      }
    }
    return true;
  }
};

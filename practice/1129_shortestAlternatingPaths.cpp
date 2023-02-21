/*
1129. Shortest Path with Alternating Colors
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
*/
class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, 
      vector<vector<int>>& redEdges, 
    vector<vector<int>>& blueEdges) 
  {
    vector<vector<pair<int, int>>> adj(n);
    for (int i=0; i<redEdges.size(); i++)
      adj[redEdges[i][0]].push_back({redEdges[i][1], 0});
    for (int i=0; i<blueEdges.size(); i++)
      adj[blueEdges[i][0]].push_back({blueEdges[i][1], 1});
    
    queue<vector<int>> Q;

    Q.push({0, 0, -1});
    vector<int> res(n, -1);
    res[0] = 0;
    
    vector<vector<bool>> visited(n, vector<bool>(2, false));
    while (!Q.empty()){
      vector<int> cur = Q.front();
      int node = cur[0], step = cur[1], prevColor = cur[2];
      Q.pop();
      
      
      for (auto neigh: adj[node]){
        if (neigh.second != prevColor && !visited[neigh.first][neigh.second]){
          visited[neigh.first][neigh.second] = true;
          Q.push({neigh.first, step + 1, neigh.second});
          if (res[neigh.first] == -1)
            res[neigh.first] = step + 1;
          
        }
      }
   
    }
    
    return res;
  }
};

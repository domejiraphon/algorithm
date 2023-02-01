/*
1168. Optimize Water Distribution in a Village
There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i - 1] (note the -1 due to 0-indexing), or pipe in water from another well to it. The costs to lay pipes between houses are given by the array pipes where each pipes[j] = [house1j, house2j, costj] represents the cost to connect house1j and house2j together using a pipe. Connections are bidirectional, and there could be multiple valid connections between the same two houses with different costs.

Return the minimum total cost to supply water to all houses.
*/
class Solution {
public:
  int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
    vector<vector<pair<int, int>>> graph(n+1);
    int k=pipes.size();
    for (int i=0; i<k; i++){
      graph[pipes[i][0]].push_back({pipes[i][2], pipes[i][1]});
      graph[pipes[i][1]].push_back({pipes[i][2], pipes[i][0]});
    }
    for (int i=0; i<n; i++)
      graph[0].push_back({wells[i], i+1});
    bool isMst[n+1];
    memset(isMst, false, sizeof(isMst));
    int usedEdge=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    minHeap.push({0, 0});
    int cost=0;
    
    
    while (usedEdge < n+1){
      pair<int, int> cur = minHeap.top();
      minHeap.pop();
      if (isMst[cur.second])
        continue;
      isMst[cur.second] = true;
      cost += cur.first;
      
      for (auto nextHouses: graph[cur.second]){
        if (!isMst[nextHouses.second]){
          minHeap.push(nextHouses);
        }
      }
      usedEdge++;
    }
    return cost;
  }
};

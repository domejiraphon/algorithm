class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n=points.size();
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    minHeap.push({0, 0});
    vector<bool> inMst(n);
    int res(0);
    int edge(0);
    
    while (edge < n){
      pair<int, int> topElement = minHeap.top();
      minHeap.pop();
      
      int weight = topElement.first;
      int currNode = topElement.second;
      
      if (inMst[currNode]){continue;}
      
      inMst[currNode] = true;
      res += weight;
      edge++;
      
      for (int i=0; i< n; i++){
        if (!inMst[i]){
          int dist = abs(points[i][0] - points[currNode][0]) + abs(points[i][1] - points[currNode][1]);
          minHeap.push({dist, i});
        }
      }
    }
    return res;
  }
};

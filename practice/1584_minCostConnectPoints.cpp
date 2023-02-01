/* 1584. Min Cost to Connect All Points
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
*/
class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n=points.size();
    int edgeUsed=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, 0});
    bool inMst[n];
    memset(inMst, false, sizeof(inMst));
    int cost=0;
    while (edgeUsed < n){
      pair<int, int> cur = minHeap.top();
      
      minHeap.pop();
      if (inMst[cur.second])
        continue;
      inMst[cur.second] = true;
      cost += cur.first;

      for (int i=0; i<n; i++){
        if (!inMst[i]){
          int dist = abs(points[i][0] - points[cur.second][0]) +
                      abs(points[i][1] - points[cur.second][1]);
          minHeap.push({dist, i});
        }
      }
      edgeUsed++;
    }
    return cost;
  }
};
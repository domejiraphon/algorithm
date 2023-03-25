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

class UnionFind {
public:
  vector<int> group;
  vector<int> rank;
  UnionFind(int n){
    group.resize(n);
    rank.resize(n);
    for (int i=0; i<n; i++)
      group[i] = i;
  }
  int find(int n){
    if (group[n] != n)
      group[n] = find(group[n]);
    return group[n];
  }

  bool join(int n1, int n2){
    int group1 = find(n1);
    int group2 = find(n2);
    if (group1 == group2)
      return false;
    group[group2] = group1;
    if (rank[group1] > rank[group2])
      group[group2] = group1;
    else if (rank[group1] < rank[group2])
      group[group1] = group2;
    else{
      group[group1] = group2;
      rank[group2] += 1;
    }
    return true;
  }
};

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<pair<int, pair<int, int>>> allEdges;
    for (int i=0; i<n; i++){
      for (int j=i+1; j<n; j++){
        int dist = abs(points[i][0] - points[j][0]) +
                   abs(points[i][1] - points[j][1]);
        allEdges.push_back({dist, {i, j}});
      }
    }
    sort(allEdges.begin(), allEdges.end());
    UnionFind uf(n);
    int cost=0;
    int edge=0;
    for (int i=0; i<allEdges.size() && edge < n - 1; i++){
      int n1 = allEdges[i].second.first;
      int n2 = allEdges[i].second.second;
      if (uf.join(n1, n2)){
        cost += allEdges[i].first;
        edge++;
      }
    }
    
    return cost;
  }
};
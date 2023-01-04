/* 973. K Closest Points to Origin
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/
class Compare {
public:
  bool operator () (pair<int, int> a, pair<int, int> b){
    return pow(a.first, 2) + pow(a.second, 2) < pow(b.first, 2) + pow(b.second, 2);
  }
};
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;
    int n=points.size();
    for (int i=0; i<n; i++){
      maxHeap.push({points[i][0], points[i][1]});
      if (maxHeap.size() > k)
        maxHeap.pop();
    }
    vector<vector<int>> res(k, vector<int>(2));
    int i=0;
    while (i<k){
      pair<int, int> cur= maxHeap.top();
      res[i][0] = cur.first;
      res[i++][1] = cur.second;
      maxHeap.pop();
    }
    return res;
  }
};
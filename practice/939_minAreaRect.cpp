/*
939. Minimum Area Rectangle
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
*/
class Solution {
public:
  int minAreaRect(vector<vector<int>>& points) {
    set<pair<int, int>> set;
    for (auto point: points)
      set.insert({point[0], point[1]});
    int area=INT_MAX;
    int n=points.size();
    for (int i=0; i<n; i++){
      for (int j=i+1; j<n; j++){
        vector<int> point1 = points[i];
        vector<int> point2 = points[j];
        if (point1[0] == point2[0] || 
            point1[1] == point2[1])
          continue;
        if (set.count({point1[0], point2[1]}) && set.count({point2[0], point1[1]}))
           
          area = min(area, abs((point2[0] - point1[0]) * (point2[1] - point1[1])));
        
      }
    }
    return area == INT_MAX ? 0 : area;
  }
};

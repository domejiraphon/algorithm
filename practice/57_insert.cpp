class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    intervals.push_back(vector<int> {INT_MAX, INT_MAX});
    int n=intervals.size();
    int i(0);
    for (auto in: intervals){
      if (newInterval[1] < in[0]){
        res.push_back(newInterval);
        newInterval = in;
      }
      else if (in[1] < newInterval[0]){
        res.push_back(in);
      }
      else {
        newInterval[0] = min(in[0], newInterval[0]);
        newInterval[1] = max(in[1], newInterval[1]);
      }
    }
     
    return res;
  }
};
/*
56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and 
return an array of the non-overlapping intervals that cover all the intervals in the input.
*/
bool sortby(vector<int> a, vector<int> b){
  return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
}
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    intervals.push_back(vector<int> {INT_MAX, INT_MAX});
    sort(intervals.begin(), intervals.end(), sortby);
    int n=intervals.size();
    int time[2] = {intervals[0][0], intervals[0][1]};
    for (int i=1; i<n; i++){
      if (intervals[i][0] <= time[1]){
        time[0] = min(time[0], intervals[i][0]);
        time[1] = max(time[1], intervals[i][1]);
      }
      else {
        res.push_back(vector<int> {time[0], time[1]});
        time[0] = intervals[i][0]; 
        time[1] = intervals[i][1];
      }
    }
    return res;
  }
};
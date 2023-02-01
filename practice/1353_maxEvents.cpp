/*
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.
*/
class Solution {
public:
  int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());
    int n=events.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int i=0, d= 0;
    int res=0;
    while (i<n || !minHeap.empty()){
      if (minHeap.empty())
        d = events[i][0];
      while (i<n && events[i][0] <= d)
        minHeap.push(events[i++][1]);
      minHeap.pop();
      d++;
      while (!minHeap.empty() && minHeap.top() < d)
        minHeap.pop();
      res++; 
    }
    return res;
  }
};

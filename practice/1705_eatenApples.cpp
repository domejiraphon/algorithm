/*
1705. Maximum Number of Eaten Apples
There is a special kind of apple tree that grows apples every day for n days. On the ith day, the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.

You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.

Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.
*/
class Compare{
public:
  bool operator() (pair<int, int>& a, pair<int, int>& b){
    return a.second >b.second;
  }
};

class Solution {
public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
    int n=apples.size();
    int count=0;
    for (int i=0; i<n || minHeap.size(); i++){
      while (!minHeap.empty() && minHeap.top().second < i){
        minHeap.pop();
      }
      if (i < n && apples[i] != 0 && days[i] != 0)
        minHeap.push({apples[i], i + days[i]-1});
      
      if (!minHeap.empty()){
        pair<int, int> cur = minHeap.top();
        count++;
        minHeap.pop();
        if (cur.first > 1 && cur.second > i)
          minHeap.push({cur.first - 1, cur.second});
      }
       
    }
    
    return count;
  }
};

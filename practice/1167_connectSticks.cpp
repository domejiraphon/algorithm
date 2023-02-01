class Comparator{
public:
  int operator() (int a, int b){
    return a > b;
  }
};
class Solution {
public:
  int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, Comparator> minHeap;
    for (auto stick: sticks){
      minHeap.push(stick);
    }
    int res(0);
    while (minHeap.size() > 1){
      int tmp = minHeap.top();
      minHeap.pop();
      int cur = tmp + minHeap.top();
      res += cur;
      minHeap.pop();
      minHeap.push(cur);
    }
    return res;
  }
};

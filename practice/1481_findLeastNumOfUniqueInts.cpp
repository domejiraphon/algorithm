/*
1481. Least Number of Unique Integers after K Removals
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
*/
class Compare {
public:
  bool operator () (int a, int b){
    return a > b;
  }
};

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int n=arr.size();
    for (int i=0; i<n; i++)
      freq[arr[i]]++;
    priority_queue<int, vector<int>, Compare> minHeap;
    for (auto it =freq.begin(); it != freq.end(); it++)
      minHeap.push(it -> second);
    int sum=0;
    while (k > 0){
      if (k >= minHeap.top()){
        k -= minHeap.top();
        minHeap.pop();
      }
      else {
        k = 0;
      }
    }

    return minHeap.size();
  }
};

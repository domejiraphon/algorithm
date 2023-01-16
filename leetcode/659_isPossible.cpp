/*
659. Split Array into Consecutive Subsequences

You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some 
(can be none) of the elements without disturbing the relative positions of the remaining elements. 
(i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).
*/
class Compare {
public:
  bool operator () (pair<int, int>& a, pair<int, int>& b){
    return a.second == b.second ? a.second - a.first > b.second - b.first : a.second > b.second;
  }
};
class Solution {
public:
  bool isPossible(vector<int>& nums) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
    int i=0;
    int n=nums.size();
    while (i < n){
      while (!minHeap.empty() && minHeap.top().second + 1 < nums[i]){
        pair<int, int> prev = minHeap.top();
        if (prev.second - prev.first < 2)
          return false;
        minHeap.pop();
      }
      if (minHeap.empty() || minHeap.top().second == nums[i])
        minHeap.push({nums[i], nums[i]});
      else if (minHeap.top().second + 1 == nums[i]){
        pair<int, int> prev = minHeap.top();
        minHeap.pop();
        minHeap.push({prev.first, prev.second + 1});
      }
      i++;
    }
    while (!minHeap.empty()){
      pair<int, int> cur = minHeap.top();
      if (cur.second - cur.first < 2)
        return false;
      minHeap.pop();
    }
    return true;
  }
};
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
  bool operator() (pair<int, int> a, pair<int, int> b){
    return (a.second == b.second) ? a.second - a.first > b.second - b.first : a.second > b.second;
  }
};

class Solution {
public:
  bool isPossible(vector<int>& nums) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
    int n=nums.size();
    minHeap.push({nums[0], nums[0]});
    for(int i=1; i <n; i++){
      
      while (!minHeap.empty() && nums[i] > minHeap.top().second + 1) {
        pair<int, int> prev = minHeap.top();
        minHeap.pop();
        if (prev.second - prev.first + 1 < 3){return false;}
      }

      if (minHeap.empty() || nums[i] == minHeap.top().second){
        minHeap.push({nums[i], nums[i]});
      }
      else {
        pair<int, int> prev = minHeap.top();
        prev.second = nums[i];
        minHeap.pop(); minHeap.push(prev);
      }
     
    }
    bool possible = true;
    while (!minHeap.empty() && possible){
      pair<int, int> prev = minHeap.top();
      cout << prev.first << ", " << prev.second << endl;
      minHeap.pop();
      possible = possible && (prev.second - prev.first + 1 >= 3);
    }
    return possible;
  }
};

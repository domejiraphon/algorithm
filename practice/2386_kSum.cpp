/*
2386. Find the K-Sum of an Array

You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.

We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).

Return the K-Sum of the array.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Note that the empty subsequence is considered to have a sum of 0.


*/
class Compare {
public:
  bool operator () (pair<long long, int>& a, pair<long long, int>& b){
    return a.first > b.first;
  }
};

class Solution {
public:
  long long kSum(vector<int>& nums, int k) {
    int n=nums.size();
    long long maxSum=0;
    for (int i=0; i<n; i++){
      if (nums[i] > 0)
        maxSum += nums[i];
      else
        nums[i] = - nums[i];
    }
    if (k == 1)
      return maxSum;
    sort(nums.begin(), nums.end());
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, Compare> minHeap;
    minHeap.push({nums[0], 0});
    long long subtract=nums[0];
    while (k > 1){
      k--;
      pair<long long, int> cur = minHeap.top();
      minHeap.pop();
      subtract = cur.first;
      if (cur.second < n - 1){
        minHeap.push({cur.first + nums[cur.second + 1], cur.second + 1});
        minHeap.push({cur.first + nums[cur.second + 1] - nums[cur.second], cur.second + 1});
      }
    }
    return maxSum - subtract;
  }
};

/*
912. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
*/
class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto n: nums)
      minHeap.push(n);
    nums.clear();
    while (!minHeap.empty()){
      nums.push_back(minHeap.top());
      minHeap.pop();
    }
    return nums;
  }
};
/*
560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    int count=0;
    int prefixSum=0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i=0; i<n; i++){
      prefixSum += nums[i];
      if (map.count(prefixSum - k))
        count += map[prefixSum - k];
      map[prefixSum]++;
    }
    return count;
    
  }
};
/*
523. Continuous Subarray Sum
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 
*/
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    int sum=0;
    unordered_map<int, int> hash;
    hash[0] = 0;
    for (int i=0; i<n; i++){
      sum += nums[i];
      if (hash.count(sum % k)){
        int prev = hash[sum % k];
        if (i - prev > 0)
          return true;
      }
      else
        hash[sum % k] = i + 1;
    }
    return false;
  }
};

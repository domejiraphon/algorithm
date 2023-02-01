/*
53. Maximum Subarray
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.
*/
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    int maxSum=INT_MIN;
    int cur=0;
    for (int i=0; i<n; i++){
      cur = max(nums[i] + cur, nums[i]);
      maxSum = max(maxSum, cur);
    }
    return maxSum;
  }
};
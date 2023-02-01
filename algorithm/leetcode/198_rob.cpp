/*
198. House Robber

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping 
you from robbing each of them is that adjacent houses have security systems connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
*/
class Solution {
public:
  int rob(vector<int>& nums) {
    int n=nums.size();
    if (n==1){return nums[0];}
    vector<int> res(n);
    res[0] = nums[0]; res[1] = max(nums[0], nums[1]);
    for (int i=2; i<n; i++){
      res[i] = max(res[i-1], nums[i] + res[i - 2]);
    }
    return res[n-1];
  }
};
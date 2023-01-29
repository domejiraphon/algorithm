/*
325. Maximum Size Subarray Sum Equals k
Given an integer array nums and an integer k, return the maximum length of a 
subarray
 that sums to k. If there is not one, return 0 instead.


*/
class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int n=nums.size();
    int maxL = 0;
    unordered_map<long, int> map;
    long sum=0;
    map[0] = -1;
    for (int i=0; i<n; i++){
      sum = sum + (long) nums[i];
      if (!map.count(sum))
        map[sum] = i;
      if (map.count(sum - k))
        maxL = max(maxL, i - map[sum - k]);
        
    }
   
    return maxL;
  }
};

/*
896. Monotonic Array

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.
*/
class Solution {
public:
  bool isMonotonic(vector<int>& nums) {
    int n=nums.size();
    bool increase = (nums[0] <= nums[n-1]);
    for (int i=1; i<n; i++){
      if (increase && nums[i] < nums[i-1])
        return false;
      if (!increase && nums[i] > nums[i-1])
        return false;
    }
    return true;
  }
};
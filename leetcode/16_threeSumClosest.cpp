/*
16. 3Sum Closest
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n=nums.size();
    int closet=INT_MIN / 2;
    for (int i=0; i<n && closet != target; i++)
      twoSum(nums, i, target, closet);
    return closet;

  }
private:
  void twoSum(vector<int>& nums, int st, int target, int& closet){
    int n=nums.size();
    int left=st+1, right = n-1;
    while (left < right){
      int cur = nums[left] + nums[right] + nums[st];
      if (cur > target)
        right--;
      else if (cur < target)
        left++;
      else{
        closet = target;
        return;
      }
      if (abs(cur - target) < abs(closet - target))
        closet = cur; 
    }
  }
};
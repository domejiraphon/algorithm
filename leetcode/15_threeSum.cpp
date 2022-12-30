/*
15. 3Sum
Given an integer array nums, 
return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i=0; i<n; i++){
      if (i != 0 && nums[i] == nums[i - 1]){continue;}
      int left = i + 1, right = n -1;
      while (left < right){
        int sum = nums[i] + nums[left] + nums[right];
        if (sum < 0) left++;
        else if (sum > 0) right--;
        else {
          res.push_back(vector<int> {nums[i], nums[left], nums[right]});
          left++;
          while (left < right && nums[left] == nums[left - 1]){
            left++;
          }
        }
      }
    }
    return res;
  }
};
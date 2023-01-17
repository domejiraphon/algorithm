/*
18. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i=0; i<n; i++){
      if (i != 0 && nums[i] == nums[i - 1])
          continue;
      for (int j=i+1; j<n; j++){
        if (j != i+1 && nums[j] == nums[j - 1])
          continue;
        twoSum(nums, i, j, target, n, res);
      }
    }
    return res;
  }
private:
  void twoSum(vector<int>& nums, int i, int j, int& target, int& n, vector<vector<int>>& res){
    int left = j+1;
    int right = n - 1;
    while (left< right){
      long  cur = (long) nums[i] + nums[j] + nums[left] + nums[right];
      if (cur == target){
        res.push_back({nums[i], nums[j], nums[left++], nums[right]});
        while (left < n && nums[left] == nums[left - 1])
          left++;
      }
      else if (cur < target)
        left++;
      else
        right--;
    }
  }
};
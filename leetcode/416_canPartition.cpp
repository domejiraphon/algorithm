/*
416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/
class Solution {
  int n;
public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
      return false;
    sort(nums.begin(), nums.end());
    n = nums.size();
    vector<vector<int>> memo (n, vector<int> (sum/2 + 1, -1));
    return helper(0, sum / 2, nums, memo);
  }
private:
  bool helper(int i, int target, vector<int>& nums, vector<vector<int>>& memo){
    if (target == 0)
      return true;
    else if (target < 0)
      return false;
    if (i >= n)
      return false;
    if (memo[i][target] != -1)
      return memo[i][target] == 1;
    bool out;
    out = helper(i + 1, target - nums[i], nums, memo) || helper(i + 1, target, nums, memo);
    memo[i][target] = out ? 1 : 0;
    return out;
  }
};
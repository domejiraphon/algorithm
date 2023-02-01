/*
494. Target Sum
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int sum=accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> memo(n, vector<int>(2*sum+1, -1));

    return count(nums, 0, 0, target, n, sum, memo);
  }
private:
  int count(vector<int>& nums, int i, int cur, int& target, int& n,
        int& sum, vector<vector<int>>& memo){
    if (i == n)
      return (cur == target) ? 1 : 0;
    if (memo[i][cur+sum] != -1)
      return memo[i][cur+sum];
    int out=0;
    out += count(nums, i+1, cur + nums[i], target, n, sum, memo);
    out += count(nums, i+1, cur - nums[i], target, n, sum, memo);
    return memo[i][cur+sum] = out;
  }
};

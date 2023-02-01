/*
90. Subsets II
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
class Solution {
  int n;
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res ={};
    vector<int> cur = {};
    backtrack(0, nums, cur, res);
    return res;
  }
private:
  void backtrack(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res){
   
    res.push_back(cur);
    //backtrack(idx + 1, nums, cur, res);
    for (int i=idx; i<n; i++){
      if (i != idx && nums[i] == nums[i - 1])
        continue;
      cur.push_back(nums[i]);
      backtrack(i + 1, nums, cur, res);
      cur.pop_back();
    }
  }
};
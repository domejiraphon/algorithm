class Solution {
  int n;
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    n = nums.size();
    vector<vector<int>> res;
    vector<int> cur;
    helper(0, nums, cur, res);
    return res;
  }
private:
  void helper(int i, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res){
    if (i == n){
      res.push_back(cur);
      return;
    }
    helper(i + 1, nums, cur, res);
    cur.push_back(nums[i]);
    helper(i + 1, nums, cur, res);
    cur.pop_back();
  }
};
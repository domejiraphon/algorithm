/*
368. Largest Divisible Subset
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.


*/
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n=nums.size();
    vector<int> cur, res;
    for (int i=0; i<n; i++)
      helper(nums, i, 1, n, cur, res);
    return res;
  }
private:
  void helper(vector<int>& nums, int start, int prev, int n, vector<int>& cur, vector<int>& res){
    if (start == n)
      return;
    if (nums[start] % prev == 0){
      cur.push_back(nums[start]);
      if (cur.size() > res.size())
        res = cur;
      helper(nums, start+1, nums[start], n, cur, res);
      cur.pop_back();
    }
    helper(nums, start+1, prev, n, cur, res);
  }
};

class Solution {
  unordered_map<int, vector<int>> memo;
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n=nums.size();
    vector<int> maxSubset;
    for (int i=0; i<n; i++){
      vector<int> cur = EDS(i, nums);
      if (cur.size() > maxSubset.size())
        maxSubset = cur;
    }
    return maxSubset;
  }
private:
  vector<int> EDS(int i, vector<int>& nums){
    if (memo.count(i))
      return memo[i];
    vector<int> maxSubset;
    for (int k=0; k<i; ++k){
      if (nums[i] % nums[k] == 0){
        vector<int> subset = EDS(k, nums);
        if (maxSubset.size() < subset.size())
          maxSubset = subset;
      }
    }
    maxSubset.push_back(nums[i]);
    return memo[i] = maxSubset;
  }
};
/*
39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> cur;
    vector<vector<int>> res;
    int n=candidates.size();
    sum(candidates, 0, target, 0, n, cur, res);
    return res;
  }
private:
  void sum(vector<int>& candidates, int cur, int target, int st, int& n, vector<int> prev, vector<vector<int>>& res){
    if (cur == target){
      res.push_back(prev);
      return;
    }
    if (st == n)
      return;
    sum(candidates, cur, target, st +1, n, prev, res);
    int curSum = cur;
    while (curSum < target){
      curSum += candidates[st];
      prev.push_back(candidates[st]);
      sum(candidates, curSum, target, st + 1, n, prev, res);
    }
  }
};
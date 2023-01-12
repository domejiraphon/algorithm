/*
334. Increasing Triplet Subsequence
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
*/
class Solution2 {
public:
  bool increasingTriplet(vector<int>& nums) {
    int n=nums.size();
    bool out=false;
    vector<vector<int>> memo(n, vector<int> (3, -1));
    for (int i=n-2; i>=0 && !out; i--)
      out = check(nums, i, 1, n, memo);
    
    return out;
  }
private:
  bool check(vector<int>& nums, int start, int target, int& n, 
            vector<vector<int>>& memo){
    if (target == 3)
      return true;
    if (memo[start][target] != -1)
      return memo[start][target] == 1;
    bool out=false;
    for (int i=start+1; i<n && !out; i++){
      if (nums[i] > nums[start])
        out = check(nums, i, target + 1, n, memo);
    }
    memo[start][target] = out ? 1 : 0;
    return out;
  }
};

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    for (auto n: nums){
      if (n <= first)
        first = n;
      else if (n <= second)
        second = n;
      else if (n > second)
        return true;
    }
    return false;
  }
private:
};

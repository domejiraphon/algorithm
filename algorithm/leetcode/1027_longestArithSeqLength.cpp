/*
1027. Longest Arithmetic Subsequence
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
*/
class Solution {
public:
  int longestArithSeqLength(vector<int>& nums) {
    int n=nums.size();
    int longest=0;
    vector<vector<int>> memo(n, vector<int> (n, -1));
    for (int i=0; i<n; i++){
      for (int j=i+1; j<n; j++){
        longest = max(longest, 2 + length(nums, i, j, n, memo));
      }
    }
    return longest;
  }
private:
  int length(vector<int>& nums, int prev, int st, int& n, vector<vector<int>>& memo){
    if (st == n)
      return 0;
    if (memo[prev][st] != -1)
      return memo[prev][st];
    int out=0;
    for (int i=st+1; i<n; i++){
      if (nums[i] - nums[st] == nums[st] - nums[prev])
        out = max(out, 1 + length(nums, st, i, n, memo));
    }
    return memo[prev][st] = out;
  }
};
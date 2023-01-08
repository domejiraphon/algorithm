/*
1027. Longest Arithmetic Subsequence
Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Note that:

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
*/
class Solution {
  int n;
  vector<vector<int>> memo;
public:
  int longestArithSeqLength(vector<int>& nums) {
    n = nums.size();
    int out=0;
    memo.resize(n, vector<int>(1001, -1));
    for (int i=0; i<n; i++){
      out = max(out, longestSub(nums, i));
    }
    return out;
  }
private:
  int longestSub(vector<int>& nums, int start, int diff=INT_MIN){
    if (start == n - 1)
      return 1;

    if (diff != INT_MIN && memo[start][diff+500] != -1)
      return memo[start][diff+500];
    int out=0;
    for (int i=start+1; i<n; i++){
      if (diff == INT_MIN || nums[i] - nums[start] == diff){
        out = max(out, longestSub(nums, i, nums[i] - nums[start]));
      }
    }
    if (diff !=INT_MIN)
      memo[start][diff+500] = out + 1;
    return out + 1;
  }
};

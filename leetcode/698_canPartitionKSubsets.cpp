/*
698. Partition to K Equal Sum Subsets
Given an integer array nums and an integer k, 
return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
*/
class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0)
      return false;
    int n=nums.size();
    int targetSum = sum / k;
    sort(nums.begin(), nums.end(), greater<int> ());
    string visited(n, '0');
    unordered_map<string, bool> memo;
    return helper(nums, visited, targetSum, 0, targetSum, n, k, 0, memo);
  }
private:
  bool helper(vector<int>& nums, string& visited, int cur, int count, int& targetSum, int& n, int& k, int idx, unordered_map<string, bool>& memo){
    if (count == k-1)
      return true;
    if (memo.count(visited))
      return memo[visited];
    if (cur == 0)
      return memo[visited] = helper(nums, visited, targetSum, count+1, targetSum, n, k, 0, memo);
    for (int i=idx; i<n; i++){
      if (visited[i] == '0' && nums[i] <= cur){
        visited[i] = '1';
        if (helper(nums, visited, cur - nums[i], count, targetSum, n, k, i+1, memo))
          return true;
        visited[i] = '0';
      }
    }
    return memo[visited]= false;
  }
};
/*
456. 132 Pattern
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.
*/
class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n=nums.size();
    vector<int> minNums(n);
    minNums[0] = nums[0];
    for (int i=1; i<n; i++)
      minNums[i] = min(minNums[i-1], nums[i]);
    stack<int> stk;
    for (int j=1; j<n; j++){
      if (minNums[j] > nums[j])
        continue;
      while (!stk.empty() && nums[stk.top()] < nums[j])
        stk.pop();
      if (stk.size() > 0 && nums[stk.top()] > nums[j] && nums[j] > minNums[stk.top()]){
        return true;
      }
        
      stk.push(j);
    }
    return false;
  }
};
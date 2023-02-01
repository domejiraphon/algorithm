/*
448. Find All Numbers Disappeared in an Array
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
*/
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n=nums.size();
    unordered_set<int> in = {nums.begin(), nums.end()};
    vector<int> res;
    for (int i=1; i<=n; i++)
      if (!in.count(i))
        res.push_back(i);
    return res;
  }
};

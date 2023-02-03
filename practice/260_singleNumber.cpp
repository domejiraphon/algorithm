/*
260. Single Number III
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
*/
class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (auto i: nums)
      freq[i]++;
    vector<int> res;
    for (auto it: freq){
      if (it.second == 1)
        res.push_back(it.first);
    }
    return res;
  }
};

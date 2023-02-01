/*
137. Single Number II
Given an integer array nums where every element appears three times except for one, which appears exactly once. 
Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int, int> freq;
    for (int i=0; i<n; i++){
      freq[nums[i]]++;
    }
    for (auto it=freq.begin(); it != freq.end(); it++){
      if (it -> second == 1)
        return it -> first;
    }
    return -1;
  }
};

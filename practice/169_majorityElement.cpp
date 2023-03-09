/*
169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n=nums.size();
    for (int i=0; i<n; i++){
      freq[nums[i]]++;
      if (freq[nums[i]] > n / 2)
        return nums[i];
    }
    return -1;
  }
};
/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int n=nums.size();
    int st = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if(st == n || nums[st] != target)
      return {-1, -1};
    int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return {st, end - 1};
  }
};
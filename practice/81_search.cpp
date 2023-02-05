/*
81. Search in Rotated Sorted Array II
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
*/
class Solution {
public:
  bool search(vector<int>& nums, int target) {
   
    int pivot=0;
    for (; pivot<nums.size()-1; pivot++){
      if (nums[pivot] > nums[pivot + 1])
        break;
    }
    pivot++;

    int idx = lower_bound(nums.begin(), nums.begin() + pivot, target) - nums.begin();
    
    if (idx < nums.size() && nums[idx] == target)
      return true;
    if (pivot < nums.size()){
      idx = lower_bound(nums.begin() + pivot, nums.end(), target) - nums.begin();
      if (idx < nums.size() && nums[idx] == target)
        return true;
    }
    
    return false;
    
  }
private:
  int findPivot(vector<int>& nums, int st, int end){
    if (nums[st] < nums[end])
      return 0;
    while (st <= end){
      int pivot = (st + end) / 2;
      if (nums[pivot] > nums[pivot + 1])
        return pivot + 1;
      else if (nums[pivot] < nums[st])
        end = pivot - 1;
      else
        st = pivot + 1;
    }
    return 0;
  }
};

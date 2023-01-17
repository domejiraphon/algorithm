/*
33. Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 1)
      return (nums[0] == target) ? 0 : -1;
    int pivot = findPivot(nums, 0, nums.size()-1);

    int left = lower_bound(nums.begin(), nums.begin() + pivot, target) - nums.begin();
    if (nums[left] == target)
      return left;
   
    int right = lower_bound(nums.begin() + pivot, nums.end(), target) - nums.begin();
    
    if (right < nums.size() && nums[right] == target)
      return right;
    return -1;
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
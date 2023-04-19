/*
1060. Missing Element in Sorted Array
Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, return the kth missing number starting from the leftmost number of the array.
*/
class Solution {
public:
  int missingElement(vector<int>& nums, int k) {
    
    int n=nums.size();
    for (int i=0; i<n-1; i++){
      int miss = nums[i+1] - nums[i];
      if (miss > k)
        return nums[i] + k;
      k -= (miss - 1);
    }
    return nums[n-1] + k;
  }
};

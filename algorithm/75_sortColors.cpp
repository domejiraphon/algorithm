/*
75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int left=0, right=0;
    int n=nums.size();
    int i=0;
    while (i<n){
      if (nums[i] == 0){
        swap(nums[i], nums[left++]);
        right = max(left, right);
      }
      if (nums[i] == 1)
        swap(nums[i], nums[right++]);
      i++;
    }
  }
};
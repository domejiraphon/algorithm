/*
162. Find Peak Element
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.
*/
class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int left=0, right = n - 1;
    while (left < right){
      int mid = (left + right) / 2;
      int leftVal = INT_MIN;
      int rightVal = INT_MIN;
      if (mid > left)
        leftVal = nums[mid - 1];
      if (mid < right)
        rightVal = nums[mid + 1];
      if (leftVal < nums[mid] && nums[mid] > rightVal)
        return mid;
      else if (nums[mid] < rightVal)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return left;
  }
};
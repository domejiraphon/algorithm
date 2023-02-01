/** 2340. Minimum Adjacent Swaps to Make a Valid Array
 * You are given a 0-indexed integer array nums.
 * Swaps of adjacent elements are able to be performed on nums.
 * A valid array meets the following conditions:
 * The largest element (any of the largest elements if there are multiple) is at the rightmost position in the array.
 * The smallest element (any of the smallest elements if there are multiple) is at the leftmost position in the array.
 * Return the minimum swaps required to make nums a valid array.
*/
class Solution {
public:
  int minimumSwaps(vector<int>& nums) {
    int n(nums.size());
    int maxVal(INT_MIN), minVal(INT_MAX);
    for (auto ele : nums){
      maxVal = max(maxVal, ele);
      minVal = min(minVal, ele);
    }
    int right, left(INT_MIN);
    for (int i=0; i < n; i++){
      if (nums[i] == maxVal){
        right = i;
      }
      if (left ==INT_MIN && nums[i] == minVal){
        left = i;
      }
    }
    return (left > right) ? n - right -1 + left - 1 : n - right -1 + left;
  }
};
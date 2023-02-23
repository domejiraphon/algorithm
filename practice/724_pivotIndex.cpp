/*
724. Find Pivot Index
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/
class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int n=nums.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    for (int i=1; i<n; i++)
      prefixSum[i] = prefixSum[i - 1] + nums[i];
    for (int i=0; i<n; i++){
      int left = prefixSum[i] - nums[i];
      int right = prefixSum[n-1] - prefixSum[i];
      if (left == right)
        return i;
    }
    return -1;
  }
};
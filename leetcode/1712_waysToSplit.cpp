/* 1712. Ways to Split Array Into Three Subarrays
A split of an integer array is good if:

The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
*/
class Solution {
public:
  int waysToSplit(vector<int>& nums) {
    int n=nums.size();
    vector<int> sum(n);
    sum[0] = nums[0];
    for (int i=1;i<n; i++){
      sum[i] = nums[i] + sum[i - 1];
    }
    int count=0;
    for (int i=0; i<n; i++){
      for (int j=i+1; j<n; j++){
        int mid = sum[j] - sum[i];
        if (sum[i] <= mid && mid <= sum[n - 1] - sum[j])
          count++;
      }
    }
    return count;
  }
};

/*
719. Find K-th Smallest Pair Distance
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
*/
class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int low = 0;
    int n=nums.size();
    int high = nums[n-1] - nums[0];
    
    while (low < high){
      int mid = (low + high)/2;
      int count=0;
      for (int i=0, j=0;i<n; i++){
        while (j<n && nums[j] - nums[i] <= mid)
          j++;
        count += j - i - 1;
      }
      
      if (count < k)
        low = mid + 1;
      else
        high = mid;
    }
    return low;
  }
};

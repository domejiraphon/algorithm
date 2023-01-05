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
    int mod = pow(10, 9) + 7;
    for (int i=1;i<n; i++){
      nums[i] = nums[i] + nums[i - 1];
    }
    int count=0;
    for (int i=0, low=0, high=0; i< n - 2; i++){
      low = max(i + 1, low);
      while (low < n - 1 && nums[low] - nums[i] < nums[i])
        low++;
      high = max(low, high);
      while (high < n && nums[high] - nums[i] <= nums[n - 1] - nums[high])
        high++;
      count = (count + high - low) % mod;
    }
    return count;
  }
};

class Solution {
public:
  int waysToSplit(vector<int>& nums) {
    int n=nums.size();
    for (int i=1;i<n; i++){
      nums[i] += nums[i - 1];
    }
    int count=0;
    for (int i=0; i<n; i++){
      for (int j=i+1; j<n; j++){
        int mid = nums[j] - nums[i];
        if (nums[i] <= mid && mid <= nums[n - 1] - nums[j])
          count++;
      }
    }
    return count;
  }
};

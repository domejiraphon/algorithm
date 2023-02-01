/*
2256. Minimum Average Difference
You are given a 0-indexed integer array nums of length n.

The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.

Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.

Note:

The absolute difference of two numbers is the absolute value of their difference.
The average of n elements is the sum of the n elements divided (integer division) by n.
The average of 0 elements is considered to be 0.

*/
class Solution {
public:
  int minimumAverageDifference(vector<int>& nums) {
    long sum = accumulate(nums.begin(), nums.end(), (long)0);
   
    int n=nums.size();
    long diff = LLONG_MAX;
    long cur =0;
    int out=n-1;
    for (int i=0; i<n; i++){
      cur = cur + nums[i];
      long first = cur / (i + 1);
      long  second = (i == n -1) ? 0 :(sum - cur) / (n - i -1);
      
      if (abs(first - second) < diff){
        out = i;
        diff = abs(first - second);
      }
      
    }
    return out;
  }
};

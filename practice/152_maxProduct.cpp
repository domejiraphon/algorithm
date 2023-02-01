/*
152. Maximum Product Subarray
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
*/
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n=nums.size();
    int maxVal=INT_MIN;
    int curMax=1, curMin=1;
    for (int i=0; i<n; i++){
      int tmp = curMax;
      curMax = max({curMax * nums[i], 
                    curMin * nums[i],
                    nums[i]});
      curMin = min({tmp * nums[i], 
                    curMin * nums[i],
                    nums[i]});
      maxVal = max({maxVal, curMax, curMin});
    }
    return maxVal;
  }
};
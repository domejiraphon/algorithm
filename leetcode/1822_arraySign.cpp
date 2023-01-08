/*
1822. Sign of the Product of an Array

There is a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).
*/
class Solution {
public:
  int arraySign(vector<int>& nums) {
    int n=nums.size(), numNeg=0;
  
    for (int i=0; i<n; i++){
      if (nums[i] < 0)
        numNeg++;
      if (nums[i] == 0)
        return 0;
    }
  
    return (numNeg % 2 == 0) ? 1 : -1;
  }
};

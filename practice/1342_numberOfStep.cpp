/*
1342. Number of Steps to Reduce a Number to Zero
Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
*/
class Solution {
public:
  int numberOfSteps(int num) {
    int dp[num+1];
    dp[0] =0;
    for (int i=1; i<= num; i++){
      if (i %2 == 0)
        dp[i] = 1 + dp[i / 2];
      else
        dp[i] = 1 + dp[i - 1];
    }
    return dp[num];
  }
};

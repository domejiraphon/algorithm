/*
357. Count Numbers with Unique Digits
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
*/
class Solution {
  int m;
  int memo[9][1024];
public:
  int countNumbersWithUniqueDigits(int n) {
    m = n;
    memset(memo, -1, sizeof(memo));
    return count(0, 0);
  }
private:
  int count(int i, int mask){
    if (i == m)
      return 1;
    if (memo[i][mask] != -1)
      return memo[i][mask];
    int out=0;
    for (int idx=0; idx<=9; idx++){
      if (mask & (1 << idx)){continue;}
      int cur = (mask == 0 && idx==0) ? mask : mask | (1 << idx);
      out += count(i + 1, cur);
    }
    return memo[i][mask] = out;
  }
};

/*
264. Ugly Number II
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.
*/
class Solution {
public:
  int nthUglyNumber(int n) {
    if (n==1)
      return 1;
    vector<int> memo (n, 1);
    int ptr1=0, ptr2=0, ptr3=0;
    for (int i=1; i< n; i++){
      memo[i] = min({2* memo[ptr1], 3* memo[ptr2], 5*memo[ptr3]});
      
      if (memo[i] == 2* memo[ptr1])
        ptr1++;
      if (memo[i] == 3* memo[ptr2])
        ptr2++;
      if (memo[i] == 5* memo[ptr3])
        ptr3++;
    }
    
    return memo[n-1];
  }
};

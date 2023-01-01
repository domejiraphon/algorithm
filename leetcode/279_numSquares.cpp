/* 279. Perfect Squares
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. 
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/
class Solution {
public:
  int numSquares(int n) {
    vector<int>memo(n, INT_MAX);
    for (int i=1; pow(i, 2) <= n; i++){
      memo[pow(i, 2) - 1] = 1;
    }
    for (int i=1; i<= n; i++){
      for (int j=1; pow(j, 2) <i; j++){
        memo[i-1] = min(memo[i-1], 1 + memo[i - pow(j, 2) - 1]);
      }
    }
    return memo[n-1];
  }
};
/*
790. Domino and Tromino Tiling
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

*/
class Solution {
  int mod = pow(10, 9)+ 7;
public:
  int numTilings(int n) {
    long memo[n+1];
    memo[0] = 1;
    memo[1] = 1;
    if (n==1)
      return memo[1];
    memo[2] = 2;
    for (int i=3; i<=n ; i++){
      memo[i] = ((long) 2 * memo[i-3] + memo[i-2] + memo[i-1]) % mod;
      int k=i;
      while (k >= 4){
        memo[i] = (memo[i] + 2* memo[k-4]) % mod;
        
        k--;
      }
    }
    return memo[n];
  }
};

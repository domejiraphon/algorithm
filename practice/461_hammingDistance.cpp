/*
461. Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.
*/
class Solution {
public:
  int hammingDistance(int x, int y) {
    int count=0;
    for (int i=0; i<32 && (x != 0 || y != 0); i++){
      if ((x & 1) != (y & 1))
        count++;
      x >>= 1;
      y >>= 1;
    }
    return count;
  }
};

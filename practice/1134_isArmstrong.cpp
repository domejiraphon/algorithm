/*
Given an integer n, return true if and only if it is an Armstrong number.

The k-digit number n is an Armstrong number if and only if the kth power of each digit sums to n.
*/
class Solution {
public:
  bool isArmstrong(int n) {
    int temp=n;
    int k=log10(n)+1;
    while (temp>0){
      n -= pow(temp % 10, k);
      temp /= 10;
    }
    return (n==0);
  }
};

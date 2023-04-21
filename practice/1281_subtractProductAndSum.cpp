/*
Given an integer number n, return the difference between the product of its digits and the sum of its digits.
*/
class Solution {
public:
  int subtractProductAndSum(int n) {
    int prod=1;
    int sum=0;
    while (n > 0){
      int rem = n % 10;
      n /= 10;
      prod *= rem;
      sum += rem;
    }
    return prod - sum;
  }
};

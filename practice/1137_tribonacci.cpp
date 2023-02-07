/*
1137. N-th Tribonacci Number
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/
class Solution {
public:
  int tribonacci(int n) {
    if (n==0)
      return 0;
    else if(n==1)
      return 1;
    int prevN=0, prevN1=1, prevN2=1;
    int out=prevN2;
    for (int i=3; i<=n; i++){
      out = prevN + prevN1 + prevN2;
      prevN = prevN1;
      prevN1 = prevN2;
      prevN2 = out;
    }
    return out;
  }
};

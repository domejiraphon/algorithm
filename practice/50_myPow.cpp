#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
class Solution {
public:
  double myPow(double x, int n) {
  if (n == 0){return 1;}
  if (n == 1){return x;}
  if (n == -1){return 1/x;}
  if (n %2 == 0){
    double out = myPow(x, (int) n /2);
    return out * out;
  }
  else {
    double out = myPow(x, (int) n /2);
    return (n < 0)? 1/x * out * out : x * out * out;}
  }
};

int main()
{ 
  Solution sol;
  cout<< sol.myPow(34.00515, -3)<< endl;
  //cout<< sol.myPow(2.1, 3)<< endl;
  //cout<< sol.myPow(2, -2)<< endl;
  return 0;
}
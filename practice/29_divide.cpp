#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <cmath>
/*
https://leetcode.com/problems/rotate-image/
*/
using namespace std;
void print(const vector<vector<int>> matrix){
  for (auto row: matrix){
    for (auto elem: row){
      cout << elem <<", ";
    }
    cout << endl;
  }
}
class Solution {
public:
  int divide(int dividend, int divisor) {
    int count(0);
    bool neg_dividend(false);
    bool neg_divisor(false);
    if (dividend < 0){
      dividend = - dividend;
      neg_dividend = true;
    }
    if (divisor < 0){
      divisor = - divisor;
      neg_divisor = true;
    }
    while (dividend > divisor){
      count++; dividend -= divisor;
    } 
    if ((neg_dividend && !neg_divisor) || (!neg_dividend && neg_divisor) ){
      count = - count;
    }
    return  count;
  }
};

int main()
{ 
  vector<vector<int>> matrix{{1,2,3}, {4,5,6}, {7,8,9}};

  Solution sol;
  cout << sol.divide(7, -3) << endl;
  cout << sol.divide(-7, -3) << endl;
  cout << sol.divide(-7, 3) << endl;
 
  return 0;
}
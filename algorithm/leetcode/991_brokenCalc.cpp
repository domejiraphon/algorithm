#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
  int brokenCalc(int startValue, int target) {
    int count(0);
    helper(count, startValue, target);
    return count;

  }
  void helper(int& count, int startValue, int target){
    if (startValue == target){return;}
    if (target < startValue) {count += (startValue - target); return;}
    else if (target %2 !=0){target++;}
    else {target /= 2;}
    count++;
    helper(count, startValue, target);
  }
};

int main()
{
  Solution sol;
  cout << sol.brokenCalc(2, 3)<<endl;
  cout << sol.brokenCalc(5, 8)<<endl;
  cout << sol.brokenCalc(3, 10)<<endl;
  cout << sol.brokenCalc(10000, 8)<<endl;
  
  return 0;
}
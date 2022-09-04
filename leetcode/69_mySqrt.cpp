#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    long int out;
    for (long int i=1; i < x; i *= 2){
      if (i*i > x || i*i == x) {
        i /=2;
        out = i;
        break;
      }
    }
    for (long int i=out; i < x; i++){
      if (i*i > x) {
        i--;
        out = i;
        break;
      }
      else if (i*i == x){
        out = i;
        break;
      }
    }
    return out;
  }
};

int main()
{
  Solution sol;
  cout << sol.mySqrt(4) << endl;
  cout << sol.mySqrt(8) << endl;
  cout << sol.mySqrt(9) << endl;
  cout << sol.mySqrt(2147395599) << endl;
  return 0;
}
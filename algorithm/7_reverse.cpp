#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    bool neg=false;
    if (x < 0){
      neg = true;
      x = -x;
    }
    string s = to_string(x);
    int num(0);
    for (int i=s.length()-1; i !=-1; i--){
      int cur = stoi(string(1, s[i]));
      num += cur* pow(10, i);
    }
    return neg ? -num : num;
  }
};
int main()
{ 
  
  Solution sol;
  //cout << sol.reverse(123) << endl;
  //cout << sol.reverse(-123) << endl;
  //cout << sol.reverse(120) << endl;
  cout << sol.reverse(1534236469) << endl;
  return 0;
}
#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    int digit(0);
    int num(0);
    int sign(1);
    for (auto ele: s){
      if (ele == ' '){continue;}
      else if (ele == '-'){sign = -1;}
      else if (ele == '+'){sign = 1;}
      else if (isdigit(ele)){
        num +=  pow(10, digit)* ((int) ele -'0');
        digit++;
      }
      else {break;}
    }
    int out(0);
    digit = 0;
    while (num > 0){
      int dig = pow(10, (int) log10(num));
      out += num / dig *pow(10, digit++);
      num = num % dig;
    }
    return out * sign;
  }
};

int main()
{
  Solution* sol;
  cout << sol -> myAtoi("42")<< endl;
  cout << sol -> myAtoi("   -42")<< endl;
  cout << sol -> myAtoi("4193 with words")<< endl;
}

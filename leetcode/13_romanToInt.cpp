#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    map <string, int> symbol;
    symbol["I"] = 1; symbol["V"] = 5;
    symbol["X"] = 10; symbol["L"] = 50;
    symbol["C"] = 100; symbol["D"] = 500;
    symbol["M"] = 1000;
    int out=0;

    for (int i=0; i != s.length(); i++){
      string cur(1, s[i]);
      if (i != s.length() - 1){
        string next(1, s[i+1]);
        if (symbol[cur] < symbol[next]){
          out += - symbol[cur];
        }
        else
          out += symbol[cur];
      }
      else
        out += symbol[cur];
    }
    return out;
  }
};

int main()
{
  Solution sol;
  cout << sol.romanToInt("III") << endl;
  cout << sol.romanToInt("LVIII") << endl;
  cout << sol.romanToInt("MCMXCIV") << endl;
  return 0;
}
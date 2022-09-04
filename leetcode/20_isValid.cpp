#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
  string cur=s;
  if (cur == "")
    return false;
  while (cur !=""){
    string first(1, cur[0]);
    string next(1, cur[1]);
    string last(1, cur[cur.size()-1]);
    if (first == ")" ||first == "]" || first == "}"){
      return false;
    }
    map <string, string> symbol;
    symbol["("] = ")"; symbol[")"] = "(";
    symbol["["] = "]"; symbol["]"] = "[";
    symbol["{"] = "}"; symbol["}"] = "{";
    if (symbol[first] == next){
      cur = cur.substr(2);
    }
    else if (symbol[first] == last){
      cur = cur.substr(1, cur.size() - 2);
    }
    else{
      return false;
    }
  }
  return true;
  }
};

int main()
{
  Solution sol;
  cout << sol.isValid("()") << endl;
  cout << sol.isValid("()[]{}") << endl;
  cout << sol.isValid("(]") << endl;
  cout << sol.isValid("((]") << endl;
  cout << sol.isValid("(([]){})") << endl;
  return 0;
}
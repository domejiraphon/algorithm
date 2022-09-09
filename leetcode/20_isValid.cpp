#include <iostream>
#include <iterator>
#include <map>
#include <stack>
#include <vector>
using namespace std;

class Solution2 {
public:
  bool isValid(string s) {
  map<char, int> iterator;
  iterator['('] = 0; iterator[')'] = 0; 
  iterator['['] = 0; iterator[']'] = 0; 
  iterator['{'] = 0; iterator['}'] = 0; 

  for (auto tmp:s){
    iterator[tmp]++;
    if (iterator[')'] > iterator['('] ||
        iterator[']'] > iterator['['] ||
        iterator['}'] > iterator['{']){
          return false;
        }
  
  }
  return true;
  }
};
class Solution {
public:
  bool isValid(string s) {
    stack<char> S;
    for (auto tmp: s){
      if (tmp == '(' || tmp == '[' || tmp == '{'){
        S.push(tmp);
      }
      else if ((tmp == ')' && !S.empty() && S.top() == '(') ||
              (tmp == ']' && !S.empty() && S.top() == '[') ||
              (tmp == '}' && !S.empty() && S.top() == '{'))
      {
        S.pop();
      }
      else {return false;};
    }
    return (S.empty()) ? true: false;
  }
};
int main()
{
  Solution sol;
  cout << sol.isValid("]") << endl;
  cout << sol.isValid("()[]{}") << endl;
  cout << sol.isValid("(]") << endl;
  cout << sol.isValid("([)]") << endl;
  cout << sol.isValid("(([]){})") << endl;
  return 0;
}
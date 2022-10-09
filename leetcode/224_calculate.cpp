#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    stack<int> S;
    int n = s.size();
    int i(0);
    int ans(0);
    int sign(1);
    while (i < n){
      if (isdigit(s[i])){
        string cur;
        while (isdigit(s[i])){
          cur += s[i]; 
          i++;
        }
        i--;
        ans += sign * stoi(cur);
      }
      else if(s[i] == '+'){
        sign = 1;
      }
      else if(s[i] == '-'){
        sign = -1;
      }
      else if (s[i] == '('){
        S.push(ans);
        S.push(sign);
        ans = 0; sign = 1;
      }  
      else if (s[i] == ')'){
        ans *= S.top();
        S.pop();
        ans += S.top(); 
        S.pop();
      }
      i++;  
    }
    return ans;
  }

};

int main()
{ 
  
  Solution* sol;
  string s;
  s = "1 + 1";
  cout << sol -> calculate(s)<< endl;

  s = " 2-1 + 2 ";
  cout << sol -> calculate(s)<< endl;
  s = "(1+(4+5+2)-3)+(6+8)";
  cout << sol -> calculate(s)<< endl;
  return 0;
}
#include <iostream>
#include <iterator>
#include <map>
#include <stack>
#include <vector>
using namespace std;
void PrintStack(stack<tuple<int, char>> S)
{
    // If stack is empty then return
    if (S.empty())
        return;
     
 
    tuple<int, char> x = S.top();
 
    // Pop the top element of the stack
    S.pop();
 
    // Recursively call the function PrintStack
    PrintStack(S);
 
    // Print the stack element starting
    // from the bottom
    cout << get<0>(x) << ", " <<  get<1>(x) << endl;
 
    // Push the same element onto the stack
    // to preserve the order
    S.push(x);
}

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    stack<tuple<int, char>> S;
    for (int i=0; i != s.size(); i++){
      if (s[i] == '('){
        S.push({i, s[i]});
      }
      else if (s[i] == ')') {
        if (!S.empty() && get<1>(S.top()) == '('){S.pop();}
        else {S.push({i, s[i]});}
      }
    }
    while (!S.empty()){
      tuple<int, char> idx = S.top();
      s.erase(get<0>(idx), 1);
      S.pop();
    }
    return s;
  }
};


int main()
{
  Solution sol;
  cout << sol.minRemoveToMakeValid("lee(t(c)o)de)") << endl;
  cout << sol.minRemoveToMakeValid("a)b(c)d") << endl;
  cout << sol.minRemoveToMakeValid("))((") << endl;
  cout << sol.minRemoveToMakeValid("a))b(c)(d))()") << endl;
  
  return 0;
}
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    unordered_map<string, function<int (int, int) >> map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
    };
    stack<int> S;
    int n=tokens.size();
    for (int i=0; i<n; i++){
      if (map.count(tokens[i])){
        int second = S.top(); S.pop();
        int first = S.top(); S.pop();
        S.push(map[tokens[i]](first, second));
      }
      else {
        S.push(stoi(tokens[i]));
      }
    }
    return S.top();
  }

};


int main()
{ 
  Solution* sol;
  vector<string> tokens;
  tokens = {"2","1","+","3","*"};
  cout << sol -> evalRPN(tokens)<< endl;
  tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  cout << sol -> evalRPN(tokens)<< endl;
  
  return 0;
}
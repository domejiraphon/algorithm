#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <cmath>
using namespace std;
void print(vector<int> cur){
  for (auto it : cur){cout << it<<", ";}
  cout << endl;
}

class Solution {
public:
  bool checkValidString(string str) {
    stack<int> S;
    vector<int> deleteList;

    for (int i=0; i != str.size(); i++){
      if (str[i] == '('){
        S.push(i);
      }
      else if (str[i] == ')' && !S.empty()){
        deleteList.push_back(S.top());
        deleteList.push_back(i);
        S.pop();
      }
    }

    sort(deleteList.begin(), deleteList.end());
    for (int i=0; i !=deleteList.size(); i++){
      str.erase(deleteList[i] - i, 1);}
    
    S = stack<int> {};
    for (int i=0; i != str.size(); i++){
      if (str[i] == '(' || str[i] == ')'){
        S.push(i);
      }
      else if (str[i] == '*' && !S.empty()){
        S.pop();
      }
    }
    
    return (check['*'] >= check['('] + check[')']) ? true : false;
  }
};

int main()
{
  string s = "()";
  
  Solution sol;
  //cout << sol.checkValidString(s)<<endl;

  s = "()(**)";
  //cout << sol.checkValidString(s)<<endl;

  s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
  cout << sol.checkValidString(s)<<endl;

  
  return 0;
}
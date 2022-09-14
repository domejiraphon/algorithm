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
    int count(0);
    int star(0);
    for (auto i=0; i != str.size(); i++){
      if (str[i] == '('){count++;}
      else if (str[i] == ')'){count--;}
      else if (str[i] == '*'){star++;}
     
    }
    
    return (- count < star) ? true : false;
  }
};

int main()
{
  string s = "(*))";
  
  Solution sol;
  cout << sol.checkValidString(s)<<endl;
 
  s = "(*)";
  cout << sol.checkValidString(s)<<endl;

  s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
  cout << sol.checkValidString(s)<<endl;

  
  return 0;
}
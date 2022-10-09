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
    stack<char> S;
    stack<string> prior;
    bool priority(false);
    char ch = '1';
	  cout << stoi(string(1, ch)); exit(0);
    for (auto ele: s){
      if (ele == ' '){continue;}
      else if (ele == '*' || ele == '/'){
        int left(0);
        int digit(0);
        while (!S.empty() && isdigit(S.top())){
          left += pow(10, digit) * S.top();
          S.pop();
          digit++;
        }
        prior.push(to_string(left));
        prior.push(string(1, ele));
        priority = true;
      }
      else {
        if (priority){
          //int right = atoi(string(1, ele));
          cout << endl;
        }
        else {
          priority = true;
          S.push(ele);
        }
      }
    }
  }
};

int main()
{ 
  
  Solution* sol;
  string s;
  s = "3+2*2";
  cout << sol -> calculate(s)<< endl;

  s = " 3/2 ";
  cout << sol -> calculate(s)<< endl;
  s = " 3+5 / 2 ";
  cout << sol -> calculate(s)<< endl;
  return 0;
}
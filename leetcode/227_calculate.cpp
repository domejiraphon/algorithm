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
    int right(0);
    int digitRight(0);
    for (auto ele: s){
      if (ele == ' '){continue;}
      else if (ele == '*' || ele == '/'){
        int left(0);
        int digit(0);
        while (!S.empty() && isdigit(S.top())){
          left += pow(10, digit) * stoi(string(1, S.top()));
          S.pop();
          digit++;
        }
        prior.push(to_string(left));
        prior.push(string(1, ele));
        priority = true;
      }
      else {
        if (priority && isdigit(ele)){
          right += pow(10, digitRight) * stoi(string(1, ele));
          digitRight++;
          
        }
        else if (priority && !isdigit(ele)){
          string mark = prior.top(); prior.pop();
          int left = stoi(prior.top()); prior.pop();
          if (mark == "*"){left *= right;}
          else {left /= right;}
          S.push(to_string(left)); 
          S.push(ele); right = 0; digitRight = 0;
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
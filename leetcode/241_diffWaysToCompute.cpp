#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
void print(vector<int> x){
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
}

class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    int n=expression.size();
    vector<int> ans;
    vector<int> leftAns;
    vector<int> rightAns;
    
    for (auto i=0; i<n; i++){
      if (!isdigit(expression[i])){
        leftAns = diffWaysToCompute(expression.substr(0, i));
        rightAns = diffWaysToCompute(expression.substr(i + 1));
        for (auto left: leftAns){
          for (auto right: rightAns){
            ans.push_back(evaluate(left, right, expression[i]));
          }
        }
      }
    }
    if (ans.size() == 0){
      ans.push_back(stoi(expression));
    }
    
    return ans;
  }
private:
  int evaluate(int x, int y, char oper){
    if (oper == '+'){return x + y;}
    else if (oper == '-'){return x - y;}
    else{return x*y;}
  }
};
int main()
{
  Solution* sol;
  vector<int> out;
  out = sol -> diffWaysToCompute("2-11-1");
  print(out);

  out = sol -> diffWaysToCompute("2*3-4*5");
  print(out);
}

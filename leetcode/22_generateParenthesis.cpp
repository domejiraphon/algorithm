#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector<string> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack(res, "", 0, 0, n);
    //backtrace(res, "", 0, 0, n);
    return res;
  }
private:
  void backtrack(vector<string>& res, string s, 
    int numOpen, int numClose, int n){
      if (numOpen == (n) && numClose == (n)){
        res.push_back(s);
        return;
      }  
      if (numOpen < n){
        backtrack(res, s+"(", numOpen+1, numClose, n);
      }     
      if (numClose < numOpen){
        backtrack(res, s+ ")", numOpen, numClose+1, n);
      }    
    }
  
};
int main()
{
  
  Solution sol;
  vector<string> out;
  out = sol.generateParenthesis(3);
  print(out);
  
  out = sol.generateParenthesis(1);
  print(out);

  return 0;
}
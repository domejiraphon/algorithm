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
private:
  map<char,vector<char>> keyPad;
public:
  Solution(){
      keyPad['2'] = vector<char> {'a', 'b', 'c'};
      keyPad['3'] = vector<char> {'d', 'e', 'f'};
      keyPad['4'] = vector<char> {'g', 'h', 'i'};
      keyPad['5'] = vector<char> {'j', 'k', 'l'};
      keyPad['6'] = vector<char> {'m', 'n', 'o'};
      keyPad['7'] = vector<char> {'p', 'q', 'r', 's'};
      keyPad['8'] = vector<char> {'t', 'u', 'v'};
      keyPad['9'] = vector<char> {'w', 'x', 'y', 'z'};
    }
  vector<string> letterCombinations(string digits) {
    vector<string> res{};
    if (digits.size() == 0) {return res;}
    backtracking(res, "", digits, 0);
    return res;
  }
private:
  void backtracking(vector<string>& res, string tmp, string digits, int iter) {
    if (iter == digits.size()) {res.push_back(tmp); return;}
    for (char elem: keyPad[digits[iter]]){
      backtracking(res, tmp + string(1, elem), digits, iter+1);
    }
  }
};

int main()
{
  
  Solution sol;
  vector<string> out;
 
  out = sol.letterCombinations("23");
  print(out);

  out = sol.letterCombinations("456");
  print(out);

  out = sol.letterCombinations("2");
  print(out);

  return 0;
}
#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
void print(vector<vector<bool>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}
class Solution2 {
public:
  bool isMatch(string s, string p) {
    if (p == ""){return s == "";}
    bool match = (s != "" && (s[0] == p[0] || p[0] == '.'));
    if (p.size() > 1 && p[1] == '*'){
      return isMatch(s, p.substr(2)) || (match && isMatch(s.substr(1), p));
    }
    else {
      return match && isMatch(s.substr(1), p.substr(1));
    }
  }
};

class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size(), m =p.size();
    vector<vector<bool>> res(n + 1, vector<bool> (m + 1, false));
    res[0][0] = true;
    for (int i=0; i<= n; i++){
      for (int j = 1; j <= m; j++){
        bool match; 
        if (p[j - 1] == '*'){
          res[i][j] = res[i][j - 2] || 
              (i && (s[i - 1] == p[j - 2]) || (p[j - 2] == '.') && res[i - 1][j]);
        }
        else {
          res[i][j] = (i && (s[i - 1] == p[j - 1]) || (p[j - 1] == '.') && res[i - 1][j - 1]);
        }
      }
    }
    print(res);
    return res[n][m];
  }
};

int main()
{
  Solution* sol;
  //cout << sol -> isMatch("ab", ".*c")<< endl;
  cout << sol -> isMatch("aa", "a")<< endl;

}

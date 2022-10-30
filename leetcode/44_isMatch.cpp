#include <iostream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    map<pair<string, string>, bool> memo;
    memo[{"", ""}] = true;
    regex(s, p, memo);
    return memo[{s, p}];
  }

private:
  bool regex(string s, string p,
      map<pair<string, string>, bool>& memo) {
    if (memo.find({s, p}) != memo.end()){
      return memo[{s, p}];
    }
   
    bool out;
    if (s!= ""){
      if (p[0] == '*'){
        out = regex(s, p.substr(1), memo) 
            || regex(s.substr(1), p, memo);
      }
      else {
        bool match = (p[0] == s[0]) ? true : (p[0] == '?');
        out = match && regex(s.substr(1), p.substr(1), memo);
      }
    }
    else {
      if (p[0] == '*'){
        out = regex(s, p.substr(1), memo);
      }
      else {out = false;}
    }
    memo[{s, p}] = out;
    return out;
  }

};
 
int main()
{
  Solution* sol;
  cout << sol -> isMatch("bac", "b*")<< endl;
  cout << sol -> isMatch("bacd", "b*acd")<< endl;
  cout << sol -> isMatch("bacdasdd", "b*adsadacd")<< endl;
}

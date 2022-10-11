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


void print(vector<vector<string>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    int n = s.size();
    vector<string> cur;
    unordered_map<string, bool> memo;
    backtrack(s, 0, n, cur, res, memo);
    return res;
  }
private:
  void backtrack(string s, int i, int n, vector<string> cur, 
      vector<vector<string>>& res, unordered_map<string, bool>& memo){
    if (i == n){
      for (int j=0; j < cur.size(); j++){
        if (memo.find(cur[j]) != memo.end()){
          if (memo[cur[j]]){continue;}
          else {return;}
        }
        else if (!isPalindrome(cur[j])){
          memo[cur[j]] = false;
          return;}
        else {memo[cur[j]] = true;}
      }
      res.push_back(cur); return;}
    cur.push_back(string(1, s[i]));
    backtrack(s, i+1, n, cur, res, memo);
    if (i > 0){
      cur.pop_back(); 
      cur[cur.size() - 1] += s[i];
      backtrack(s, i+1, n, cur, res, memo);
      
    }
  }
  bool isPalindrome(string s){
    int low(0), high(s.size() - 1);
    while (low < high){
      if (s[low++] != s[high--]){return false;}
    }
    return true;
  }
};

int main()
{
  Solution* sol;
  vector<vector<string>> out;
  out = sol -> partition("aabba");
  print(out);
}

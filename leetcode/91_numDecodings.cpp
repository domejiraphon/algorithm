#include <iostream>
#include <iterator>
#include <unordered_map>
#include <map>
#include <cmath>
#include <vector>
#include <list>

using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  int numDecodings(string s) {
    vector<int> dp(s.size() + 1, -1);
    int out = count(0, s, dp);
    return out;
  }
private:
  int count(int idx, string s, vector<int>& dp){
    if (dp[idx] != -1){
      return dp[idx];
    }
    if (idx == s.size()){
      dp[idx] = 1;
      return 1;
    }
    if (s[idx] == '0'){
      return 0;
    }
    int out = count(idx + 1, s, dp);
    
    if (idx < s.size() - 1){
      int cur = stoi(s.substr(idx, 2));
      if (cur <= 26){
        out += count(idx +2, s, dp);
      }
    }
    dp[idx] = out;
    return out;
  }
};

int main()
{
  Solution* sol;
  //cout << sol -> numDecodings("12312302")<< endl;
  //cout << sol -> numDecodings("11106")<< endl;
  cout << sol -> numDecodings("12")<< endl;
}

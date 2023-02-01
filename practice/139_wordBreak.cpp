#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void print(vector<bool> memo){
  for (auto ele: memo){
    cout << ele << ", ";
  }
  cout << endl;
}
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> memo(s.size() + 1, false);
    memo[0] = true;
    for (int i=1; i !=s.size()+1; i++){
      for (auto ele: wordDict){
        if (i >= ele.size()){
          string cur = {s.begin() + i - ele.size(), s.begin() + i};
          memo[i] = memo[i - ele.size()] && cur == ele;
          if (memo[i]){break;}
        } 
      }

    }
    return memo[s.size()];
  }
};

int main()
{ 
  
  Solution* sol;
  vector<string> wordDict = {"leet", "code"};
  cout << sol -> wordBreak("leetcode", wordDict)<< endl;
  
  wordDict = vector<string> {"apple","pen"};
  cout << sol -> wordBreak("applepenapple", wordDict)<< endl;

  wordDict = vector<string> {"cats","dog","sand","and","cat"};
  cout << sol -> wordBreak("catsandog", wordDict)<< endl;
  
  return 0;
}
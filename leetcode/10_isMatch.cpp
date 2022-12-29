/*
10. Regular Expression Matching
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/
class Solution {
public:
  bool isMatch(string s, string p) {
    cout << s << ", "<< p<< endl;
    if (p == ""){return s == "";}
    bool first = ((s != "" && s[0] == p[0]) || p[0] == '.');
    
    if (p.size() > 1 && p[1] == '*'){
      return (isMatch(s, p.substr(2))) ||
              first && isMatch(s.substr(1), p);
    }
    else {
      return first && isMatch(s.substr(1), p.substr(1));
    }
  }
};

class Solution {
  string word, pattern;
  int nWord, nPattern;
  vector<vector<int>> dp;
public:
  bool isMatch(string s, string p) {
    word = s; pattern = p;
    nWord = word.size();
    nPattern = pattern.size();
    dp.resize(nWord+1, vector<int> (nPattern+1, -1));
    return helper(0, 0);
  }
private:
  bool helper(int i, int j){
    //if (dp[i][j] != -1){
    //  return dp[i][j] == 1;
    //}
    bool out;
    if (j == nPattern) {out = i == nWord;}
    else {
      bool first = (i < nWord && word[i] == pattern[j]) || (pattern[j] == '.');
      if (j < nPattern - 1 && pattern[j+1] == '*'){
        out = helper(i, j + 2) ||
              (first && helper(i + 1, j));
      }
      else {
        out = first && helper(i + 1, j + 1);
      }
      //dp[i][j] = out == 1;
    }
    return out;
  }
};
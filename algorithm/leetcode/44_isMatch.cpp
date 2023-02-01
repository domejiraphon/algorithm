/*
44. Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/
class Solution2 {
public:
  bool isMatch(string s, string p) {
    if (p == "")
      return s == "";
    if (s!= "" && p[0] != '*'){
      bool first = (s[0] == p[0] || p[0] == '?');
      return first && isMatch(s.substr(1), p.substr(1));
    }
    else {
      if (p[0] == '*'){
        if (s != "")
          return isMatch(s.substr(1), p) || isMatch(s, p.substr(1));
        else 
          return isMatch(s, p.substr(1));
      }
      else
        return false;
    }
  }
};

class Solution {
public:
  bool isMatch(string s, string p) {
    int n=s.size();
    int m=p.size();
    vector<vector<int>> memo(n+1, vector<int> (m+1, -1));
    return check(0, 0, n, m, s, p, memo);
  }
private:
  bool check(int i, int j, int& n, int& m, string& s, string& p, vector<vector<int>>& memo){
    if (j == m){
      return i == n;
    }
    if (memo[i][j] != -1)
      return memo[i][j];
    bool out;
    if (i < n && p[j] != '*'){
      bool first = (s[i] == p[j] || p[j] == '?');
      out = first && check(i + 1, j + 1, n, m, s, p, memo);
    }
    else {
      if (p[j] == '*'){
        if (i < n)
          out = check(i+1, j, n, m, s, p, memo) || check(i, j+1, n, m, s, p, memo);
        else
          out = check(i, j+1, n, m, s, p, memo);
      }
      else
        out = false;
    }
    return memo[i][j] = out;
  }
};
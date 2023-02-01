class Solution {
public:
  bool isMatch(string s, string p) {
    string S = s, P = p;
    int n=S.size();
    int m=P.size();
    vector<vector<int>> memo (n+1, vector<int> (m+1, -1));
    return check(S, P, 0, 0, n, m, memo);
  }
private:
  bool check(string& s, string& p, int i, int j, int& n, int& m, 
    vector<vector<int>>& memo){
    if (j == m)
      return i == n;
    if (memo[i][j] != -1)
      return memo[i][j] == 1;
    bool first = (i < n) && (s[i] == p[j] || p[j] == '.');
    
    bool out;
    if (j < m - 1 && p[j+1] == '*'){
      out = check(s, p, i, j + 2, n, m, memo) || 
            (first && check(s, p, i + 1, j, n, m, memo));
    }
    else
      out = first && check(s, p, i + 1, j + 1, n, m, memo);
    memo[i][j] = out ? 1: 0;

    return out;
  }
};
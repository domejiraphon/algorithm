/*
131. Palindrome Partitioning
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.


*/
class Solution {
  int memo[17][17];
  vector<vector<string>> res;
public:
  vector<vector<string>> partition(string s) {
    memset(memo, -1, sizeof(memo));
    vector<string> cur;
    helper(s, 0, cur);
    return res;
  }
private:
  bool check(string& s, int start, int end){
    if (memo[start][end] != -1){
      return memo[start][end] == 1;
    }
    bool out=true;
    int i = start, j = end;
    while (start < end && out){
      if (s[start++] != s[end--])
        out = false;
    }
    memo[i][j] = (out) ? 1: 0;
    return out;
  }
  void helper(string& s, int start, vector<string>& cur){
    if (start == s.size()){
      res.push_back(cur);
      return;
    }

    for (int i=start; i<s.size(); i++){
      if (check(s, start, i)){
        cur.push_back(s.substr(start, i - start + 1));
        helper(s, i + 1, cur);
        cur.pop_back();
      }
    }
  }
};
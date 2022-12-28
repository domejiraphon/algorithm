/* 5. Longest Palindromic Substring
Given a string s, return the longest 
palindromic substring in s.
*/
class Solution {
private:
  map<pair<int, int>, bool> dp;
  string S;
public:
  string longestPalindrome(string s) {
    S = s;
    int n=s.size();
    string out="";
    for (int i=0; i< n; i++){
      for (int j=i+1; j<= n; j++){
        string cur = S.substr(i, j - i + 1);
       
        if (check(i, j) && out.size() < cur.size()){
          out = cur;
        }
      }
    }
    return out;
  }
private:
  bool check(int i, int j){
    if (i < j){
      if (dp.count({i, j})){
        return dp[{i, j}];
      }
      bool out;
      
      if (S[i] == S[j]){
        out = check(i+1, j-1);
      }
      else {
        out = false;
      }
      return dp[{i, j}] = out;
    }
    return true;
  }
};
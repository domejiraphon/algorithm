/* 5. Longest Palindromic Substring
Given a string s, return the longest 
palindromic substring in s.
*/
class Solution {
public:
  string longestPalindrome(string s) {
    int length=0;
    int n=s.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    
    string out;
    for (int i=0; i<n; i++){
      for (int j=i; j<n; j++){
        if (checkPalindrome(s, i, j, memo)){
          if (length < j - i + 1){
            length = j - i +1;
            out = s.substr(i, j - i + 1);
          }
        }
      }
    }
    return out;
  }
private:
  bool checkPalindrome(string& s, int st, int end, vector<vector<int>>& memo){
    if (st > end)
      return true;
    if (memo[st][end] != -1)
      return memo[st][end] == 1;
    bool out=false;
    if (s[st] == s[end])
      out = checkPalindrome(s, st + 1, end -1, memo);
    memo[st][end] = out ? 1 : 0;
    return out;
  }
};
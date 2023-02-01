/*
516. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
*/
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    string S=s;
    int n=S.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return maxLength(S, 0, S.size() - 1, memo);
  }
private:
  int maxLength(string& s, int left, int right, vector<vector<int>>& memo){
    if (left > right)
      return 0;
    if (left == right)
      return 1;
    if (memo[left][right] != -1)
      return memo[left][right];
    int res;
    if (s[left] == s[right])
      res = 2 + maxLength(s, left+1, right-1, memo);
    else 
      res = max(maxLength(s, left + 1, right, memo), maxLength(s, left, right - 1, memo));
    return memo[left][right] = res;
  }
};

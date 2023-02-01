/*
1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int n=text1.size();
    int m=text2.size();
    vector<vector<int>> memo(n, vector<int>(m, -1));
    return common(text1, 0, text2, 0, n, m, memo);
  }
private:
  int common(string& text1, int i, string& text2, int j, int& n, int& m, vector<vector<int>>& memo){
    if (i == n)
      return 0;
    if (i >= n || j >= m)
      return 0;
    if (memo[i][j] != -1)
      return memo[i][j];
    int out=0;
    if (text1[i] == text2[j])
      out = 1 + common(text1, i+1, text2, j+1, n, m, memo);
    else
      out = max(common(text1, i+1, text2, j, n, m, memo),
                common(text1, i, text2, j+1, n, m, memo));
    return memo[i][j] = out;
  }
};
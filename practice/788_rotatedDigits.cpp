/*
788. Rotated Digits
An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].
*/
class Solution {
  unordered_map<int, int> S;
  int memo[10001][2][2];
public:
  int rotatedDigits(int n) {
    S[2] = 5; S[5] = 2; S[6] = 9; S[9] = 6;
    S[0] = 0; S[1] = 1; S[8] = 8;
    string s = to_string(n);
    memset(memo, -1, sizeof(memo));
    return dp(0, true, false, s);
  }
private:
  int dp(int cur, bool bound, bool hasChanged, string& s){
    if (cur == s.size())
      return hasChanged;
    if (memo[cur][bound][hasChanged] != -1)
      return memo[cur][bound][hasChanged];
    int ans=0;
    int maxDigit = (bound) ? s[cur] - '0' : 9;
    for (int i=0; i<= maxDigit; i++){
      if (S.count(i))
        ans += dp(cur + 1, bound && (i == maxDigit), 
                  hasChanged || S[i] != i, s);
    }
    return memo[cur][bound][hasChanged] = ans;
  }
};

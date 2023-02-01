class Solution {
public:
  int uniqueLetterString(string s) {
    int dp[26][2];
    memset(dp, -1, sizeof(dp));
    int n=s.size();
    int res(0);
    for (int i=0; i<n; i++){
      int idx = s[i] - 'A';
      res += (dp[idx][1] - dp[idx][0]) * (i - dp[idx][1]);
      dp[idx][0] = dp[idx][1];
      dp[idx][1] = i;
    }
    for (int idx=0; idx<26; idx++){
      res += (dp[idx][1] - dp[idx][0]) * (n - dp[idx][1]);
    }
    return res;
  }
};
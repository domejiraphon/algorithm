/* 91. Decode Ways
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using 
the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
*/
class Solution {
public:
  int numDecodings(string s) {
    int memo[s.size()];
    memset(memo, -1, sizeof(memo));
    return dp(s, 0, memo);
  }
private:
  int dp(string& s, int idx, int *memo){
    if (idx == s.size())
      return 1;
    if (memo[idx] != -1)
      return memo[idx];
    int ans = 0;
    if (s[idx] != '0')
      ans += dp(s, idx+1, memo);
    if (idx < s.size() - 1){
      if ((s[idx] == '1') ||
          (s[idx] == '2' && s[idx+1] >= '0' && s[idx+1] <='6'))
        ans += dp(s, idx + 2, memo);
    }
    
    return memo[idx] = ans;
  }
};
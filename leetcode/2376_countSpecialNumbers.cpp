class Solution {
private:
  int dp[10][2][1024];
  string s;
public:
  int countSpecialNumbers(int n) {
    s = to_string(n);
    int out;
    memset(dp, -1, sizeof(dp));
    out = count(0, 1, 0);
    return out;
  }
private:
  int count(int idx, int tight, int mask){
    if (idx == s.size()){return mask != 0;}
    if (dp[idx][tight][mask] != -1){
      return dp[idx][tight][mask];
    }
    int ans(0);
    int limit = (tight == 1) ? (s[idx] - '0') : 9;
    for (int i=0; i<= limit; i++){
      if (mask & (1 << i)){continue;}
      
      int newMask = (mask == 0 && i == 0) ? mask : mask | (1 << i);
     
      int newTight = tight;
      if (tight == 1){
        newTight = (i == (s[idx] - '0')) ? 1 : 0;
      }
      ans += count(idx + 1, newTight, newMask);
    }
    
    return dp[idx][tight][mask] = ans;
  }
};

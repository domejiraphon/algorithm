class Solution {
private:
  string S;
  int n;
  vector<vector<int>> dp;
public:
  int minFlipsMonoIncr(string s) {
    S = s;
    n = S.size();
    dp.resize(n, vector<int> (2, -1));
    return flip(0, false);
  }
private:
  int flip(int idx, bool tight){
    if (idx == n){return 0;}
    if (dp[idx][tight] != -1){return dp[idx][tight];}
    int count;
    if (tight){
      count = (S[idx] == '0') ? flip(idx + 1, tight) + 1: flip(idx + 1, tight);
    }
    else {
      if (S[idx] == '0'){
        count = min(flip(idx + 1, true) + 1, 
                    flip(idx + 1, tight));
      }
      else {
        count = min(flip(idx + 1, true),
                    flip(idx + 1, tight) + 1);
      }
    }
    return dp[idx][tight] = count;
  }
};

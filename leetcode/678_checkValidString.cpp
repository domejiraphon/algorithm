class Solution {
private:
  string S;
  int n;
  int dp[101][101];
  
public:
  bool checkValidString(string s) {
    S=s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    return check(0, 0);
  }
private:
  bool check(int idx, int count){
    if (idx == n){return count == 0;}
    if (count < 0){return false;}
    if (dp[idx][count] != -1){return dp[idx][count];}
    bool out;
    if (S[idx] == '('){
      out = check(idx + 1, count + 1);
    }
    else if (S[idx] == ')'){
      out = check(idx + 1, count - 1);
    }
    else {
      out = check(idx + 1, count + 1) ||
            check(idx + 1, count - 1) ||
            check(idx + 1, count);
    }
    
    return dp[idx][count] = out;
    
  }
};
/*
357. Count Numbers with Unique Digits
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
*/
class Solution {
public:
  int minSessions(vector<int>& tasks, int sessionTime) {
    int n=tasks.size();
    vector<vector<int>> memo (1<<n, vector<int> (sessionTime+1, -1));
    return dp(tasks, 0, 0, sessionTime, n, sessionTime, memo);
  }
private:
  int dp(vector<int>& tasks, int i, int mask, int left, int& n, int& sessionTime, vector<vector<int>>& memo ){
    if (i == n)
      return 1;
    if (memo[mask][left] != -1)
      return memo[mask][left];
    int out=n;
    for (auto it=0; it < n; it++){
      if (mask & (1 << it))
        continue;
      int newMask = mask | (1 << it);
      if (left >= tasks[it])
        out = min(out, dp(tasks, i+1, newMask, left - tasks[it], n, sessionTime, memo));
      else 
        out = min(out, 1 + dp(tasks, i+1, newMask, sessionTime - tasks[it], n, sessionTime, memo));
      
    }
    return memo[mask][left] = out;
  }
};

class Solution {
  int m;
  int memo[9][1024];
public:
  int countNumbersWithUniqueDigits(int n) {
    m = n;
    memset(memo, -1, sizeof(memo));
    return count(0, 0);
  }
private:
  int count(int i, int mask){
    if (i == m)
      return 1;
    if (memo[i][mask] != -1)
      return memo[i][mask];
    int out=0;
    for (int idx=0; idx<=9; idx++){
      if (mask & (1 << idx)){continue;}
      int cur = (mask == 0 && idx==0) ? mask : mask | (1 << idx);
      out += count(i + 1, cur);
    }
    return memo[i][mask] = out;
  }
};

class Solution {
public:
  int minSessions(vector<int>& tasks, int sessionTime) {
    int n=tasks.size();
    
    return dp(tasks, 0, sessionTime, n, sessionTime);
  }
private:
  int dp(vector<int>& tasks, int i, int left, int& n, int& sessionTime){
    if (i == n)
      return 1;
    //if (memo[i][left] != -1)
    //  return memo[i][left];
    int out=n;
    for (auto it=i; it < n; it++){
      swap(tasks[it], tasks[i]);
      if (left >= tasks[i])
        out = min(out, dp(tasks, i+1, left - tasks[i], n, sessionTime));
      else 
        out = min(out, 1 + dp(tasks, i+1, sessionTime - tasks[i], n, sessionTime));
      swap(tasks[it], tasks[i]);
    }
    return out;
  }
};

class Solution {
public:
  long long maximumBooks(vector<int>& books) {
    stack<int> monotonic;
    int n=books.size();
    long long dp[n+1];
    long long out(0);
    for (int i=0; i< n; i++){
      while (!monotonic.empty() && books[monotonic.top()] > books[i] - (i - monotonic.top())){
        monotonic.pop();
      }
      
      dp[i] = (monotonic.empty()) ? 0 : dp[monotonic.top()];
      dp[i] += getSum(books[i]) - getSum(books[i] -i + ((monotonic.empty()) ? -1 : monotonic.top()));
      monotonic.push(i);
      out = max(out, dp[i]);
    }
    return out;
  }
private:
  long long getSum(int i){
    if (i < 0)
		  return 0;

    long long n = i;
    return n * (n + 1) /2;
  }
};

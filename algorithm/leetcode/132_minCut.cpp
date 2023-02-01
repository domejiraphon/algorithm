class Solution {
private:
  string S;
  int n;
  int num = INT_MAX;
  vector<int> memo;
  vector<vector<optional<bool>>> memoPalindrome;
public:
  int minCut(string s) {
    S = s;
    n = s.size();
    memo.resize(n, -1);
    memoPalindrome.resize(s.length(), vector<optional<bool>>(s.length(), nullopt));
    return backtrack(0, INT_MAX);
  }
private:
  int backtrack(int start, int minimum){
    if (start == n || isPalindrome(start, n-1)){
      return 0;}
    if (memo[start] != -1){return memo[start];}
  
    for (int i=start; i<n; i++){
      if (isPalindrome(start, i)){
        minimum = min(minimum, 1 + backtrack(i + 1, minimum));
      }
    }
    return memo[start] = minimum;
  }
  bool isPalindrome(int start, int end) {
    if (start >= end) return true;
    // check for results in memoPalindrome
    if (memoPalindrome[start][end] != nullopt)
        return (memoPalindrome[start][end] == true);
    memoPalindrome[start][end] =
        (S[start] == S[end]) && isPalindrome(start + 1, end - 1);
    return (memoPalindrome[start][end] == true);
  }
};

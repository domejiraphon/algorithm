/*
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
*/
class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    int n=expression.size();
    vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(n+1, vector<int>{}));
    vector<int> res = helper(expression, 0, n, memo);
    return res;
  }
private:
  int getNumber(string& expression, int st, int end){
    int cur =0;
    for (int i=st; i<end; i++)
      cur = 10 * cur + (expression[i] - '0');
    return cur;
  }
  vector<int> helper(string& expression, int st, int end, vector<vector<vector<int>>>& memo) {
    vector<int> res;
    vector<int> left, right;
    if (memo[st][end].size() > 0)
      return memo[st][end];
    for (int i=st; i<end; i++){
      if (expression[i] == '+' ||
          expression[i] == '-' ||
          expression[i] == '*')
        left = helper(expression, st, i, memo);
        right = helper(expression, i+1, end, memo);
      
        int n = left.size();
        int m=right.size();
        
        for (int j=0; j<n; j++){
          for (int k=0; k<m; k++){
            if (expression[i] == '+')
              res.push_back(left[j] + right[k]);
            else if (expression[i] == '-')
              res.push_back(left[j] - right[k]);
            else if (expression[i] =='*')
              res.push_back(left[j] * right[k]);
          }
        }
    }
    if (res.size() == 0)
      res.push_back(getNumber(expression, st, end));
    return memo[st][end] = res;
  }
};
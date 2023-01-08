/*
772. Basic Calculator III
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/
class Solution {
public:
  int calculate(string s) {
    int i=0;
    return parseExpr(s, i);
  }

private:
  long getNumber(string& s, int& i){
    long cur=0;
    while (i<s.size() && isdigit(s[i])){
      cur = 10 *cur + (s[i++] - '0');
    }
    return cur;
  }
  int parseExpr(string& s, int& i){
    vector<int> nums;
    char op = '+';
    int n=s.size();
    while (i<n&& op != ')'){
      if (s[i] == ' ') continue;
      long num = (s[i] == '(') ? parseExpr(s, ++i) : getNumber(s, i);
      
      if (op == '+')
        nums.push_back(num);
      else if (op == '-')
        nums.push_back(-num);
      else if (op == '*')
        nums.back() *= num;
      else if (op == '/')
        nums.back() /= num;
      if (i < n)
        op = s[i];
      i++;
    }
    return accumulate(nums.begin(), nums.end(), 0);
  }
};

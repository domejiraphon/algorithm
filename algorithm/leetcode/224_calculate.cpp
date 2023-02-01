
/*
224. Basic Calculator
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/
class Solution {
public:
  int calculate(string s) {
    int n=s.size();
    int i=0;
    int sign=1;
    int ans=0;
    stack<int> stk;
    while (i <n){
      if (s[i] == ' '){
        i++; continue;
      }
      else if (s[i] == '+')
        sign = 1;
      else if (s[i] == '-')
        sign = -1;
      else if (s[i] == '('){
        stk.push(ans);
        stk.push(sign);
        ans = 0; sign = 1;
      }
      else if (s[i] == ')'){
        ans *= stk.top();
        stk.pop();
        ans += stk.top();
        stk.pop();
      }
      else if (isdigit(s[i])){
        int num = getNumber(s, i);
        ans += sign * num;
        sign = 1;
      }
      i++;
    }
    
    return ans;
  }
private:
  int getNumber(string& s, int& i){
    int cur=0;
    while (isdigit(s[i])){
      cur = 10 * cur + (s[i++] - '0');
    }
    i--;
    return cur;
  }
};
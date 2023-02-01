/*
227. Basic Calculator II
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/
class Solution {
  int n;
public:
  int calculate(string s) {
    n=s.size();
    stack<int> stk;
    int i=0;
    int sign=1;
    while (i < n){
      if (s[i]== ' '){i++; continue;}
      if (isdigit(s[i])){
        int cur = sign * getNextNumber(s, i);
        stk.push(cur);
        sign = 1;
      }
      else if (s[i] == '+')
        sign = 1;
      else if (s[i] == '-')
        sign = -1;
      else if (s[i] == '*' || s[i] == '/'){
        char mul = s[i];
        int prev = stk.top();
        stk.pop();
        int next = sign * getNextNumber(s, ++i);
        int result = (mul == '*') ? prev * next : prev / next;
        cout << result << endl;
        stk.push(result);
      }
      i++;
    }
    int result=0;
    while (!stk.empty()){
      result += stk.top();
      stk.pop();
    }
    return result;
  }
private:
  int getNextNumber(string& s, int& i){
    int cur=0;
    while (i<n && s[i] == ' ')
      i++;
    
    while (i<n && isdigit(s[i])){
      cur = 10 * cur + (s[i] - '0');
      i++;
    }
    i--;
    return cur;
  }
};
/* 32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.
*/
class Solution {
public:
  int longestValidParentheses(string s) {
    int lFreq(0), rFreq(0);
    int res(0);
    for (auto ch: s){
      if (ch == '('){lFreq++;}
      else if (ch == ')'){rFreq++;}
      if (lFreq == rFreq){
        res = max(res, 2*lFreq);
      }
      else if (rFreq > lFreq){
        rFreq = 0; lFreq = 0;
      }
    }
    lFreq = 0; rFreq = 0;
    int n=s.size();
    for (int i=n-1; i>=0; i--){
      if (s[i] == '('){lFreq++;}
      else if (s[i] == ')'){rFreq++;}
      if (lFreq == rFreq){
        res = max(res, 2*lFreq);
      }
      else if (rFreq < lFreq){
        rFreq = 0; lFreq = 0;
      }
    }
    return res;
  }
};

class Solution {
public:
  int longestValidParentheses(string s){
    stack<int> stk;
    int length=0;
    int n=s.size();
    stk.push(-1);
    for (int i=0; i<n; i++){
      if (s[i] == '(') stk.push(i);
      else {
        stk.pop();
        if (stk.empty()){
          stk.push(i);
        }
        else {
          length = max(length, i - stk.top());
        }
      }
    }
    return length;
  }
};
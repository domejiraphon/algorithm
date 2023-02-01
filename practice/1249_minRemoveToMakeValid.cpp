/* 1249. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
*/
class Solution {
public:
  string minRemoveToMakeValid(string s) {
    stack<int> stk;
    int n=s.size();
    for (int i=0; i<n; i++){
      if (s[i] == '(')
        stk.push(i);
      else if (s[i] == ')'){
        if (!stk.empty() && s[stk.top()] == '(')
          stk.pop();
        else 
          stk.push(i);
      }
    }
    
    while (!stk.empty()){
      s.erase(stk.top(), 1);
      stk.pop();
    }
    return s;
  }
};
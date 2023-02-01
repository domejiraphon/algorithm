/*
402. Remove K Digits
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
*/
class Solution {
public:
  string removeKdigits(string num, int k) {
    stack<char> stk;
    int n=num.size();
    
    for (int i=0; i<n; i++){
      while (!stk.empty() && k > 0 && stk.top() > num[i]){
        stk.pop(); k--;
      }
      stk.push(num[i]);
    }
    for (int i=0; i<k; i++)
      stk.pop();
    num="";
    
    while (!stk.empty()){
      num = stk.top() + num; stk.pop();
    }
   
    if (num == "")
      return "0";
    else if (num[0] == '0'){
      int i=0, n=num.size();
      while (i < n && num[i++] == '0');
      return num.substr(i-1);
    }
    return num;
  }
};

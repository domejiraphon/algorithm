/*
43. Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    vector<vector<int>> res;
    int n=num2.size();
    for (int i=0; i<n; i++)
      res.push_back(multiplyOneDigit(num1, num2[i] - '0', i));
    return sum(res);
  }
private:
  vector<int> multiplyOneDigit(string& first, int second, int lead){
    vector<int> res(lead, 0);
    int carry=0;
    for (auto ch: first){
      int cur = (ch - '0') * (second);
      cur += carry;
      carry = cur / 10;
      
      res.push_back(cur % 10);
    }
    if (carry)
      res.push_back(carry);
    return res;
  }
  string sum(vector<vector<int>>& out){
    vector<int> answer = out.back();
    vector<int> temp;
    out.pop_back();

    
    for (auto cur: out){
      temp.clear();
      int carry=0;
      for (int i=0; i<answer.size() || i<cur.size(); i++){
        int first = (i < answer.size()) ? answer[i] : 0;
        int sec = (i < cur.size()) ? cur[i] : 0;
        int sum = carry + first + sec;
        carry = sum / 10;
        temp.push_back(sum % 10);
      }
      if (carry)
        temp.push_back(carry);
      answer = temp;
    }
    string ans="";
    while (answer.size() > 0){
      ans += answer.back() +'0';
      answer.pop_back();
    }
    return ans;
  }
};
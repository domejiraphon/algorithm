/*
282. Expression Add Operators
Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.
*/
class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    string exp;
    int n=num.size();
    helper(num, 0, 0, 0, target, "", res, n);
    return res;
  }
private:
  void helper(string& num, int pos, long prev, long mul, int target, string exp, vector<string>& res, int& n){
    if (pos == n){
      if (prev == target)
        res.push_back(exp);
      return;
    }
    for (int i=pos; i<n; i++){
      
      string cur = num.substr(pos, i-pos+1);
      if (cur[0] == '0' && cur.size() > 1)
        continue;
      long curVal = stol(cur);
      
      if (pos == 0)
        helper(num, i+1, prev + curVal, curVal, target, cur, res, n);
      else{
        helper(num, i+1, prev + curVal, curVal, target, exp + "+"+ cur, res, n);
        helper(num, i+1, prev - curVal, - curVal, target, exp + "-"+ cur, res, n);
        helper(num, i+1, prev - mul + mul * curVal, mul * curVal, target, exp + "*"+ cur, res, n);
      }
    }
  }
};

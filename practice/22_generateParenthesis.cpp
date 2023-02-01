/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
class Solution {
private:
  vector<string> out;
  int n;  
public:
  vector<string> generateParenthesis(int nums) {
    n = nums;
    string s="";
    backtrack(s, 0, 0);
    return out;
  }
private:
  void backtrack(string s, int left, int right){
    if (left == n && right == n){out.push_back(s); return;}
    if (left < n){
      backtrack(s + "(", left + 1, right);
    }
    if (left > right && right < n){
      backtrack(s + ")", left, right + 1);
    }
  }
};
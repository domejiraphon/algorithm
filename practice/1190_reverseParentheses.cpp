/*
1190. Reverse Substrings Between Each Pair of Parentheses
You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.
*/
class Solution {
public:
  string reverseParentheses(string s) {
    int i=0;
    int n=s.size();
    vector<char> out = helper(s, i, n);
    string res;
    for (int i=0; i<out.size(); i++)
      res.push_back(out[i]);
    
    return res;
  }
private:
  vector<char> helper(string& s, int& i, int& n){
    
    vector<char> stk;
    for (; i<n; i++){
      if (s[i] == '('){
        i++;
        vector<char> out = helper(s, i, n);
        int left=0, right = out.size() - 1;
        while (left < right)
          swap(out[left++], out[right--]);
        stk.insert(stk.end(), out.begin(), out.end());
      }
      else if (s[i] == ')')
        break;
      else 
        stk.push_back(s[i]);
    }
    
    return stk;
  }
};

/*
93. Restore IP Addresses
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
*/
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    string cur = string(1, s[0]);
    vector<string> res;
    backtracking(s, 1, 1, s[0] - '0', cur, res);
    return res;
  }
private:
  void backtracking(string& s, int i, int num, int prevNum, string& cur, vector<string>& res){
    if (i == s.size()){
      if (num == 4)
        res.push_back(cur);
      return;
    }
    if (num > 4)
      return;
    int newNum = 10 * prevNum + (s[i] - '0');
    if (prevNum != 0 && newNum < 256){
      cur += string(1, s[i]);
      backtracking(s, i+1, num, newNum, cur, res);
      cur.pop_back();
    }
    cur += string(1, '.') + string(1, s[i]);
    backtracking(s, i+1, num+1, s[i] - '0', cur, res);
    cur.pop_back();
    cur.pop_back();
  }
};

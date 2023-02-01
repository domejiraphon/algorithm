/*
1221. Split a String in Balanced Strings
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number of substrings such that:

Each substring is balanced.
Return the maximum number of balanced strings you can obtain.
*/
class Solution {
public:
  int balancedStringSplit(string s) {
    vector<int> count(2, 0);
    
    int n=s.size();
    int res=0;
    int right=0;
    while (right < n){
      count.resize(2, 0);
      inc(count, s, right);
      while (right < n && count[0] != count[1]){
        inc(count, s, right);
      }
      //cout << right << endl;
      res++;
      //right++;
    }
    return res;
  }
private:
  void inc(vector<int>& count, string& s, int& right){
    if (s[right++] == 'L')
      count[0]++;
    else
      count[1]++;
  }
};

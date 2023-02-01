/*
161. One Edit Distance
Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.

*/
class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    int n=s.size();
    int m=t.size();
    if (n > m)
      return isOneEditDistance(t, s);
    if (abs(n - m) > 1)
      return false;
    else if (abs(n - m) == 1)
      return del(s, t);
    return replace(s, t);
  }
private:
  bool del(string& s, string& t){
    int n=s.size();
    
    int i=0;
    for (; i<n; i++){
      if (s[i] != t[i])
        return s.substr(i) == t.substr(i+1);
    }
    return true;
  }
  bool replace(string& s, string& t){
    int n=s.size();
   
    int diff=0;
    int i=0;
    while (i<n){
      diff += (s[i] != t[i++]);
      if (diff > 1)
        return false;
    }
    return (diff == 1);
  }
};

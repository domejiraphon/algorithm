/*
1071. Greatest Common Divisor of Strings
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
*/
class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str2.size() > str1.size())
      return gcdOfStrings(str2, str1);
    int n=str1.size();
    int m=str2.size();
    string out="";
    for (int i=1; i<=m; i++){
      string t = str2.substr(0, i);
      bool found=true;
      for (int j=0; j<n && found; j += i){
        string s = str1.substr(j, i);
        if (s != t)
          found = false;
      }
      if (found && t.size() > out.size())
        out = t;
    }
    return out;
  }
};

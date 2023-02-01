class Solution {
public:
  bool isNumber(string s) {
    int n=s.size();
    bool seenDigit = false;
    bool seenExpo = false;
    bool seenDot = false;
    for (int i=0; i<n; i++){
      if (s[i] >= '0' && s[i] <= '9')
        seenDigit = true;
      else if (s[i] == '+' || s[i] == '-'){
        if (i > 0 && s[i - 1] != 'E' && s[i - 1] != 'e')
          return false;
      }
      else if (s[i] == 'e' || s[i] == 'E') {
        if (seenExpo || !seenDigit)
          return false;
        seenExpo = true; seenDigit = false;
      }
      else if (s[i] == '.'){
        if (seenDot || seenExpo)
          return false;
        seenDot = true;
      }
      else 
        return false;

    }
    return seenDigit;
  }
};
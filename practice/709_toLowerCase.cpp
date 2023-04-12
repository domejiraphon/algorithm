/* 709. To Lower Case
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
 */

class Solution {
public:
  string toLowerCase(string s) {
    int n = s.size();
    for (int i=0; i<n; i++){
      if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] = s[i] - 'A' + 'a';
    }
    return s;
  }
};

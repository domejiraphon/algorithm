/* 680. Valid Palindrome II
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/
class Solution {
public:
  bool validPalindrome(string s, bool first=true) {
    int n=s.size();
    int left=0;
    int right = n - 1;
    
    while (left <= right){
      if (s[left] == s[right]){
        left++; right--; continue;
      }
      else {
        if (first){
          string tmp=s;
          string l = s.erase(left, 1);
          string r = tmp.erase(right, 1);
          
          return validPalindrome(l, false) || validPalindrome(r, false);
        }
        else
          return false;
      }
    }
    return true;
  }
};
/*
844. Backspace String Compare
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
*/
class Solution {
public:
  bool backspaceCompare(string s, string t) {
    getString(s);
    getString(t);
    return s == t;
  }
private:
  void getString(string& s){
    for (int i=0; i<s.size(); i++){
      if (s[i] == '#'){
        if (i != 0){
          s.erase(i - 1, 2);
          i -=2;
        }
        else{
          s.erase(i, 1);
          i -=1;
        }
      }
        
    }
  }
};
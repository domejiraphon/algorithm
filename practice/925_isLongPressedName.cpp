/*
925. Long Pressed Name
Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 
*/
class Solution {
  int memo[1001][1001];
public:
  bool isLongPressedName(string name, string typed) {
    memset(memo, -1, sizeof(memo));
    return dp(name, typed, 0, 0);
  }
private:
  bool dp(string& name, string& typed, int i, int j){
    if (i == name.size() && j == typed.size())
      return true;
    if (i == name.size() || j == typed.size())
      return false;
    if (memo[i][j] != -1)
      return memo[i][j];
    bool out=false;
    if (name[i] == typed[j])
      out = dp(name, typed, i+1, j+1) ||
            dp(name, typed, i, j+1);
    return memo[i][j] = out;
  }
};

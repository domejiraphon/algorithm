/*
2193. Minimum Number of Moves to Make Palindrome

You are given a string s consisting only of lowercase English letters.

In one move, you can select any two adjacent characters of s and swap them.

Return the minimum number of moves needed to make s a palindrome.

Note that the input will be generated such that s can always be converted to a palindrome.
*/
class Solution {
public:
  int minMovesToMakePalindrome(string s) {
    int res=0;
    while (s.size() > 0){
      int n=s.size();
      int i;
      for (i=0; i<n; i++){
        if (s[i] == s.back())
          break;
      }
      if (i == n - 1)
        res += n/2;
      else
        res += i, s.erase(i, 1);
      s.pop_back();
    }
    return res;
  }
};

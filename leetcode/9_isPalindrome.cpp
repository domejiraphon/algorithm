/*
9. Palindrome Number
Given an integer x, return true if x is a 
palindrome
, and false otherwise.
*/
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    string temp = to_string(x);
    int left=0, right = temp.size() - 1;
    while (left < right){
      if (temp[left++] != temp[right--])
        return false;
    }
    return true;
  }
};
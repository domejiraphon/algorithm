/*
415. Add Strings
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
*/
class Solution {
public:
  string addStrings(string num1, string num2) {
    int n=num1.size(), m=num2.size();
    int left=n-1, right=m-1;
    string out="";
    int carry=0;
    int cur;
    while (left >= 0 || right >= 0 || carry != 0){
      if (left >= 0 && right >= 0)
        cur = (num1[left--] - '0') + (num2[right--] - '0');
      else 
        if (left >= 0)
          cur = (num1[left--] - '0');
        else if (right >= 0)
          cur = (num2[right--] - '0');
        else 
          cur = 0;
      cur += carry;
      carry = cur / 10;
      cur %= 10;
      out = string(1, cur + '0') + out;
    }
    return out;
  }
};
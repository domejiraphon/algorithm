/*
258. Add Digits
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/
class Solution {
public:
  int addDigits(int num) {
    int out = num;
    while (out / 10 > 0)
      out = process(out);
    
    return out;
  }
private:
  int process(int num){
    int cur=0;
    while (num > 0){
      cur += num % 10;
      num /= 10;
    }
    return cur;
  }
};

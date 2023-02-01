/*
13. Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/
class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> sym;
    sym['I'] = 1; sym['V'] = 5; sym['X'] = 10; sym['L'] = 50; sym['C'] = 100;
    sym['D'] = 500; sym['M'] = 1000; 
    int right =0;
    int n=s.size();
    int out=0;
    while (right < n){
      if (right < n - 1 && sym[s[right]] < sym[s[right+1]])
        out += sym[s[right + 1]] - sym[s[right++]];
      else 
        out += sym[s[right]];
      right++;
    }
    return out;
  }
};
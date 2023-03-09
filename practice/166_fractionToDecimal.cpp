/*
166. Fraction to Recurring Decimal
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
*/
class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
      return "0";
    string out="";
    if (numerator < 0 ^ denominator < 0)
      out += "-";
    long num = (long)abs(numerator);
    long den = (long) abs(denominator);
    out += to_string((int) num / den);
    long remainder = num % den;
    
    if (remainder == 0)
      return out;
    out += ".";
    unordered_map<long, int> pos;
    
    while (remainder !=0){
      if (pos.count(remainder)){
        out.insert(pos[remainder], "(");
        out += ")";
        break;
      }
        
      pos[remainder] = out.size();
      remainder *= 10;
      out += remainder / den +'0';
      remainder %= den;
    }
    return out;
    
      
  }
};
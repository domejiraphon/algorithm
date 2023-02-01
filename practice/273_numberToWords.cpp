/*
273. Integer to English Words

Convert a non-negative integer num to its English words representation.
*/
class Solution {
  unordered_map<int, string> digit;
  unordered_map<int, string> twoLessThan20;
  unordered_map<int, string> ten;
public:
  string numberToWords(int num) {
    if (num == 0)
      return "Zero";
    fillHash();
    int billion = num / pow(10, 9);
    int million = (num - billion* pow(10, 9)) / pow(10, 6);
    int thousand = (num - billion* pow(10, 9)-million*pow(10, 6)) / pow(10, 3);
    int rest = num - billion* pow(10, 9) -million*pow(10, 6) - thousand*pow(10, 3);

    string out="";
    if (billion != 0)
      out += digit[billion] + " Billion";
    if (million != 0){
      if (out.size() > 0)
        out += " ";
      out += threeDigit(million) + " Million";
    }
    if (thousand!= 0) {
      if (out.size() > 0)
        out += " ";
      out += threeDigit(thousand) +" Thousand";
    }
    if (rest != 0) {
      if (out.size() > 0)
        out += " ";
      out += threeDigit(rest);
    }
      
    
    return out ;
  }
private:
  void fillHash(){
    digit[1] = "One"; digit[2] = "Two"; digit[3] = "Three";
    digit[4] = "Four"; digit[5] = "Five"; digit[6] = "Six";
    digit[7] = "Seven"; digit[8] = "Eight"; digit[9] = "Nine";

    twoLessThan20[10] = "Ten"; twoLessThan20[11] = "Eleven"; twoLessThan20[12] = "Twelve";
    twoLessThan20[13] = "Thirteen"; twoLessThan20[14] = "Fourteen"; twoLessThan20[15] = "Fifteen";
    twoLessThan20[16] = "Sixteen"; twoLessThan20[17] = "Seventeen"; twoLessThan20[18] = "Eighteen";
    twoLessThan20[19] = "Nineteen";

    ten[20] = "Twenty"; ten[30] = "Thirty"; ten[40] = "Forty";
    ten[50] = "Fifty"; ten[60] = "Sixty"; ten[70] = "Seventy";
    ten[80] = "Eighty"; ten[90] = "Ninety";
  }
  string twoDigit(int num){
    if (num == 0)
      return "";
    else if (num < 10)
      return digit[num];
    else if (num < 20)
      return twoLessThan20[num];
    else {
      int sec = num % 10;
      int first = num - sec;
      return (sec == 0) ? ten[first] : ten[first] + " " + digit[sec];
    }
  }

  string threeDigit(int num){
    int hundred = num / 100;
    int rest = num - hundred * 100;
    string res="";
    if (hundred*rest != 0)
      res = digit[hundred] + " Hundred " + twoDigit(rest);
    else if ((hundred == 0) && (rest != 0))
      res = twoDigit(rest);
    else if ((hundred != 0) && (rest == 0))
      res = digit[hundred] + " Hundred";
    
    return res;
  }
};

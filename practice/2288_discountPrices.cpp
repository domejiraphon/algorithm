/*
2288. Apply Discount to Prices
A sentence is a string of single-space separated words where each word can contain digits, 
lowercase letters, and the dollar sign '$'. 
A word represents a price if it is a sequence of digits preceded by a dollar sign.

For example, "$100", "$23", and "$6" represent prices while "100", "$", and "$1e5" do not.
You are given a string sentence representing a sentence and an integer discount. For each word representing a price, apply a discount of discount% on the price and update the word in the sentence. All updated prices should be represented with exactly two decimal places.

Return a string representing the modified sentence.

Note that all prices will contain at most 10 digits.


*/
class Solution {
public:
  string discountPrices(string sentence, int discount) {
    int n=sentence.size();
    int i=0;
    string out="";
    while (i < n){
      if (sentence[i] == '$'){
        i++;
        string amt="";
        bool notDigit=false;
        while (i < n && sentence[i] != ' '){
          if (!isdigit(sentence[i]))
            notDigit = true;
          amt += sentence[i++];
        }
      
        if (!notDigit && amt != ""){
          long double v = stoll(amt);
          v = v - (v * discount / 100.0);
          amt = to_string(v);
          int posDot = amt.find('.');
          amt = amt.substr(0, posDot + 3);
          
        }
        out += " $" + amt;
      }
      else {
        string word="";
        while (i < n && sentence[i] != ' '){
          word += sentence[i++];
        }
        
        out += " " + word;
      }
      i++;
    }
    
    return out.substr(1);
  }
};

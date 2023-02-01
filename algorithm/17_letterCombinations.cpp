/* 17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
class Solution {
  unordered_map<int, vector<char>> keyPad;
    
  string digit;
  int n;
  vector<string> res;
public:
  vector<string> letterCombinations(string digits) {
    if (digits == ""){return res;}
    keyPad['2'] = vector<char> {'a', 'b', 'c'};
    keyPad['3'] = vector<char> {'d', 'e', 'f'};
    keyPad['4'] = vector<char> {'g', 'h', 'i'};
    keyPad['5'] = vector<char> {'j', 'k', 'l'};
    keyPad['6'] = vector<char> {'m', 'n', 'o'};
    keyPad['7'] = vector<char> {'p', 'q', 'r', 's'};
    keyPad['8'] = vector<char> {'t', 'u', 'v'};
    keyPad['9'] = vector<char> {'w', 'x', 'y', 'z'};
    digit = digits; n=digits.size(); 
    backtrack(0, "");
    return res;
  }
private:
  void backtrack(int i, string s){
    if (i == n){res.push_back(s); return;}
    for (auto ch: keyPad[digit[i]]){
      backtrack(i + 1, s + ch);
    }
  }
};
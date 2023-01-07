/*
38. Count and Say
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":
*/
class Solution {
public:
  string countAndSay(int n) {
    if (n == 1){return "1";}
    else if (n == 2){return "11";}
    string prev = "11";
    for (int k=2; k<n; k++){
      int m = prev.size();
      int count = 1;
      string res="";
      
      for (int i=1; i<=m; i++){
        if(i != m && prev[i] == prev[i - 1]){
          count++;
        }
        else {
          res += (char) (count + '0');
          res += prev[i - 1];
          count = 1;
        }
        
      }
      prev =res;
    }
    return prev;
    
  }
};
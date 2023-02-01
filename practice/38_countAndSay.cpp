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
    if (n == 1)
      return "1";
    string prev = "1";
    for (int i=1; i<n; i++){
      int left=0, right=0;
      int m = prev.size();
      string cur="";
      while (right < m){
        while (right < m - 1 && prev[right] == prev[right+1])
          right++;
        cur += to_string(right - left + 1) + prev[left];
        right++; left = right;
      }
      prev = cur;
    }
    return prev;
  }
};
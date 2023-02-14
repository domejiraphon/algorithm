/*
171. Excel Sheet Column Number
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
*/
class Solution {
public:
  int titleToNumber(string columnTitle) {
    int n=columnTitle.size();
    int out=0;
    for (int i=0; i<n; i++)
      out = 26 * out + (columnTitle[i] - 'A' + 1);
    
    return out;
  }
};
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:


*/
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) 
      return s;
    int n=s.size();
    int numCols = ceil(n/(2* numRows - 2.0))* (numRows - 1);
    vector<vector<char>> memo(numRows);

    int curRow=0;
    int i=0;
    while (i<n){
      while (curRow < numRows && i<n)
        memo[curRow++].push_back(s[i++]);

      curRow -= 2;
      while (curRow > 0 && i<n)
        memo[curRow--].push_back(s[i++]);
    }
    string res="";
    for (int i=0; i<numRows; i++){
      for (int j=0; j<memo[i].size(); j++){
        res += memo[i][j];
      }
    }
    return res;

  }
};
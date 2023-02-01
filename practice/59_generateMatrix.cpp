/*
59. Spiral Matrix II
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, -1));
    int i=1;
    int row=0, col=0;
    int round=0;
    while (i<=(pow(n, 2))){
      //cout << row <<", "<<col <<", "<<round<<endl;
      while(col < n - round)
        res[row][col++] = i++;
      if (i == pow(n, 2) + 1)
        break;
      row++;
      col--;
      while (row < n - round)
        res[row++][col] = i++;
      if (i == pow(n, 2) + 1)
        break;
      row--;
      col--;
      while (col >= round)
        res[row][col--] = i++;
      if (i == pow(n, 2) + 1)
        break;
      row--;
      col++;
      while (row >= round + 1)
        res[row--][col] = i++;
      if (i == pow(n, 2) + 1)
        break;
      row++;
      col++;
      round++;
      
    }
    
    return res;
  }
};

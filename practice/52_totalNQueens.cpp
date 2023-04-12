/*
52. N-Queens II
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/
class Solution {
public:
  int totalNQueens(int n) {
    vector<bool> cols(n, false);
    vector<bool> diag(2*n, false);
    vector<bool> antiDiag(2*n, false);
    return backtracking(0, cols, diag, antiDiag, n);
  }
private:
  int backtracking(int row, vector<bool>& cols, vector<bool>& diag, vector<bool>& antiDiag, int& n){
    if (row == n)
      return 1;
    int ans=0;
    for (int col=0; col<n; col++){
      int curDiag = row - col + n;
      int curAnti = row + col;
      if (cols[col] || diag[curDiag] || antiDiag[curAnti])
        continue;
      cols[col] = true;
      diag[curDiag] = true;
      antiDiag[curAnti] = true;
      ans += backtracking(row + 1, cols, diag, antiDiag, n);
      cols[col] = false;
      diag[curDiag] = false;
      antiDiag[curAnti] = false;
    }
    return ans;
  }
  
};

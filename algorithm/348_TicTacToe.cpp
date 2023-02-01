class TicTacToe {
  vector<vector<int>> countRow;
  vector<vector<int>> countCol;
  vector<int> countDiagL;
  vector<int> countDiagR;
  int n;
public:
  TicTacToe(int num) {
    n = num;
    countRow.resize(2, vector<int> (n, 0));
    countCol.resize(2, vector<int> (n, 0));
    countDiagL.resize(2, 0);
    countDiagR.resize(2, 0);
    
  }
  
  int move(int row, int col, int player) {
    
    countRow[player - 1][row]++;
    countCol[player - 1][col]++;
    if (row == col)
      countDiagL[player - 1]++;
    if (n - row - 1== col)
      countDiagR[player - 1]++;
    
    if (countRow[player - 1][row] == n ||
        countCol[player - 1][col] == n ||
        countDiagL[player - 1] == n ||
        countDiagR[player - 1] == n)
      return player;
    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
/*
37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

*/
class Solution {
private:
  vector<vector<int>> rows, cols, boxes;
  bool solve=false;
  vector<vector<char>> B;
  int n;
public:
  void solveSudoku(vector<vector<char>>& board) {
    n=board.size();
    rows.resize(n, vector<int> (n+1, 0));
    cols.resize(n, vector<int> (n+1, 0));
    boxes.resize(n, vector<int> (n+1, 0));
    B = board;
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        if (board[i][j] != '.'){
          placeNumber(board[i][j] - '0', i, j);
        }
      }
    }
    backtrack(0, 0);
    board = B;
  }
private:
  void placeNumber(int num, int i, int j){
    int idx = (i / 3) * 3 + j / 3;
    rows[i][num]++;
    cols[j][num]++;
    boxes[idx][num]++;
    B[i][j] = num + '0';
  }

  void removeNumber(int num, int i, int j){
    int idx = (i / 3) * 3 + j / 3;
    rows[i][num]--;
    cols[j][num]--;
    boxes[idx][num]--;
    B[i][j] = '.';
  }

  void placeNext(int i, int j){
    if (i == n - 1 && j == n -1) solve = true;
    else {
      if (j == n - 1) backtrack(i + 1, 0);
      else backtrack(i, j + 1);
    }
  }
  void backtrack(int i, int j){
    if (B[i][j] == '.'){
      for (int num=1; num<10; num++){
        if (canPlace(num, i, j)){
          placeNumber(num, i, j);
          placeNext(i, j);
          if (!solve){removeNumber(num, i, j);}
        }
      }
    }
    else placeNext(i, j);
  }


  bool canPlace(int num, int i, int j){
    int idx = (i / 3) * 3 + j / 3;
    return rows[i][num] + cols[j][num] + boxes[idx][num] == 0;
  }
};

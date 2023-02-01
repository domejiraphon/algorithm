/*
1275. Find Winner on a Tic Tac Toe Game

Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

Players take turns placing characters into empty squares ' '.
The first player A always places 'X' characters, while the second player B always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never on filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.
*/
class Solution {
public:
  string tictactoe(vector<vector<int>>& moves) {
    int rows[3];
    int cols[3];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    int diag=0;
    int rDiag = 0;
    int n=moves.size();
    for (int i=0; i<n ; i++){
      int player = (i % 2 == 0) ? 1 : -1;
      rows[moves[i][0]] += player;
      cols[moves[i][1]] += player;
      if (moves[i][0] == moves[i][1])
        diag += player;
      if (moves[i][0] == 2 - moves[i][1])
        rDiag += player;
      if (abs(rows[moves[i][0]]) == 3 ||
          abs(cols[moves[i][1]]) == 3 ||
          abs(diag) == 3 || abs(rDiag) == 3)
        return (player == 1) ? "A" : "B";
    }
    return (n == 9) ? "Draw": "Pending";
  }
};

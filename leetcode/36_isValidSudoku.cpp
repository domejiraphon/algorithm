/* 
36. Valid Sudoku
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/
class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int nums = 9;
    int rows[nums][nums];
    int cols[nums][nums];
    int boxes[nums][nums];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    memset(boxes, 0, sizeof(boxes));

    for (int i=0; i<nums; i++){
      for (int j=0; j<nums; j++){
        if (board[i][j]== '.')
          continue;
        int idx = (int) j / 3 + 3 * (i / 3);
        int cur = board[i][j] - '1';
        rows[i][cur]++; cols[j][cur]++; boxes[idx][cur]++;
        if (rows[i][cur] != 1 || cols[j][cur] != 1 || boxes[idx][cur] != 1){
          return false;
        }
      }
    }
    return true;
  }
};
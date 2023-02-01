/*
79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
*/
class Solution {
private:
  vector<vector<bool>> visited;
  int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  string W;
  int n, m;
  vector<vector<char>> Board;
public:
  bool exist(vector<vector<char>>& board, string word) {
    n = board.size();
    m = board[0].size();
    visited.resize(n, vector<bool> (m, false));
    Board = board;
    bool out=false;
    W = word;
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (board[i][j] == word[0]){
          visited[i][j] = true;
          out = DFS(i, j, 1);
          visited[i][j] = false;
        }
        if (out){return true;}
      }
    }
    return false;
  }
private:
  bool DFS(int i, int j, int k){
    if (k == W.size()){return true;}
    bool out=false;
    for (auto dir: dirs){
      int x = i + dir[0];
      int y = j + dir[1];
      if (x >=0 && x < n &&
          y >= 0 && y < m &&
          W[k] == Board[x][y] &&
          !visited[x][y]){
        visited[x][y] = true;
        out = DFS(x, y, k + 1);
        visited[x][y] = false;
      }
      if (out){break;}
    }
    return out;
  }
};
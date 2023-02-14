/*
79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
*/
class Solution {
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
  bool exist(vector<vector<char>>& board, string word) {
    int n=board.size();
    int m = board[0].size();
    vector<vector<bool>> visited (n, vector<bool>(m, false));
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (board[i][j] == word[0]){
          visited[i][j] = true;
          if (dfs(board, i, j, 1, word, visited, n, m))
            return true;
          visited[i][j] = false;
        }
      }
    }
    return false;
  }
private:
  bool dfs(vector<vector<char>>& board, int i, int j, int cur, string& word, vector<vector<bool>>& visited, int& n, int& m){
    if(cur == word.size())
      return true;
    for (auto dir: dirs){
      int newI = i + dir[0];
      int newJ = j + dir[1];
      if (0 <= newI && newI < n && 0 <= newJ && newJ<m && 
          !visited[newI][newJ] && board[newI][newJ] == word[cur]){
        visited[newI][newJ] = true;
        if (dfs(board, newI, newJ, cur + 1, word, visited, n, m))
          return true;
        visited[newI][newJ] = false;
      }
    }
    return false;
  }
};
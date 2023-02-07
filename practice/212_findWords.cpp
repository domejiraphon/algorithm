
/*
212. Word Search II
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
*/
class Solution {
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int n=board.size();
    int m=board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<string> res;
    for (auto word: words){
      bool found=false;
      for (int i=0; i<n && !found; i++){
        for (int j=0; j<m && !found; j++){
          if (board[i][j] == word[0]){
            visited = vector<vector<bool>>(n, vector<bool>(m, false));
            visited[i][j] = true;
            found = dfs(board, i, j, n, m, 1, word, visited);
          }
        }
      }
      if (found)
        res.push_back(word);
    }
    return res;
    
  }
private:
  bool dfs(vector<vector<char>>& board, int i, int j, int& n, int& m, int cur, string& word, vector<vector<bool>> & visited){
    if (cur == word.size())
      return true;
    for (auto dir: dirs){
      int newI = i + dir[0];
      int newJ = j + dir[1];
      if (newI >= 0&& newI < n && newJ >=0 && newJ<m && !visited[newI][newJ] && board[newI][newJ] == word[cur]){
        
        visited[newI][newJ] = true;
        if (dfs(board, newI, newJ, n, m, cur + 1, word, visited))
          return true;
        visited[newI][newJ] = false;
      }
    }
    return false;
  }
};

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
    vector<vector<bool>> visited (n, vector<bool> (m, false));
    vector<string> res;
    for(auto ch: words){
      bool found=false;
      for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
          string cur = ch;
          visited[i][j] = true;
          if (board[i][j] == cur[0] && dfs(i, j, n, m, board, visited, 1, cur)){
            res.push_back(cur);
            found = true; break;
          }
          visited[i][j] = false;
        }
        if (found)
          break;
      }
    }
    return res;
  }
private:
  bool dfs(int i, int j, int&n, int& m, vector<vector<char>>& board, 
    vector<vector<bool>>& visited, int idx, string& word){
    if (idx == word.size())
      return true;
    bool out=false;
    for (auto dir: dirs){
      int x = i + dir[0];
      int y = j + dir[1];
      if (0 <= x && x < n && 0 <= y && y < m && !visited[x][y]
          && board[x][y] == word[idx]){
        visited[x][y] = true;
        out = dfs(x, y, n, m, board, visited, idx + 1, word);
        visited[x][y] = false;
      }
    }
    return out;
  }
};

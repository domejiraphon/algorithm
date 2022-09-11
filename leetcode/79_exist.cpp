#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector<string> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      bool out(false);
      
      for (int i=0; i < board.size(); i++){
        for (int j=0; j < board[0].size(); j++){
          if (board[i][j] == word[0]){
            vector<vector<char>>tmp_board = board;
            vector<vector<bool>> visited {board.size(), vector<bool> (board[0].size(), false)};
            out = DFS(tmp_board, visited, i, j, word, 0);
            if (out) {return out;}
          }
        }
      }
      return out;
    }
private:
  bool DFS(vector<vector<char>>& board, vector<vector<bool>> visited,
      int i, int j, string word, int iter){
    if (iter == word.size() ){return true;}
    if (1 == word.size() ){return (board[i][j] == word[iter]) ? true: false;}
    if (word[iter] == board[i][j] && !visited[i][j]){
      //cout << i <<", " << j<<endl;
      visited[i][j] = true;
      //board[i][j] = '_';
      bool left(false), right(false), up(false), down(false);
      if (i-1 >= 0) {down = DFS(board, visited, i-1, j, word, iter+1);}
      if (j-1 >= 0) {left = DFS(board, visited, i, j-1, word, iter+1);}
      if (i+1 < board.size()) {up = DFS(board, visited, i+1, j, word, iter+1);}
      if (j+1 < board[0].size()) {right = DFS(board, visited, i, j+1, word, iter+1);}
      
      return down || left || up || right;
    }
    else {return false;}
  }
};

int main()
{
  
  Solution sol;
  vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                {'S', 'F', 'C', 'S'},
                                {'A', 'D', 'E', 'E'}};
  bool out; 
  
  out = sol.exist(board, "ABCCED");
  cout << out<<endl;

  out = sol.exist(board, "SEE");
  cout << out<<endl;

  board = vector<vector<char>>  {{'A'}};
  out = sol.exist(board, "A");
  cout << out<<endl;

  board = vector<vector<char>>  {{'A', 'B', 'C', 'E'},
                                {'S', 'F', 'E', 'S'},
                                {'A', 'D', 'E', 'E'}};
  out = sol.exist(board, "ABCESEEEFS");
  cout << out<<endl;

  return 0;
}
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<vector<char>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}
void print(vector<vector<bool>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int n=board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int i=0; i < m; i++){ 
      if (board[0][i] == 'O') DFS(board, 0, i, n, m, dirs, visited, true);}
    for (int i=0; i < m; i++){ 
      if (board[n - 1][i] == 'O') DFS(board, n - 1, i, n, m, dirs, visited, true);}
    for (int i=0; i < n; i++){
      if (board[i][0] == 'O') DFS(board, i, 0, n, m, dirs, visited, true);}
    for (int i=0; i < n; i++){
      if (board[i][m - 1] == 'O') DFS(board, i, m - 1, n, m, dirs, visited, true);}
   
    for (int i=0; i < n; i++){
      for (int j=0; j < m; j++){
        if (board[i][j] == 'O' && !visited[i][j]){
          DFS(board, i, j, n, m, dirs, visited, false);
        }
      }
    }
  }
private:
  void DFS(vector<vector<char>>& board, int i, int j, int n, int m, vector<vector<int>>& dirs,
           vector<vector<bool>>& visited, bool check){
    if (!check){board[i][j] = 'X';}
    
    visited[i][j] = true;
    for (vector<int> d: dirs){
      int x = i + d[0], y = j + d[1];
      if (x >= 0 && x < n && y >=0 && y < m && board[x][y] == 'O' && !visited[x][y]){
        DFS(board, x, y, n, m, dirs, visited, check);
      }
    }
  }
};

int main()
{ 
  Solution* sol;
  vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
  //sol -> solve(board);
  //print(board);
  cout << endl;
  board = {{'X','O','X','O','X','O'}, 
            {'O','X','O','X','O','X'},
            {'X','O','X','O','X','O'},
            {'O','X','O','X','O','X'}};
  sol -> solve(board);
  print(board);
  return 0;
}
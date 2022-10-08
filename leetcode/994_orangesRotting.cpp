#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}
void print(queue<pair<int, int>> Q){
  while (!Q.empty()){
    pair<int, int> ele = Q.front();
    cout << ele.first << ", "<< ele.second << endl;
    Q.pop();
  }
}

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> Q;
    int n = grid.size();
    int m = grid[0].size();
    int freshOrange(0);
    for (int i=0; i < n; i++){
      for (int j=0; j < m ; j++){
        if (grid[i][j] == 2){
          Q.push({i, j});
        }
        else if (grid[i][j] == 1){
          freshOrange++;
        }
      }
    }
    int count = BFS(grid, Q, n, m, freshOrange);
    return (freshOrange == 0) ? count : -1;
  }
private:
  int BFS(vector<vector<int>>& grid, queue<pair<int, int>> Q, 
      int n, int m, int& freshOrange){
    if (Q.empty()){return 0;}
    int count(-1);
    while (!Q.empty()){
      int queueSize = Q.size();
      count++;
      for (int i=0; i < queueSize; i++){
        pair<int, int> cur = Q.front();
        int row = cur.first; 
        int col = cur.second;
        grid[row][col] = 0;
        Q.pop();
        if (row > 0 && row < n && col >= 0 && col < m && 
          (grid[row - 1][col] == 1)){
            Q.push({row - 1, col}); grid[row - 1][col] = 0; freshOrange--;
        }
        if (row >= 0 && row < (n -1) && col >= 0 && col < m && 
          (grid[row + 1][col] == 1)){
            Q.push({row + 1, col}); grid[row + 1][col] = 0;freshOrange--;
        }
        if (row >= 0 && row < n && col > 0 && col < m && 
          (grid[row][col - 1] == 1)){
            Q.push({row, col - 1}); grid[row][col - 1] = 0;freshOrange--;
        }
        if (row >= 0 && row < n && col >= 0 && col < (m - 1) && 
          (grid[row][col + 1] == 1)){
            Q.push({row, col + 1}); grid[row][col + 1] = 0;freshOrange--;
        }
      }
    }
    return count;
  }
};


int main()
{ 
  vector<vector<int>> grid;
  Solution* sol;
  
  grid = {{2,1,1}, {1,1,0}, {0,1,1}};
  
  cout << sol -> orangesRotting(grid)<< endl;

  grid = {{0}};
  cout << sol -> orangesRotting(grid)<< endl;

  grid = {{1}};
  cout << sol -> orangesRotting(grid)<< endl;
  grid = {{2,1,1}, {1,1,1}, {0,1,2}};
  cout << sol -> orangesRotting(grid)<< endl;
  grid = {{2,2}, {1,1}, {0,0}, {2, 0}};
  cout << sol -> orangesRotting(grid)<< endl;
  return 0;
}
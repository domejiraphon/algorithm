#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
using namespace std;


class Solution {
private:
  void DFS(vector<vector<char>>& grid, int i, int j){
    grid[i][j] = 0;
    int row = grid.size(); int col = grid[0].size();
    if (i-1 >= 0 && grid[i-1][j] == '1'){DFS(grid, i-1, j);}
    if (j-1 >=0 && grid[i][j-1] == '1'){DFS(grid, i, j-1);}
    if (i+1 < row && grid[i+1][j] == '1'){DFS(grid, i+1, j);}
    if (j+1 < col && grid[i][j+1] == '1'){DFS(grid, i, j+1);}
  }

  void BFS(vector<vector<char>>& grid, int i, int j){
    int row = grid.size(); int col = grid[0].size();
    queue<tuple<int, int>> Q;
    Q.push({i, j});

    while(!Q.empty()){
      tie(i, j) = Q.front();
      grid[i][j] = '0';
      Q.pop();
      if (i-1 >= 0 && grid[i-1][j] == '1'){Q.push({i-1, j});}
      if (j-1 >=0 && grid[i][j-1] == '1'){Q.push({i, j-1});}
      if (i+1 < row && grid[i+1][j] == '1'){Q.push({i+1, j});}
      if (j+1 < col && grid[i][j+1] == '1'){Q.push({i, j+1});}
    }
   
  }
public:
  int numIslands(vector<vector<char>>& grid) {
    int count(0);
    for (int i =0; i != grid.size(); i++){
      for (int j =0; j != grid[0].size(); j++){
        //if (grid[i][j] == '1'){DFS(grid, i, j); count++;}
        if (grid[i][j] == '1'){BFS(grid, i, j); count++;}
       
      }
    }
    return count;
  }

};

int main()
{
  vector<vector<char>> grid2 {{'1', '1', '1',},
                             {'0', '1', '0'},
                             {'1', '1', '1',}};
  
  Solution sol;
  cout << sol.numIslands(grid2)<<endl;
  vector<vector<char>> grid {{'1', '1', '0', '0', '1'},
                             {'1', '1', '0', '0', '0'},
                             {'0', '0', '1', '0', '0'},
                             {'1', '0', '0', '1', '1'}};
  cout << sol.numIslands(grid);
  
  return 0;
}
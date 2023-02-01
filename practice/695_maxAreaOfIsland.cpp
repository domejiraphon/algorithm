#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele :row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    int m = grid[0].size();
    int maxArea(0);
    for (int i=0; i < n; i++){
      for (int j=0; j < m; j++){
        if (grid[i][j] == 1){
          int size(0);
          DFS(grid, i, j, n, m, size);
          maxArea = max(maxArea, size);
        }
      }
    }
    return maxArea;
  }
private:
  void DFS(vector<vector<int>>& grid, 
        int i, int j, int n, int m, int& size){
    if (0 <= i && i < n && 0 <= j && j < m && grid[i][j] == 1){
      size++; 
      grid[i][j] = 0;
      DFS(grid, i - 1, j, n, m, size);
      DFS(grid, i + 1, j, n, m, size);
      DFS(grid, i, j - 1, n, m, size);
      DFS(grid, i, j + 1, n, m, size);
    }
   
  }
};

int main()
{ 
  vector<vector<int>> grid;
  Solution* sol;
  
  grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                 {0,0,0,0,0,0,0,1,1,1,0,0,0},
                 {0,1,1,0,1,0,0,0,0,0,0,0,0},
                 {0,1,0,0,1,1,0,0,1,0,1,0,0},
                 {0,1,0,0,1,1,0,0,1,1,1,0,0},
                 {0,0,0,0,0,0,0,0,0,0,1,0,0},
                 {0,0,0,0,0,0,0,1,1,1,0,0,0},
                 {0,0,0,0,0,0,0,1,1,0,0,0,0}};
  
  cout << sol -> maxAreaOfIsland(grid) << endl;

  grid = {{0, 1}};
  cout << sol -> maxAreaOfIsland(grid) << endl;
  return 0;
}
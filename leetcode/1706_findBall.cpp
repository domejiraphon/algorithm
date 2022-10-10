#include <iostream>
#include <iterator>
#include <map>
#include <unordered_set>
#include <cmath>
#include <vector>
#include <list>

using namespace std;
void print(vector<int> x){
  
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
  
}
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele: row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  vector<int> findBall(vector<vector<int>>& grid) {
    vector<int> res;
    for (int i=0; i < grid[0].size(); i++){
      DFS(grid, 0, i, res);
    }
    return res;
  }
private:
  void DFS(vector<vector<int>>& grid, int i, int j, vector<int>& res){
    if (i == grid.size()){res.push_back(j); return;}
    if (grid[i][j] == 1 && j < (grid[0].size() - 1) && grid[i][j+1] == 1){
      DFS(grid, i+1, j+1, res);
    }
    else if (grid[i][j] == -1 && j > 0 && grid[i][j-1] == -1){
      DFS(grid, i+1, j-1, res);
    }
    else {res.push_back(-1);return;}

  }
};

int main()
{
  Solution* sol;
  vector<vector<int>> grid = {{1,1,1,-1,-1}, {1,1,1,-1,-1}, {-1,-1,-1,1,1}};
  vector<int> out;
  out = sol -> findBall(grid);
  print(out);

  grid = {{-1}};
  out = sol -> findBall(grid);
  print(out);
  grid = {{1,1,1,1,1,1}, {-1,-1,-1,-1,-1,-1}, {1,1,1,1,1,1}, {-1,-1,-1,-1,-1,-1}};
  out = sol -> findBall(grid);
  print(out);
}

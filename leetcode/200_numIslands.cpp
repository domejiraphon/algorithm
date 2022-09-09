#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int numIslands(const vector<vector<char>>& grid) {
    
    int count(0);
    for (int i=0; i != grid.size(); i++){
      for (int j=0; j != grid[0].size(); j++){
        if (i ==0 && j==0 && grid[i][j] == '1'){count++;}
        else if (i ==0) {
          if (grid[i][j] == '1' && grid[i][j-1] == '0'){count++;}
        }
        else if (j ==0) {
          if (grid[i][j] == '1' && grid[i-1][j] == '0'){count++;}
        }
        else {
          if (grid[i][j] == '1' && grid[i-1][j] == '0' && grid[i][j-1] == '0'){count++;}
          if (grid[i][j] == '1' && grid[i-1][j] == '1' && grid[i][j-1] == '1'){count--;}
        }
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
  cout << sol.numIslands(grid2);
  vector<vector<char>> grid {{'1', '1', '0', '0', '0'},
                             {'1', '1', '0', '0', '0'},
                             {'0', '0', '1', '0', '0'},
                             {'0', '0', '0', '1', '1'}};
  cout << sol.numIslands(grid);
  
  return 0;
}
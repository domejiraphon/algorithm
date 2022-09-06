#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> memo=grid;
    for (int i=0; i != grid.size(); i++)
    {
      for (int j=0; j != grid[0].size(); j++)
      {
        if (i==0 && j==0){memo[i][j] = grid[i][j];}
        else if (i==0 && j!=0){memo[i][j] = grid[i][j] + memo[i][j-1];}
        else if (i!=0 && j==0){memo[i][j] = grid[i][j] + memo[i-1][j];}
        else 
        {
          memo[i][j] = grid[i][j] + min(memo[i][j-1], memo[i-1][j]);
        }
      }
    }
    return memo[grid.size()-1][grid[0].size()-1];
  }
};

int main()
{ 
  vector<vector<int>> grid={{1,3,1},
                            {1,5,1},
                            {4,2,1}};
  Solution sol;
  cout<< sol.minPathSum(grid) << endl;
  return 0;
}
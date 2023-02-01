#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();
    vector<vector<int>> memo(n, vector<int>(m, 0));

    for (int i=0; i < n; i++){
      if (obstacleGrid[i][0] == 1){
        memo[i][0] = 0;
        break;
      }
      else{memo[i][0] = 1;}
    }

    for (int j=0; j < m; j++){
      if (obstacleGrid[0][j] == 1){
        memo[0][j] = 0;
        break;
      }
      else{memo[0][j] = 1;}
    }

    for (int i=1; i < n; i++){
      for (int j=1; j < m; j++){
        if (obstacleGrid[i][j] == 1){
          memo[i][j] = 0; continue;
        }
        memo[i][j] = memo[i][j - 1] + memo[i - 1][j];
      }
    }
    return memo[n - 1][m -1];
  }
};

int main()
{
  Solution* sol;
  vector<vector<int>> grid = {{0, 0, 0},
                              {0, 1, 0},
                              {0, 0, 0}};
  cout << sol -> uniquePathsWithObstacles(grid)<< endl;

  grid = {{0, 1}, {0, 0}};
  cout << sol -> uniquePathsWithObstacles(grid)<< endl;
  return 0;
}
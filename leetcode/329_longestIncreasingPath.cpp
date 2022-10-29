#include <iostream>
#include <iterator>
#include <unordered_map>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n=matrix.size(), m=matrix[0].size();
    vector<vector<int>> memo(n, vector<int> (m, -1));
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int out(INT_MIN);
    for (int i=0; i < n; i++){
      for (int j=0; j < m; j++){
        out = max(out, DFS(i, j, n, m, matrix, memo, dirs));
      }
    }
    return out;
  }
private:
  int DFS(int i, int j, int n, int m,
      vector<vector<int>>& matrix, vector<vector<int>>& memo,
      const vector<vector<int>>& dirs){
    if (memo[i][j] != -1){
      return memo[i][j];
    }
    int out(0);
    
    for (int idx=0; idx < 4; idx++){
      int x = i + dirs[idx][0], y = j + dirs[idx][1];
      if (x >= 0 && x < n && y >= 0 && y < m &&
        matrix[i][j] < matrix[x][y]){
          out = max(out, DFS(x, y, n, m, matrix, memo, dirs));
        }
    }
    memo[i][j] = ++out;
    return out;
  }
};

int main()
{
  Solution* sol;
  vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
  cout << sol -> longestIncreasingPath(matrix)<< endl;

  matrix = {{3,4,5},{3,2,6},{2,2,1}};
  cout << sol -> longestIncreasingPath(matrix)<< endl;

}

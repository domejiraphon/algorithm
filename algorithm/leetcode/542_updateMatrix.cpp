/*
542. 01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
*/
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> res = mat;
    int n=mat.size();
    int m=mat[0].size();
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (mat[i][j] == 1)
          res[i][j] = INT_MAX/10;
      }
    }
    int dirs[2][2] = {{-1, 0}, {0, -1}};
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        for (auto dir : dirs){
          int newI = i +dir[0];
          int newJ = j + dir[1];
          if (0 <= newI && newI <n && 0 <= newJ && newJ < m){
            res[i][j] = min(res[i][j], 1 + res[newI][newJ]);
          }
        }
      }
    }
   
    for (int i=n-1; i>=0; i--){
      for (int j=m-1; j>=0; j--){
        for (auto dir : dirs){
          int newI = i - dir[0];
          int newJ = j - dir[1];
          if (0 <= newI && newI <n && 0 <= newJ && newJ < m){
            res[i][j] = min(res[i][j], 1 + res[newI][newJ]);
          }
        }
      }
    }
    return res;
  }
  
};

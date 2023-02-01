/*
1329. Sort the Matrix Diagonally
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.


*/
class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
    int n=mat.size();
    int m=mat[0].size();
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        map[j - i].push(mat[i][j]);
      }
    }
    vector<vector<int>> res(n, vector<int>(m));
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        res[i][j] = map[j - i].top();
        map[j - i].pop();
      }
    }
    return res;
  }
};

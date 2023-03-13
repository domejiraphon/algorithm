/*
562. Longest Line of Consecutive One in Matrix
Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.

The line could be horizontal, vertical, diagonal, or anti-diagonal.
*/
class Solution {
public:
  int longestLine(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    vector<vector<vector<int>>> length(m, vector<vector<int>> (n, vector<int> (4, 0)));
    int longest=0;
    for (int i=0; i<m; i++){
      for (int j=0; j<n; j++){
        if (mat[i][j] == 0)
          continue;
        for (int k=0; k<4; k++)
          length[i][j][k] = 1;
        if (j > 0)
          length[i][j][0] = 1 + length[i][j-1][0];
        if (i > 0)
          length[i][j][1] = 1 + length[i-1][j][1];
        if (i > 0 && j > 0)
          length[i][j][2] = 1 + length[i-1][j-1][2];
        if (i > 0 && j < n - 1)
          length[i][j][3] = 1 + length[i-1][j+1][3];
        longest = max({longest, length[i][j][0], length[i][j][1], 
                       length[i][j][2], length[i][j][3]});
      }
    }
    
    return longest;
  }
};

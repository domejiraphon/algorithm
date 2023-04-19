/*
1074. Number of Submatrices That Sum to Target
Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
*/
class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
    int prefix[n+1][m+1];
    memset(prefix, 0, sizeof(prefix));
    for (int i=1; i<n+1; i++){
      for (int j=1; j<m+1; j++)
        prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
    }
    int count=0;
    for (int r1=1; r1<n+1; r1++){
      for (int r2=r1; r2<n+1; r2++){
        unordered_map<int, int> hash;
        for (int col=0; col<m+1; col++){
          int cur = prefix[r2][col] - prefix[r1 - 1][col];
          if (hash.count(cur - target))
            count += hash[cur - target];
          hash[cur]++;
        }
      }
    }
    return count;
  }
};

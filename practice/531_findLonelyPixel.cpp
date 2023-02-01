/*
531. Lonely Pixel I
Given an m x n picture consisting of black 'B' and white 'W' pixels, return the number of black lonely pixels.

A black lonely pixel is a character 'B' that located at a specific position where the same row and same column don't have any other black pixels.
*/
class Solution {
public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    int n=picture.size();
    int m=picture[0].size();
    int row[n];
    int col[m];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (picture[i][j] == 'B'){
          row[i]++;
          col[j]++;
        }
      }
    }
    int count=0;
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        count += (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1);
      }
    }
    return count;
  }
};

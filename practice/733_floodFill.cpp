/*
733. Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.


*/
class Solution {
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n=image.size();
    int m=image[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[sr][sc] = true;
    dfs(image, sr, sc, image[sr][sc], color, n, m, visited);
    image[sr][sc] = color;
    return image;
  }
private:
  void dfs(vector<vector<int>>& image, int sr, int sc, int starting, int color, int& n, int& m, vector<vector<bool>>& visited){
    for (auto dir: dirs){
      int newSr = sr + dir[0];
      int newSc = sc + dir[1];
      if (newSr >= 0 && newSr < n && newSc>=0 && newSc < m && image[newSr][newSc] == starting && !visited[newSr][newSc]){
        image[newSr][newSc] = color;
        visited[newSr][newSc] = true;
        dfs(image, newSr, newSc, starting, color, n, m, visited);
      }
    }
  }
};
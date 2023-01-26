/*
675. Cut Off Trees for Golf Event
You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:

0 means the cell cannot be walked through.
1 represents an empty cell that can be walked through.
A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).

Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.

Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.
*/
class Solution {
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
  int cutOffTree(vector<vector<int>>& forest) {
    int n=forest.size();
    int m=forest[0].size();
    int rest=0;
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (forest[i][j] > 1)
          rest++;
      }
    }
    rest -= (forest[0][0] > 1);
    
    vector<vector<bool>> visited (n, vector<bool>(m, false));
    int out = dfs(forest, 0, 0, 1, visited, n, m, rest) ;
    return out == INT_MAX/10 ? -1 : out;
  }
private:
  int dfs(vector<vector<int>>& forest, int i, int j, int prev, vector<vector<bool>>& visited, int& n, int& m, int rest){
    if (rest == 0)
      return 0;
    int out=INT_MAX/10;
    for (auto dir: dirs){
      int newI = i + dir[0];
      int newJ = j + dir[1];
      if (0 <= newI && newI <n && 0 <= newJ && newJ < m && !visited[newI][newJ]){
        visited[newI][newJ] = true;
        if (forest[newI][newJ] == 1)
          out = min(out, 1 + dfs(forest, newI, newJ, prev, visited, n, m, rest));
        else if (forest[newI][newJ] >= prev)
          out = min(out, 1 + dfs(forest, newI, newJ, forest[newI][newJ], visited, n, m, rest - 1));
        visited[newI][newJ] = false;
      }
    }
    return out;
  }
};

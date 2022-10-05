#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void print(vector<vector<T>> x){
  for (auto row: x){
    for (auto elem: row) {
      cout << elem <<", ";}
    cout << endl;
  }
  
}
class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), false));
    BFS(image, sr, sc, color, visited);
    return image;
  }
private:
  void BFS(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& visited){
    int n = image.size();
    int m = image[0].size();
    if (sr < 0 || sr == n ||
        sc < 0 || sc == m){return;}
    int cur = image[sr][sc];
    image[sr][sc] = color;
    visited[sr][sc] = true;
    if (sr >= 1 && !visited[sr - 1][sc] && image[sr - 1][sc] == cur){BFS(image, sr - 1, sc, color, visited);}
    if (sr < n - 1 && !visited[sr + 1][sc] && image[sr + 1][sc] == cur){BFS(image, sr + 1, sc, color, visited);}
    if (sc >= 1 && !visited[sr][sc - 1] && image[sr][sc - 1] == cur){BFS(image, sr, sc - 1, color, visited);}
    if (sc < m - 1&& !visited[sr][sc + 1] && image[sr][sc + 1] == cur){BFS(image, sr, sc + 1, color, visited);}
  }
};

int main()
{
  Solution* sol;
  vector<vector<int>> image ={{1,1,1}, {1,1,0}, {1,0,1}};
  vector<vector<int>> out;
  out = sol -> floodFill(image, 1, 1, 2);
  print(out);

  image = {{0, 0, 0}, {0, 0, 0}};
  out = sol -> floodFill(image, 0, 0, 1);
  print(out);
  return 0;
}
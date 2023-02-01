#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    vector<bool> visited(n, false);
    int remove(0);
    for(int i=0; i < n; i++){
      if (!visited[i]){
        int size(-1);
        DFS(stones, visited, i, n, size);
        remove += size;
      }
    }
    return remove;
  }
private:
  void DFS(vector<vector<int>>& stones, vector<bool>& visited,
      int i, int n, int& size){
    size++;
    visited[i] = true;
    for (int j=0; j < n; j++){
      if (j == i){continue;}
      if (((stones[j][0] == stones[i][0]) || (stones[j][1] == stones[i][1])) 
          && !(visited[j])){
        DFS(stones, visited, j, n, size);
      }
    }
  }
};

int main()
{ 
  vector<vector<int>> stones;
  Solution* sol;
  stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
  cout << sol -> removeStones(stones)<< endl;

  stones = {{0,0}, {0,2}, {1,1}, {2,0}, {2,2}};
  cout << sol -> removeStones(stones)<< endl;

  stones = {{0,0}};
  cout << sol -> removeStones(stones)<< endl;
  return 0;
}
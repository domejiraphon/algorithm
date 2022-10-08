#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele :row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int count(0);
    vector<bool> visited(n, false);
    for (int i=0; i < n; i++){
      if (!visited[i]){
        DFS(isConnected, visited, i, n);
        count++;
      }
    }
    return count;
  }
private:
  void DFS(vector<vector<int>>& isConnected, vector<bool>& visited, int i, int n){
    visited[i] = true;
    for (int j=0; j < n; j++){
      if (i == j){continue;}
      if (!visited[j] && isConnected[i][j] == 1){
        DFS(isConnected, visited, j, n);
      }
    }
    return;
  }
};


class SolutionUnion {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int m = isConnected[0].size();
    vector<int> parents(n, -1);
    for (int i=0; i < n; i++){
      for (int j=0; j < m; j++){
        if (i !=j && isConnected[i][j] == 1){
          unionFind(isConnected, parents, i, j);
        }
      }
    }
    int count = 0;
    for (int i = 0; i < parents.size(); i++) {
      if (parents[i] == -1)
        count++;
    }
    return count;
  }
private:
  void unionFind(vector<vector<int>>& isConnected, 
      vector<int>& parents, int i, int j){
    int parentI = find(parents, i);
    int parentJ = find(parents, j);
    if (parentI != parentJ){
      parents[i] = j;
    }
  }
  int find(vector<int> parents, int i){
    if (parents[i] == -1){
      return i;
    }
    return find(parents, parents[i]);
  }
};

int main()
{ 
  vector<vector<int>> isConnected;
  SolutionUnion* sol;
  
  isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};
  cout << sol -> findCircleNum(isConnected)<< endl;

  isConnected = {{1,0,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,1,1}};
  cout << sol -> findCircleNum(isConnected)<< endl;
  return 0;
}
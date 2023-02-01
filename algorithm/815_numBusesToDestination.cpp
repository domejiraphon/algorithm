#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;
    int n= routes.size();
    for (int i=0; i < n; i++){
      sort(routes[i].begin(), routes[i].end());
    }
    for (int i=0; i < n; i++){
      for (int j=0; j <routes[i].size(); j++){
        adj[routes[i][j]].insert(adj[routes[i][j]].end(), routes[i].begin(), routes[i].end());
      }
    }
    
    int out = BFS(adj, visited, source, target);
    return out;
  }
private:
  int BFS(unordered_map<int, vector<int>> adj, unordered_set<int> visited,
        int source, int target){
    queue<int> Q;
    Q.push(source);
    int numLayer(-1);
    bool found(false);
    while (!Q.empty())
    {
      int n=Q.size();
      numLayer++;
      for (int i=0; i < n; i++){
        int cur = Q.front();
        Q.pop();
        visited.insert(cur);
        if (cur == target){
          found = true;
          Q = {};
          break;
        }
        for (int stops: adj[cur]){
          if (visited.find(stops) == visited.end()){
            Q.push(stops);
          }
        }
      }
    }
    return (found) ? numLayer : -1;
  }
  bool intersect(vector<int> routes1, vector<int> routes2){
    int idx1(0), idx2(0);
    int n = routes1.size(), m = routes2.size();
    while (idx1 < n && idx2 < m){
      if (routes1[idx1] == routes2[idx2]){
        return true;
      }
      if (idx1 < idx2){idx1++;}
      else {idx2++;}
    }
    return false;
  }
};

int main()
{ 
  vector<vector<int>> routes;
  Solution* sol;
  routes = {{1,2,7},{3,6,7}};
  cout << sol -> numBusesToDestination(routes, 1, 6)<< endl;
  
  routes = {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
  cout << sol -> numBusesToDestination(routes, 15, 12)<< endl;

  cout << sol -> numBusesToDestination(routes, 15, 4)<< endl;


  return 0;
}
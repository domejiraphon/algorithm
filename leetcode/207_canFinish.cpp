#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, 
    vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    for(auto edge : prerequisites)
      adj[edge[1]].push_back(edge[0]);
    
    vector<bool> visited(numCourses, false);
    vector<bool> parents(numCourses);
    bool out(false);
    for (int i=0; i < numCourses; i++){
      if (!visited[i]){
        out = isCycle(adj, i, visited, parents);
      }
      if (out){break;}
    }
    return !out;
  }
private:
  bool isCycle(vector<int> adj[], int cur,
          vector<bool>& visited, vector<bool>& parents){
    if (adj[cur].size() == 0){return false;}
    visited[cur] = true;
    bool out(false);

    parents[cur] = true;
    for (auto next: adj[cur]){
      if (parents[next]){return true;}
      if (!visited[next]){
        out = isCycle(adj, next, visited, parents);
      }
      if (out){break;}
    }
    parents[cur] = false;
    return out;

  }
};


int main()
{ 
  
  Solution* sol;
  vector<vector<int>> prerequisites;
  prerequisites = {};
  cout << sol -> canFinish(1, prerequisites)<< endl;
  
  prerequisites = {{1,0}};
  cout << sol -> canFinish(2, prerequisites)<< endl;

  prerequisites = {{1,0},{0,1}, {0, 2}};
  cout << sol -> canFinish(3, prerequisites)<< endl;
  
  
  return 0;
}
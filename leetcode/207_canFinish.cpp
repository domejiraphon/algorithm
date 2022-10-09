#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}
void print(vector<string> x){
  for (auto row: x){
    cout << row <<", ";
    
  }
  cout << endl;
}

class Solution {
public:
  bool canFinish(int numCourses, 
    vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses, vector<int> {});
    vector<string> state(numCourses, "undiscovered");
    for (auto ele: prerequisites){
      adj[ele[0]].push_back(ele[1]);
    }
    bool isCycle(false);
    for (int i=0; i<numCourses; i++){
      if (state[i] != "visited"){
        isCycle = DFS(adj, i, state);
        if (isCycle){return false;}
      }
    }
    return !isCycle;
  }
private:
  bool DFS(vector<vector<int>> adj, int start, 
    vector<string>& state){
    state[start] = "active";
    bool isCycle(false);
    for (auto neighbors: adj[start]){
      if (state[neighbors] == "active"){
        isCycle = true;
        break;
      }
      if (state[neighbors] == "undiscovered"){
        isCycle = isCycle || DFS(adj, neighbors, state);
      }
    }
    state[start] = "visited";
    return isCycle;
  }
};

int main()
{ 
  
  Solution* sol;
  vector<vector<int>> prerequisites;

  prerequisites = {{1,0}};
  cout << sol -> canFinish(2, prerequisites)<< endl;

  prerequisites = {{1,0},{0,1}, {0, 2}};
  cout << sol -> canFinish(3, prerequisites)<< endl;
  return 0;
}
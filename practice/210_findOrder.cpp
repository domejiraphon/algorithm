#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <tuple>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

class Solution {
  int step=0;
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
    vector<int> adj[numCourses];
    for(auto edge : prerequisites)
      adj[edge[1]].push_back(edge[0]);
    
    vector<bool> visited(numCourses, false);
    vector<bool> parents(numCourses);
    vector<vector<int>> time(numCourses, vector<int> (2));
    for (int i=0; i< numCourses; i++){
      time[i][0] = i;
    }
    bool out;
   
    for (int i=0; i< numCourses; i++){
      if (!visited[i]){
        out = DFS(adj, i, visited, parents, time);
      }
      if (out){return vector<int> {};}
    }
    sort(time.begin(), time.end(), [](const vector<int>& a, const vector<int>& b) -> bool
    {
        return a[1] > b[1];
    });
    
    vector<int> order(numCourses);
    for (int i=0; i < numCourses; i++) {order[i] = time[i][0];}
    return order;
  }

  bool DFS(vector<int> adj[], int cur,
    vector<bool>& visited, vector<bool>& parents,
    vector<vector<int>>& time){

      visited[cur] = true;
      parents[cur] = true; 
      bool out(false);
      
      for (auto child: adj[cur]){
         
        if (parents[child]){return true;}
        if (!visited[child]){
          out = DFS(adj, child, visited, parents, time);
        }
        if (out){break;}
      }
      step++;
      parents[cur] = false; 
      time[cur][1] = step;
      
      return out;
    }
};



int main()
{ 
  
  Solution* sol = new Solution();
  vector<vector<int>> prerequisites;
  

  prerequisites = {{1,0}};
  vector<int> out;
  out = sol ->findOrder(2, prerequisites);
  /**
   * prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};
  vector<int> out;
  out = sol ->findOrder(4, prerequisites);
  */
  
  return 0;
}
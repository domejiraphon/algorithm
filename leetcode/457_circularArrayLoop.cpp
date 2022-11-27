class Solution {
private:
  vector<bool> visited;
  vector<string> status;
  vector<vector<int>> graph;
  bool isCycle = false;
public:
  bool circularArrayLoop(vector<int>& nums) {
    int n=nums.size();
    visited.resize(n, false);
    status.resize(n, "undiscovered");
    graph.resize(n);
    for (int i=0; i<n; i++){
      int target = (i + nums[i] + n) % n;
      
      if (target != i){
        graph[i].push_back(target);
      }
    }
   
    for (int i=0; i<n; i++){
      if (!visited[i]){
   
        DFS(i);
      }
      
    }
    return isCycle;
  }
private:
  void DFS(int source){
    status[source] = "active";
    visited[source] = true;
    for (auto neigh: graph[source]){
      if (status[neigh] == "active"){
        isCycle = true;
        return;
      }
      if (!visited[neigh]){
        DFS(neigh);
        visited[neigh] = true;
        
      }
    }
    status[source] = "discovered";
    return;
  }
};

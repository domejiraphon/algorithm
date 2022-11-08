#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <iostream>
using namespace std;
void print(queue<int> S){
  while (!S.empty()){
    cout << S.front() << ", ";
    S.pop();
  }
  cout << endl;
}
void print(unordered_map<int, vector<int>> graph){
  for (auto it=graph.begin(); it != graph.end(); it++){
    cout << it -> first << ": ";
    for (auto ele: it -> second){
      cout << ele << ", ";
    }
    cout << endl;
  }
  cout << endl;
}
class Solution {
public:
  int treeDiameter(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph;
    
    int n=edges.size() + 1;
    for (auto ele: edges){
      graph[ele[0]].push_back(ele[1]);
      graph[ele[1]].push_back(ele[0]);
    }
    
    int A, distA, B, distB, C, distC;
    BFS(graph, 1, A, distA, n);
    //memset(&visited, false, sizeof(visited)); 
   
    BFS(graph, A, B, distB, n);
    //memset(&visited, false, sizeof(visited)); 
    cout << A << endl;
    cout << B << endl; exit(0);
    BFS(graph, B, C, distC, n);
    return distC;
  }
private:
  void BFS(unordered_map<int, vector<int>>& graph, int source,
          int& furthest, int& distance, int numNodes){
    queue<int> S;
    S.push(source);
    int prev;
    int count(-1);
    vector<bool> visited(numNodes, false);
    while (!S.empty()){
      int n = S.size();
      for (int i=0; i < n; i++){
        int head = S.front();
        visited[head] = true;
        S.pop();
        for (int ele: graph[head]){
          if (!visited[ele]){
            S.push(ele);
          }
        }
        prev = head;
      }
      
      count++;
    }
    furthest = prev;
    distance = count;
  }
};
int main()
{ 
  
  Solution* sol;
  vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {1,4}, {4,5}};

  cout << sol -> treeDiameter(edges) << endl;
  return 0;
}
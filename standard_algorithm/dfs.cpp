// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <stack>
using namespace std;
class Graph
{
    int V, time; 
    vector<vector<int>> adj;
    vector<string> visited;
    vector<int> parents, starting_time, finishing_time;
    stack<int> topological_order;
  public:
  Graph(int V) {
    this -> V = V;
    adj.resize(V);
    visited.resize(V, "undiscovered");
    parents.resize(V, -1);
    starting_time.resize(V, -1);
    finishing_time.resize(V, -1);
    time = 0;
  }

  void addEdge(int u, int v){
    adj[u].push_back(v);
  }

  void DFS()
  {
    for (int i=0; i != V; i++)
    {
      if (visited[i] == "undiscovered")
      {
        DFS_helper(i);
      }
    }
    cout << "starting time: "<<endl;
    print(starting_time);
    cout << "finishing time: "<<endl;
    print(finishing_time);
  }
  
  void DFS_helper(int s)
  {
    time++;
    starting_time[s] = time;
    visited[s] = "active";
    

    for (auto adjecent: adj[s])
    {
      if (visited[adjecent] == "undiscovered")
      {
        parents[adjecent] = s;
        DFS_helper(adjecent);
      }
    }
    visited[s] = "seen";
    time++;
    topological_order.push(s);
    finishing_time[s] = time;
     
  }

  void print_adj(){
    
    for (auto row: adj)
    {
      for (auto elem: row)
      {
        cout << elem << ", ";
      }
      cout << endl;
    }
  }

  void print(const vector<int>& in){
   
    for (auto elem: in)
    {
      cout << elem << ", ";
      
    }
    cout << endl;
  }

  void topological_sort()
  {
    cout << "Topological sort order: "<< endl;
    while (!topological_order.empty()) {
      cout << topological_order.top() << " ";
      topological_order.pop();
    }
    cout << endl;
  }
};

int main()
{
  // Create a graph given in the above diagram
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(0, 2);
  g.addEdge(3, 2);
 
 
  g.DFS();
  g.topological_sort();
  return 0;
}

// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <list>
using namespace std;
class Graph
{
    int V; 
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parents;
  public:
  Graph(int V) {
    this -> V = V;
    adj.resize(V);
    visited.resize(V, false);
    parents.resize(V, -1);
  }

  void addEdge(int u, int v){
    adj[u].push_back(v);
  }

  void BFS(int s)
  {
      // Mark all the vertices as not visited
      // Create a queue for BFS
      queue<int> queue;
 
      // Mark the current node as visited and enqueue it
      visited[s] = true;
      queue.push(s);
  
      while(!queue.empty())
      {
          // Dequeue a vertex from queue and print it
          s = queue.front();
          cout << s << " ";
          queue.pop();
  
          // Get all adjacent vertices of the dequeued
          // vertex s. If a adjacent has not been visited,
          // then mark it visited and enqueue it
          for (auto adjecent: adj[s])
          {
              if (!visited[adjecent])
              {
                  visited[adjecent] = true;
                  queue.push(adjecent);
                  parents[adjecent] = s;
              }
          }
      }
      cout << endl;
     
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

  void print_1d(const vector<int>& in){
   
    for (auto elem: in)
    {
      cout << elem << ", ";
      
    }
    cout << endl;
  }

  
};

int main()
{
  // Create a graph given in the above diagram
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  //g.print_adj();
  cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
  g.BFS(2);

  return 0;
}

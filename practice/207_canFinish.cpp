/*
207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto relation: prerequisites)
      adj[relation[1]].push_back(relation[0]);
    vector<bool> visited(numCourses, false);
    vector<bool> active(numCourses, false);
    for (int i=0; i<numCourses; i++){
      if (!visited[i]){
        if (isCycle(adj, visited, i, active))
          return false;
      }
    }
    return true;
  }
private:
  bool isCycle(vector<vector<int>>& adj, vector<bool>& visited, int i, vector<bool>& active){
    active[i] = true;
    for (auto neigh: adj[i]){
      if (active[neigh])
        return true;
      if (!visited[neigh]){
        visited[neigh] = true;
        if (isCycle(adj, visited, neigh, active))
          return true;
      }
        
    }
    active[i] = false;
    return false;
  }
};

class Node {
public:
  int inDegrees=0;
  vector<int> outNodes;
};

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (prerequisites.size() == 0)
      return true;
    unordered_map<int, Node*> graph;
    for (auto relation: prerequisites){
      Node* prev = createNode(graph, relation[1]);
      Node* next = createNode(graph, relation[0]);
      prev ->outNodes.push_back(relation[0]);
      next -> inDegrees++;
    }

    vector<int> noDep;
    for (auto it=graph.begin(); it != graph.end(); it++){
      if (it -> second -> inDegrees == 0)
        noDep.push_back(it -> first);
    }
    int removedEdges = 0;
    while (noDep.size() > 0){
      int cur = noDep.back();
      noDep.pop_back();
      for (int next: graph[cur] -> outNodes){
        Node* child = graph[next];
        child -> inDegrees--;
        removedEdges++;
        if (child -> inDegrees == 0)
          noDep.push_back(next);
      }
    }
    return (removedEdges == prerequisites.size()); 

  }
private:
  Node* createNode(unordered_map<int, Node*>& graph, int course){
    if (graph.count(course))
      return graph[course];
    Node* cur = new Node();
    graph[course] =cur;
    return cur;
  }
};
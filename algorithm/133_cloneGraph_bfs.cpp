#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

void print(unordered_map<Node*, Node*> visited){
  for (auto it=visited.begin(); it != visited.end(); it++){
    cout << it -> first -> val<< ": ";
    for (auto x: it-> second -> neighbors){
      cout << x <<", ";
    }
    cout << endl;
  }
}


class Solution {
private:
  unordered_map<Node*, Node*> visited;
public:
  Node* cloneGraph(Node* node) {
    if(!node){return node;}

    queue<Node*> Q;
    Q.push(node);
    Node* cloneNode = new Node(node -> val);
    visited[node] = cloneNode;
    while (!Q.empty()){
      Node* cur = Q.front();
      Q.pop();

      cloneNode = visited[cur];
      for (auto ele: cur -> neighbors){
        if (visited.find(ele) == visited.end()){
          Q.push(ele);
          Node* cloneNeighbor = new Node(ele -> val);
          visited[ele] = cloneNeighbor;
        }
        (cloneNode -> neighbors).push_back(visited[ele]);
      }
    }
    
    return visited[node];
    
  }
};

int main()
{ 
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  
  node1 -> neighbors = vector<Node*> {node2, node4};
  node2 -> neighbors = vector<Node*> {node1, node3};
  node3 -> neighbors = vector<Node*> {node2, node4};
  node4 -> neighbors = vector<Node*> {node1, node3};


  Solution sol;
  Node* out = sol.cloneGraph(node1);
  cout << out -> val << endl;
  cout << out -> neighbors[0] -> val << endl;
  cout << out -> neighbors[1] -> val << endl;
  return 0;
}
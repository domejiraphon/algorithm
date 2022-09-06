#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

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

map<int, bool> visited;

class Solution {
public:
  Node* cloneGraph(Node* node) {
    if (!node){
      return nullptr;
    }
    Node* new_node = new Node(node -> val);
    
    vector <Node*> ptr_neighbors;
    if (visited.find(new_node -> val) == visited.end()){
      visited[new_node -> val] = false;
    }
    for (Node* neighb : node -> neighbors){  
      if (visited.find(neighb -> val) == visited.end()){
        visited[neighb -> val] = false;
      } 
      if (!visited[neighb -> val]){
        ptr_neighbors.push_back(cloneGraph(neighb));
      }

    }
    if (visited.find(new_node -> val) == visited.end()){
      visited[new_node -> val] = true;
    }
   
   
    new_node -> neighbors = ptr_neighbors;
    return new_node;
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
  cout<< out << endl;
  cout<< out -> neighbors[0] << endl;
  cout<< out -> neighbors[1] << endl;
  return 0;
}
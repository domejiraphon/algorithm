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

void print(vector<int> x){
  for (auto ele: x){
    cout << ele <<", ";
  }
   cout << endl;
}

class Solution {
public:
  vector<int> preorder(Node* root) {
    vector<int> out;
    preorder(root, out);
    return out;
  }
private:
  void preorder(Node* root, vector<int>& cache) {
    if (!root){return;}
    cache.push_back(root -> val);
    for (auto ele: root ->neighbors){
      preorder(ele, cache);
    }
  }
};

int main()
{ 
  Node* node1_1 = new Node(1);

  Node* node2_1 = new Node(3);
  Node* node2_2 = new Node(2);
  Node* node2_3 = new Node(4);

  Node* node3_1 = new Node(5);
  Node* node3_2 = new Node(6);
  
  node1_1 -> neighbors = vector<Node*> {node2_1, node2_2, node2_3};
  node2_1 -> neighbors = vector<Node*> {node3_1, node3_2};
  


  Solution* sol;
  vector<int> out = sol -> preorder(node1_1);
  print(out);
  return 0;
}
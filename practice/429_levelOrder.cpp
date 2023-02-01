#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Node {
public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
      val = _val;
  }

  Node(int _val, vector<Node*> _children) {
      val = _val;
      children = _children;
  }
};
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem << " ";
    }
    cout << endl;
  }
}

void print1d(vector<int> x){
  for (auto elem: x){
    cout << elem << " ";
  }
  cout << endl;
}

class Solution {
public:
  vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> out;
    if (!root)
      return out;
    queue<Node*> Q;
    Q.push(root);
 
    vector<int> tmp;
    while(!Q.empty()){
      int n = Q.size();
      for (int i=0; i < n; i++){
        Node* cur_node = Q.front();
        Q.pop();
        tmp.push_back(cur_node -> val);
        for (auto child: cur_node -> children)
          Q.push(child);
      }
      out.push_back(tmp);
      tmp.clear();
    }
    return out;
  }

};

int main()
{ 
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);
  Node* node6 = new Node(6);
  
  node1 -> children = vector<Node*> {node3, node2, node4};
  node3 -> children = vector<Node*> {node5, node6};
  

  Solution sol;
  vector<vector<int>> out = sol.levelOrder(node1);
  print(out);
  return 0;
}
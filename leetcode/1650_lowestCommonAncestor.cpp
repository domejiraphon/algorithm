#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
  Node(int x){val=x;}
  int val;
  Node* left;
  Node* right;
  Node* parent;
};

class Solution {
public:
  Node* lowestCommonAncestor(Node* p, Node * q){
    vector<Node*> out_p;
    lowestCommonAncestorHelper(p, q, out_p);
    remove(out_p);
    return out_p[0];
 
  }
  void lowestCommonAncestorHelper(Node* p, Node * q, vector<Node*>& out_p){
    if (!p || !q) {return ;}
    if (p == q) {
      if (find(out_p.begin(), out_p.end(), p) == out_p.end()){
        out_p.push_back(p);} 
      return;}
   
    lowestCommonAncestorHelper(p -> parent ? p -> parent : nullptr, q, out_p);
    lowestCommonAncestorHelper(p, q -> parent ? q -> parent : nullptr, out_p);

  }

  void remove(vector<Node*>& out_p){
    for (int i=0; i != out_p.size(); i++){
      for (int j=i; j != out_p.size(); j++){
        if (out_p[i] -> left == out_p[j] || out_p[i] -> right == out_p[j]){
          out_p.erase(out_p.begin()+i);
          break;
        }
      }
    }

  }
};

int main()
{
  Node* node0_0 = new Node(3);

  Node* node1_0 = new Node(5);
  Node* node1_1 = new Node(1);

  Node* node2_0 = new Node(6);
  Node* node2_1 = new Node(2);
  Node* node2_2 = new Node(0);
  Node* node2_3 = new Node(8);

  Node* node3_0 = new Node(7);
  Node* node3_1 = new Node(4);

  node0_0 -> left = node1_0; node1_0 -> parent = node0_0;
  node0_0 -> right = node1_1; node1_1 -> parent = node0_0;
  node1_0 -> left = node2_0; node2_0 -> parent = node1_0;
  node1_0 -> right = node2_1; node2_1 -> parent = node1_0;
  node1_1 -> left = node2_2; node2_2 -> parent = node1_1;
  node1_1 -> right = node2_3; node2_3 -> parent = node1_1;
  node2_1 -> left = node3_0; node3_0 -> parent = node2_1;
  node2_1 -> right = node3_1; node3_1 -> parent = node2_1;
 
  Solution sol;
  Node* out;

  //out = sol.lowestCommonAncestor(node1_0, node1_1);
  //cout << out -> val<<endl;

  out = sol.lowestCommonAncestor(node3_0, node3_1);
  cout << out -> val<<endl;
  return 0;
}
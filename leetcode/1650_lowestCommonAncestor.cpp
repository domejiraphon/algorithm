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
  Node* lowestCommonAncestor(Node* p, Node * q) {
    vector<Node*> pathP, pathQ;
    getPathToRoot(p, pathP); getPathToRoot(q, pathQ);
    int left(pathP.size() - 1), right(pathQ.size() - 1);
    while (left >=0 && right >=0 && pathP[left] == pathQ[right]){
      left--; right--;
    }
    return pathP[++left];
  }
private:
  void getPathToRoot(Node* cur, vector<Node*>& path){
    if (!cur){return;}
    path.push_back(cur);
    getPathToRoot(cur -> parent, path);
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
/* 1650. Lowest Common Ancestor of a Binary Tree III
Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

According to the definition of LCA on Wikipedia: 
"The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants 
(where we allow a node to be a descendant of itself)."
*/

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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
  Node* lowestCommonAncestor(Node* p, Node * q) {
    Node* root = findRoot(p);
    return ancestor(root, p, q);
  }
private:
  Node* findRoot(Node* p){
    return (p -> parent) ? findRoot(p -> parent) : p;
  }
  
  Node* ancestor(Node* root, Node* p, Node* q){
    if (!root || root == p || root == q)
      return root;
    Node* left = ancestor(root -> left, p, q);
    Node* right = ancestor(root -> right, p, q);

    if (left && right)
      return root;
    else
      return (left) ? left : right;
  }
};

class Solution {
public:
  Node* lowestCommonAncestor(Node* p, Node * q) {
    Node* a = p;
    Node* b = q;
    while (a != b){
      a = (!a) ? q : a -> parent;
      b = (!b) ? p : b -> parent;
    }
    
    return a;
  }
};
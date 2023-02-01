#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
class Solution {
public:
  Node* inorderSuccessor(Node* node) {
    if (node -> right){
      node = node -> right;
      while (node -> left){
        node = node -> left;
      }
      return node;
    }
    
      
    while (node -> parent && node == node -> parent -> right){
      node = node -> parent;
    }
      
    return node -> parent;
  }
};


class Solution {
public:
  Node* inorderSuccessor(Node* node) {
    Node* root = getRoots(node);
    Node* suc = nullptr;
    while(root){
      if (node -> val >= root -> val)
        root = root -> right;
      else{
        suc = root;
        root = root -> left;
      }
    }
    return suc;
  }
private:
  Node* getRoots(Node* node){
    while (node -> parent)
      node = node -> parent;
    return node;
  }
};
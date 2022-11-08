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

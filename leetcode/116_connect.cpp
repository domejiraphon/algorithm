#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node* connect(Node* root) {
    if (!root){return nullptr;}
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()){
      int n = Q.size();
      Node* prev;
      for (int i=0; i<n; i++){
        Node* head = Q.front();
        Q.pop();
        if (i > 0){
          prev -> next = head;
        }
        if (head -> left){
          Q.push(head -> left);
        }
        if (head -> right){
          Q.push(head -> right);
        } 
        prev = head;
      }
      prev -> next = nullptr;
    }
    return root;
  }
};

int main()
{
  Solution* sol;

  Node* node1 = new Node(1);

  Node* node2 = new Node(2);
  Node* node3 = new Node(3);

  Node* node4 = new Node(4);
  Node* node5 = new Node(5);
  Node* node6 = new Node(6);
  Node* node7 = new Node(7);

  node1 -> left = node2; node1 -> right = node3;
  node2 -> left = node4; node2 -> right = node5;
  node3 -> left = node6; node3 -> right = node7;

  Node* out = sol -> connect(node1);

}

/*
116. Populating Next Right Pointers in Each Node
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/
/*
// Definition for a Node.
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
*/

class Solution {
public:
  Node* connect(Node* root) {
    if (!root)
      return root;
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()){
      int len = Q.size();
      for (int i=0; i<len; i++){
        Node* cur = Q.front();
        Q.pop();
        
        if (i < len - 1)
          cur -> next = Q.front();
        else
          cur -> next = nullptr;
        if (cur -> left)
          Q.push(cur -> left);
        if (cur -> right)
          Q.push(cur -> right);
      }
     
    }
    
    return root;
  }
};
/*
590. N-ary Tree Postorder Traversal
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)


*/
/*
// Definition for a Node.
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
*/

class Solution {
public:
  vector<int> postorder(Node* root) {
    vector<int> res;
    helper(root, res);
    return res;
  }
private:
  void helper(Node* root, vector<int>& res){
    if (!root)
      return;
    for (auto child: root -> children)
      helper(child, res);
    res.push_back(root -> val);
  }
};

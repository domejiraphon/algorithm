/**
 * 1315. Sum of Nodes with Even-Valued Grandparent
 * Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. 
 * If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int sumEvenGrandparent(TreeNode* root) {
    int out=0;
    sum(root, out, nullptr);
    return out;
  }
private:
  void sum(TreeNode* root, int& out, TreeNode* parent){
    if (!root)
      return;
    if (parent && parent -> val % 2 == 0){
      if (root -> left)
        out += root -> left -> val;
      if (root -> right)
        out += root -> right -> val;
    }
    sum(root -> left, out, root);
    sum(root -> right, out, root);
  }
};
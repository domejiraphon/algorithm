/*
897. Increasing Order Search Tree
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.
*/
/**
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
  TreeNode* head;
public:
  TreeNode* increasingBST(TreeNode* root) {
    TreeNode* dummy = new TreeNode(0);
    head = dummy;
    inOrder(root);
    return dummy -> right;
  }
private:
  void inOrder(TreeNode* root){
    if (!root)
      return;
    inOrder(root -> left);
    root -> left = nullptr;
    head -> right = root;
    head = root;
    inOrder(root -> right);
  }
};

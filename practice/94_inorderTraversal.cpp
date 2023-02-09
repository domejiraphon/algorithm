/*
94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.
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
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    helper(root, res);
    return res;
  }
private:
  void helper(TreeNode* root, vector<int>& res){
    if (!root)
      return;
    helper(root -> left, res);
    res.push_back(root -> val);
    helper(root -> right, res);
  }
};
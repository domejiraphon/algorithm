/*
1080. Insufficient Nodes in Root to Leaf Paths
Given the root of a binary tree and an integer limit, delete all insufficient nodes in the tree simultaneously, and return the root of the resulting binary tree.

A node is insufficient if every root to leaf path intersecting this node has a sum strictly less than limit.

A leaf is a node with no children.
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
  TreeNode* sufficientSubset(TreeNode* root, int limit) {
  if (root -> left == root -> right)
    return root -> val < limit ? nullptr : root;
  if (root -> left)
    root -> left = sufficientSubset(root -> left, limit - root -> val);
  if (root -> right)
    root -> right = sufficientSubset(root -> right, limit - root -> val);
  return root -> left == root -> right ? nullptr : root;
  }
};

/*
865. Smallest Subtree with all the Deepest Nodes
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.
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
  unordered_map<TreeNode*, int> depthNode;
  int maxDepth=0;
public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    findDepth(root, 0, depthNode);
    return answer(root);
  }
private:
  void findDepth(TreeNode* root, int val, unordered_map<TreeNode*, int>& depthNode){
    if (!root)
      return;
    depthNode[root] = val;
    maxDepth = max(maxDepth, val);
    findDepth(root -> left, val + 1, depthNode);
    findDepth(root -> right, val + 1, depthNode);
  }
  TreeNode* answer(TreeNode* node){
    if (!node || depthNode[node] == maxDepth)
      return node;
    TreeNode* left = answer(node -> left);
    TreeNode* right = answer(node -> right);
    if (left && right)
      return node;
    if (left)
      return left;
    return right;
  }
};

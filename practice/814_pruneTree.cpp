/*
814. Binary Tree Pruning

Given the root of a binary tree, return the same tree where every subtree (of the given tree) 
not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.
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
class Solution2 {
  unordered_map<TreeNode*, bool> canPrune;
public:
  TreeNode* pruneTree(TreeNode* root) {
    allZero(root);
    return prune(root);
  }
private:
  bool allZero(TreeNode* root){
    if (!root){return true;}
    bool out=false;
    if (root -> val == 0) 
      out = allZero(root -> left) && allZero(root -> right);
    else 
      allZero(root -> left); allZero(root -> right);
    return canPrune[root] = out;
  }

  TreeNode* prune(TreeNode* root){
    if (!root) return root;
    if (canPrune[root]){
      return nullptr;
    }
    else {
      root -> left = prune(root -> left);
      root -> right = prune(root -> right);
      return root;
    }
  }
};


class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
  if (!root) 
    return nullptr;
  
  TreeNode* left_prune = pruneTree(root -> left);
  TreeNode* right_prune = pruneTree(root -> right);
  root -> left = left_prune;
  root -> right = right_prune;
  if (!left_prune && !right_prune && root -> val == 0)
    return nullptr;
  return root;
  }
};

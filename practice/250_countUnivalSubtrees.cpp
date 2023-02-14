/*
250. Count Univalue Subtrees
Given the root of a binary tree, return the number of uni-value 
subtrees
.

A uni-value subtree means all nodes of the subtree have the same value.
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
  TreeNode* dummy = new TreeNode(INT_MAX);
public:
  int countUnivalSubtrees(TreeNode* root) {
    if (!root)
      return 0;
    int num=0;
    dfs(root, num);
    return num;
  }
private:
  TreeNode* dfs(TreeNode* root, int& num){
    if (!root -> left && !root -> right){
      num++;
      return root;
    }
      
    TreeNode* leftLeaves = nullptr;
    TreeNode* rightLeaves = nullptr;
    if (root -> left)
      leftLeaves = dfs(root -> left, num);
    if (root -> right)
      rightLeaves = dfs(root -> right, num);
    if (leftLeaves && rightLeaves && root -> val == leftLeaves -> val && root -> val == rightLeaves -> val){
      num++;
      return root;
    }
    else if (leftLeaves && !rightLeaves && root -> val == leftLeaves -> val){
      num++;
      return root;
    }
    else if (rightLeaves && !leftLeaves && root -> val == rightLeaves -> val){
      num++;
      return root;
    }
    return dummy;
  }
};

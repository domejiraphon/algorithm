/*
1026. Maximum Difference Between Node and Ancestor
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
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
  int maxAncestorDiff(TreeNode* root) {
    int diff=0;
    DFS(root, INT_MIN, INT_MAX, diff);
    return diff; 
  }
private:
  void DFS(TreeNode* root, int maxNode, int minNode, int& diff){
    if (!root)
      return;
    maxNode = max(maxNode, root -> val);
    minNode = min(minNode, root -> val);
    diff = max({diff, 
                abs(maxNode - root -> val),
                abs(minNode - root -> val)});
    DFS(root -> left, maxNode, minNode, diff);
    DFS(root -> right, maxNode, minNode, diff);
  }
};

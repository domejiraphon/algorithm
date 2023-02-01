/*
1469. Find All The Lonely Nodes
In a binary tree, a lonely node is a node that is the only child of its parent node. The root of the tree is not lonely because it does not have a parent node.

Given the root of a binary tree, return an array containing the values of all lonely nodes in the tree. Return the list in any order.
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
  vector<int> getLonelyNodes(TreeNode* root) {
    vector<int> res;
    helper(root, res);
    return res;
  }
private:
  void helper(TreeNode* root, vector<int>& res){
    if (!root)
      return;
    if (root -> left && !root -> right)
      res.push_back(root -> left -> val);
    else if (!root -> left && root -> right)
      res.push_back(root -> right -> val);
    helper(root -> left, res);
    helper(root -> right, res);
  }
};

/*
230. Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
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
  int kthSmallest(TreeNode* root, int k) {
    vector<int> res;
    getAll(root, res);
    return res[k-1];
  }
private:
  void getAll(TreeNode* root, vector<int>& res){
    if (!root)
      return;
    getAll(root -> left, res);
    res.push_back(root -> val);
    getAll(root -> right, res);
  }
};
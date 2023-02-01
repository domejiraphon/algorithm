/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 
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
  unordered_map<int, int> inOrderIdx;
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=inorder.size();
    for (int i=0; i<n; i++)
      inOrderIdx[inorder[i]] = i;
    int idx=0;
    return helper(preorder, 0, preorder.size() - 1, idx);
  }
private:
  TreeNode* helper(vector<int>& preorder, int left, int right, int& idx){
    if (left > right)
      return nullptr;
    int val = preorder[idx++];
    TreeNode* root = new TreeNode(val);
    int indexRoot = inOrderIdx[val];

    root -> left = helper(preorder, left, indexRoot - 1, idx);
    root -> right = helper(preorder, indexRoot + 1, right, idx);
    return root;
  }
};
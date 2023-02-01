/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    
    int n=inorder.size();
    for (int i=0; i<n; i++)
      inOrderIdx[inorder[i]] = i;
    int idx = n-1;
    return helper(postorder, 0, n-1, idx);
  }
  TreeNode* helper(vector<int>& postorder, int left, int right, int& idx){
    if (left > right)
      return nullptr;
    
    int val = postorder[idx--];
    TreeNode* root = new TreeNode(val);
    int indexRoot = inOrderIdx[val];
    
    root -> right = helper(postorder, indexRoot + 1, right, idx);
    root -> left = helper(postorder, left, indexRoot - 1, idx);
    
    
    
    return root;
  }
};

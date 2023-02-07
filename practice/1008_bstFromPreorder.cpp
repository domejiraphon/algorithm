/*
1008. Construct Binary Search Tree from Preorder Traversal
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
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
  int preIdx=0;
public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n=preorder.size();
    map<int, int> index;
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    for (int i=0; i<n; i++)
      index[inorder[i]] = i;
    
    return helper(preorder, 0, preorder.size(), index);
  }
private:
  TreeNode* helper(vector<int>& preorder, int start, int end, map<int, int>& index){
    if (start == end)
      return nullptr; 
      
    int val = preorder[preIdx++];
    TreeNode* root = new TreeNode(val);
    int i = index[val];
    root -> left = helper(preorder, start, i, index);
    root -> right = helper(preorder, i + 1, end, index);
    return root;
  }
};

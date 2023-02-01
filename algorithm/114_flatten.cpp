/*
114. Flatten Binary Tree to Linked List
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
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
  void flatten(TreeNode* root) {
    helper(root);
  }
private:
  TreeNode* helper(TreeNode* root){
    if (!root)
      return root;
    if (!root -> left && !root -> right)
      return root;
    
    TreeNode* leftChild = helper(root -> left);
    TreeNode* rightChild = helper(root -> right);
    if (leftChild){
      leftChild -> right = root -> right;
      root -> right = root -> left;
      root -> left = nullptr;
    }
    
    return !rightChild ? leftChild : rightChild;
  }
};

class Solution {
public:
  void flatten(TreeNode* root) {
    root = helper(root);
  }
private:
  TreeNode* helper(TreeNode* root){
    if (!root)
      return root;
    if (!root -> left && !root -> right)
      return root;
    
    TreeNode* leftChild = helper(root -> left);
    TreeNode* rightChild = helper(root -> right);
    if (leftChild){
      root -> right = leftChild;
      root -> left = nullptr;
      TreeNode* cur = leftChild;
      while (cur && cur -> right)
        cur = cur -> right;
      cur -> right = rightChild;
    }
    
    return root;
  }
};
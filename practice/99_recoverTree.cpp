/*
99. Recover Binary Search Tree

You are given the root of a binary search tree (BST), 
where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.
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
  void recoverTree(TreeNode* root) {
    vector<TreeNode*> arr = inOrder(root);
    int n=arr.size();
    TreeNode* x=nullptr;
    TreeNode* y=nullptr;

    for (int i=0; i<n-1; i++){
      if (arr[i] -> val > arr[i+1] -> val){
        y = arr[i+1];
        if (!x)
          x = arr[i];
      }
    }
    int tmp = x -> val;
    x -> val = y -> val;
    y -> val = tmp;
  }
private:
  vector<TreeNode*> inOrder(TreeNode* root){
    if (!root)
      return vector<TreeNode*> {};

    vector<TreeNode*> left = inOrder(root -> left);
    left.push_back(root);
    vector<TreeNode*> right = inOrder(root -> right);
    left.insert(left.end(), right.begin(), right.end());

    return left;
  }
};
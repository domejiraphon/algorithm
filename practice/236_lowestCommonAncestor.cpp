/* 236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q 
as descendants (where we allow a node to be a descendant of itself).”
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
private:
  TreeNode* ans=nullptr;
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    helper(root, p, q);
    return ans;
  }
private:
  bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
    if (!root){return false;}
    
    int found1 = helper(root -> left, p, q) ? 1 : 0;
    int found2 = helper(root -> right, p, q) ? 1 : 0;
    int found3 = (root == p || root == q) ? 1 : 0;

    if (found1 + found2 + found3 >= 2){ans = root;}
    return (found1 + found2 + found3) > 0;
  }
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q){return root;}
    TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);
    if (left && right){return root;}
    else {return left ? left : right;}
  }
};
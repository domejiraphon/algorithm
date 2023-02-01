/* 
653. Two Sum IV - Input is a BST
Given the root of a binary search tree and an integer k, 
return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
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
  unordered_set<int> memo;
  int target;
public:
  bool findTarget(TreeNode* root, int k) {
    target = k;
    return traverse(root);
  }
private:
  bool traverse(TreeNode* root){
    if (!root)
      return false;
    bool out;
    if (memo.count(root -> val))
      out = true;
    else {
      memo.insert(target - root -> val);
      out = traverse(root -> left) || traverse(root -> right);
    }
    return out;

  }
};

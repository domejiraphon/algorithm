/*
337. House Robber III
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
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
  int rob(TreeNode* root) {
    vector<int> out = helper(root);
    return max(out[0], out[1]);
  }
private:
   vector<int> helper(TreeNode* root){
    if (!root){
      //rob this node, not rob this node;
      return {0, 0};
    }
    vector<int> left = helper(root -> left);
    vector<int> right = helper(root -> right);
    int notRob = max(left[0], left[1]) + max(right[0], right[1]);

    int rob = left[1] + right[1] + root -> val;
    return {rob, notRob};
  }
};

/*
437. Path Sum III
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
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
  unordered_map<long, int> map;
public:
  int pathSum(TreeNode* root, int targetSum) {
    int ans=0;
    map[0] = 1;
    helper(root, targetSum, 0, ans);
    return ans;
  }
private:
  void helper(TreeNode* root, int targetSum, long sum, int& ans){
    if (!root)
      return;
    sum += (long) root -> val;
    if (map.count(sum - targetSum))
      ans += map[sum - targetSum];
    map[sum]++;
    helper(root -> left, targetSum, sum, ans);
    helper(root -> right, targetSum, sum, ans);
    map[sum]--;
  }
};
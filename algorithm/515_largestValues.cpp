/*
515. Find Largest Value in Each Tree Row
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
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
  vector<int> largestValues(TreeNode* root) {
    if (!root)
      return {};
    queue<TreeNode*> Q;
    Q.push(root);
    vector<int> res;
    while (!Q.empty()){
      
      int len = Q.size();
      int val = Q.front() -> val;
      for (int i=0; i<len; i++){
        TreeNode* cur = Q.front();
        val = max(val, cur -> val);
        Q.pop();
        if (cur -> left)
          Q.push(cur -> left);
        if (cur -> right)
          Q.push(cur -> right);
      }
      res.push_back(val);
    }
    return res;
  }
};

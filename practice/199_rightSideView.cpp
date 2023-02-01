/*
199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.
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
  vector<int> res;
public:
  vector<int> rightSideView(TreeNode* root) {
    if (!root)
      return vector<int> {};
    vector<int> res;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()){
      int n=Q.size();
      for (int i=0; i<n; i++){
        TreeNode* cur = Q.front();
        Q.pop();
        if (cur -> left)
          Q.push(cur -> left);
        if (cur -> right)
          Q.push(cur -> right);
        if (i == n -1)
          res.push_back(cur -> val);
      }
    }
    return res;
  }
};
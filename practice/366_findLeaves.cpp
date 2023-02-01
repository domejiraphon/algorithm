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
  map<int, vector<int>> depth;
public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    findDepth(root);
    for (auto it=depth.begin(); it != depth.end(); it++){
      res.push_back(it -> second);
    }
    return res;
  }
private:
  int findDepth(TreeNode* root){
    if (!root){return 0;}
    int left = findDepth(root -> left);
    int right = findDepth(root -> right);
    int cur = 1 + max(left, right);
    depth[cur].push_back(root -> val);
    return cur;
  }
};
/* 314. Binary Tree Vertical Order Traversal
Given the root of a binary tree, return the vertical order traversal of its nodes' values. 
(i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.
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
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root){return res;}
    map<int, vector<int>> hash;
    queue<pair<TreeNode*, int>> Q;
    Q.push({root, 0});
    while (!Q.empty()){
      pair<TreeNode*, int> cur = Q.front();
      Q.pop();
      hash[cur.second].push_back(cur.first -> val);
      if (cur.first -> left){
        Q.push({cur.first -> left, cur.second - 1});
      }
      if (cur.first -> right){
        Q.push({cur.first -> right, cur.second + 1});
      }
    }
    
    for (auto it = hash.begin(); it != hash.end(); it++){
      res.push_back(it -> second);
    }
    return res;
  }
};
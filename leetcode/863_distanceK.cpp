/*
863. All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
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
 
class Solution {
  unordered_map<TreeNode*, TreeNode*> parents;
  unordered_set<TreeNode*> visited;
  vector<int> res;
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    getParents(nullptr, root);
    visited.insert(target);
    get(target, k);
    return res;
  }
private:
  void getParents(TreeNode* parent, TreeNode* root){
    if (!root)
      return;
    parents[root] = parent;
    getParents(root, root -> left);
    getParents(root, root -> right);
  }
  void get(TreeNode* target, int k){
    if (!target){return;}
    if (k == 0){
      res.push_back(target -> val); return;
    }
    if (!visited.count(target -> left)){
      visited.insert(target -> left);
      get(target -> left, k - 1);
    }

    if (!visited.count(target -> right)){
      visited.insert(target -> right);
      get(target -> right, k - 1);
    }

    if (!visited.count(parents[target])){
      visited.insert(parents[target]);
      get(parents[target], k - 1);
    }
  }
};
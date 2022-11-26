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
private:
  vector<int> res;
  unordered_map<TreeNode*, TreeNode*> parents;
  unordered_set<TreeNode*> seen;
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    DFS(root, nullptr);
    goUp(target, k);
    return res;
  }
private:
  void DFS(TreeNode* node, TreeNode* par){
    if (!node){return;}
    parents[node] = par;
    DFS(node -> left, node);
    DFS(node -> right, node);
  }
 
  void goUp(TreeNode* target, int k){
    if (k < 0 || !target){return;}
    if (k == 0){res.push_back(target -> val);}
    seen.insert(target);
    if (!seen.count(target -> left)){
      goUp(target -> left, k - 1);
    }
    
    if (!seen.count(target -> right)){
      goUp(target -> right, k - 1);
      
    }
    if (!seen.count(parents[target])){
      goUp(parents[target], k - 1);
      
    }
  }
};

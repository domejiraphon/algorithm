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
private:
  int depthFirst=-1;
  bool out = false;
public:
  bool isCousins(TreeNode* root, int x, int y) {
    getDepth(root, x, y, 0);
    return out;
    
  }
private:
  bool getDepth(TreeNode* root, int x, int y, int depth){
    if (!root){return false;}
    if (depthFirst != -1 && depth > depthFirst){return false;}
    if (root -> val == x || root -> val == y){
      if (depthFirst == -1){
        depthFirst = depth;
      }
      
      return depthFirst == depth;
    }
    bool left= getDepth(root -> left, x, y, depth + 1);
    bool right= getDepth(root -> right, x, y, depth + 1);
    if (left && right && depthFirst != depth + 1){
      out = true;
    }
    return left || right;
    
  }
};

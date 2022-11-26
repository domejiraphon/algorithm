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
  double maxAvg=0;
public:
  double maximumAverageSubtree(TreeNode* root) {
    sumCount(root);
    return maxAvg;
  }
private:
  pair<int, int> sumCount(TreeNode* root){
    if (!root){return {0, 0};}
    
    pair<int, int> leftChild = sumCount(root -> left);
    pair<int, int> rightChild = sumCount(root -> right);
    pair<int, int> cur = {leftChild.first + rightChild.first + root -> val, 
                         leftChild.second + rightChild.second + 1};
    double curAvg = (double) cur.first / cur.second;
    maxAvg = max(maxAvg, curAvg);
    return cur;
    
  }
};

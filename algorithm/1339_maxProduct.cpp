/*
1339. Maximum Product of Splitted Binary Tree

Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.
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
  int mod = pow(10, 9) + 7;
public:
  int maxProduct(TreeNode* root) {
    long val = sumAll(root);
    long maxProd = INT_MIN;
    sumPart(root, val, maxProd);
    return maxProd % mod;
  }
private:
  long sumAll(TreeNode* root){
    if (!root)
      return 0;
    return root -> val + sumAll(root -> left) + sumAll(root -> right);
  }
  int sumPart(TreeNode* root, long& val, long& maxProd){
    if (!root)
      return 0;
    
    int curSum = root -> val;
    curSum += sumPart(root -> left, val, maxProd);
    curSum += sumPart(root -> right, val, maxProd);
    maxProd = max(maxProd, ((long) (val - curSum) * curSum));
    return curSum;
  }
};

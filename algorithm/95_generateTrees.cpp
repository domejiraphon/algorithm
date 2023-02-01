/*
95. Unique Binary Search Trees II
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
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
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    res = helper(1, n);
    return res;
  }
private:
  vector<TreeNode*> helper(int start, int end){
    if (start > end)
      return vector<TreeNode*> {nullptr};

    vector<TreeNode*> res;
    for (int i=start; i<= end; i++){
      vector<TreeNode*> leftSub = helper(start, i-1);
      vector<TreeNode*> rightSub = helper(i+1, end);
      
      for (auto l: leftSub){
        for (auto r: rightSub){
          TreeNode* cur = new TreeNode(i);
          cur -> left =l;
          cur -> right = r;
          res.push_back(cur);
        }
      }
      
      
    }
    return res;
  }
};
/*
662. Maximum Width of Binary Tree
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
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
  int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, int>> Q;
    Q.push({root, 1});
    int maxWidth = 0;
    while (!Q.empty()){
      int len=Q.size();
      int start = Q.front().second;
      int end = Q.back().second;
      maxWidth = max(maxWidth, end - start + 1);
      for (int i=0; i<len; i++){
        pair<TreeNode*, long> cur = Q.front();
        int idx = cur.second - start;
        Q.pop();
        if (cur.first -> left)
          Q.push({cur.first -> left, (long long)2 * idx});
        if (cur.first -> right)
          Q.push({cur.first -> right, (long long)2 *  idx + 1});
      }
     
    }
    return maxWidth;
  }
};

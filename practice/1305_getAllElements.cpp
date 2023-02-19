/*
1305. All Elements in Two Binary Search Trees
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
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
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> res1, res2;
    inOrder(root1, res1);
    inOrder(root2, res2);
    int n=res1.size();
    int m=res2.size();
    int left=0, right=0;
    vector<int> res;
    while (left<n || right <m){
      if (left < n && right <m){
        if (res1[left] <= res2[right])
          res.push_back(res1[left++]);
        else
          res.push_back(res2[right++]);
      }
      else {
        if (left < n)
          res.push_back(res1[left++]);
        if (right < m)
          res.push_back(res2[right++]);
      }
    }
    return res;
  }
private:
  void inOrder(TreeNode* root, vector<int>& res){
    if (!root)
      return;
    inOrder(root -> left, res);
    res.push_back(root -> val);
    inOrder(root -> right, res);
  }
};

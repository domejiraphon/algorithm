/**
 * Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
 * For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) 
 * and (row + 1, col + 1) respectively. The root of the tree is at (0, 0). 
 * The vertical order traversal of a binary tree is a list of top-to-bottom orderings 
 * for each column index starting from the leftmost column and ending on the rightmost column. 
 * There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
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
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> res;
    if (!root){return res;}
    map<int, vector<int>> hash;
    queue<pair<TreeNode*, int>> Q;
    Q.push({root, 0});
    while (!Q.empty()){
      int n=Q.size();
      for (int i=0; i < n; i++){
        pair<TreeNode*, int> cur = Q.front();
        hash[cur.second].push_back(cur.first -> val);
        Q.pop();
        if (cur.first -> left){
          Q.push({cur.first -> left, cur.second - 1});
        }
        if (cur.first -> right){
          Q.push({cur.first -> right, cur.second + 1});
        }
      }
    }
    for (auto it=hash.begin(); it != hash.end(); it++){
      res.push_back(it -> second);
    }
    return res;
  }
};
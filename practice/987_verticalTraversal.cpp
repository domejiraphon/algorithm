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
bool sortby(pair<int, int> a, pair<int, int> b){
  return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
}
class Solution {
  map<int, vector<pair<int, int>>> memo;
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> res;
    DFS(root, 0, 0);
    for (auto it=memo.begin(); it != memo.end(); it++){
      vector<pair<int, int>> tmp = it -> second;
      sort(tmp.begin(), tmp.end(), sortby);
      vector<int> cur;
      for (auto pp: tmp)
        cur.push_back(pp.second);
      
      res.push_back(cur);
    }
    return res;
  }
private:
  void DFS(TreeNode* root, int x, int y){
    if (!root)
      return;
    memo[x].push_back({y, root -> val});
    DFS(root -> left, x - 1, y + 1);
    DFS(root -> right, x + 1, y + 1);
  }
};
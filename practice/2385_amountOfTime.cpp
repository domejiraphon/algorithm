/*
2385. Amount of Time for Binary Tree to Be Infected
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.


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
  int amountOfTime(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> parents;
    TreeNode* target = nullptr;

    getParents(root, nullptr, parents, target, start);
    queue<TreeNode*> Q;
    Q.push(target);
    int steps=-1;
    unordered_set<TreeNode*> seen = {target};
    while (!Q.empty()){
      int len = Q.size();
      for (int i=0; i<len; i++){
        TreeNode* cur = Q.front();
        Q.pop();
        if (cur -> left && !seen.count(cur -> left)){
          seen.insert(cur -> left);
          Q.push(cur -> left);
        }
        if (cur -> right && ! seen.count(cur -> right)){
          seen.insert(cur -> right);
          Q.push(cur -> right);
        }
       
        if (parents[cur] && !seen.count(parents[cur])){
          seen.insert(parents[cur]);
          Q.push(parents[cur]);
        }
      }
      cout << endl;
      steps++;
    }
    return steps;

  }
private:
  void getParents(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parents, TreeNode*& target, int start){
    if (!root)
      return;
    if (root -> val == start)
      target = root;
    parents[root] = parent;
    getParents(root -> left, root, parents, target, start);
    getParents(root -> right, root, parents, target, start);
  }
};

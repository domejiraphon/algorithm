/*
2096. Step-By-Step Directions From a Binary Tree Node to Another
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.
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
  unordered_map<TreeNode*, TreeNode*> parents;
  TreeNode* start;
  int startVal, n;
public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    startVal = startValue;
    getParents(root, nullptr); 
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    
    queue<pair<TreeNode*, string>> Q;
    
    Q.push({start, ""});
    visited[startValue] = true;
    while (!Q.empty()){
      int len = Q.size();
      for (int i=0; i<n; i++){
        pair<TreeNode*, string> cur = Q.front();
        
        Q.pop();
        if (cur.first -> val == destValue)
          return cur.second;
        int next;
        
        if (cur.first -> left){
          next = cur.first -> left -> val;
          if (!visited[next]){
            visited[next] = true;
            Q.push({cur.first -> left, cur.second + "L"});
          }
            
        }
          
        if (cur.first -> right){
          next = cur.first -> right -> val;
          if (!visited[next]){
            visited[next] = true;
            Q.push({cur.first -> right, cur.second + "R"});
          }
        }
          
        if (parents[cur.first]){
          next = parents[cur.first] -> val;
          if (!visited[next]){
            visited[next] = true;
            Q.push({parents[cur.first], cur.second + "U"});
          }
            
        }

      }
    }
    return "";
  }
private:
  void getParents(TreeNode* root, TreeNode* parent){
    if (!root)
      return;
    if (root -> val == startVal){
      start = root;
    }
      
    parents[root] = parent;
    n = max(n, root -> val);
    getParents(root -> left, root);
    getParents(root -> right, root);
  }


};

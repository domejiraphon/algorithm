#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
  if (!root)
    return nullptr;
  TreeNode *left_ptr = root -> left ? root -> left : nullptr;
  TreeNode *right_ptr = root -> right ? root -> right : nullptr;
  TreeNode * left_prune = prune(left_ptr);
  TreeNode * right_prune = prune(right_ptr);
  root -> left = left_prune;
  root -> right = right_prune;
  if (!left_prune && !right_prune && root -> val == 0)
    return nullptr;
  return root;
  }

  TreeNode* prune(TreeNode* head){
    if (!head)
      return nullptr;
    TreeNode *left_ptr = head -> left ? head -> left : nullptr;
    TreeNode *right_ptr = head -> right ? head -> right : nullptr;
    if (!left_ptr && !right_ptr && head -> val == 0){
      return nullptr;
    }
    else 
      return pruneTree(head);
    
  }



};

int main()
{ 
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node3 = new TreeNode(0);
  TreeNode* node4 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(0, node3, node4);
  
  
  Solution sol;
  TreeNode* out = sol.pruneTree(node1);
  cout << out -> val << endl;
  cout <<(out ->right) ->val << endl;

  return 0;
}
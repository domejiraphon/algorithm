#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void print(stack<TreeNode*> path){
  while (!path.empty()){
    cout << path.top() -> val << ", ";
    path.pop();
  }
  cout << endl;
}
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*> path;
    bool found(false);
    DFS(root, q, path, found);
    print(path);
    exit(0);
    return nullptr;
  }
private:
  void DFS(TreeNode* root, TreeNode* target, stack<TreeNode*>& path, bool& found){
    if (!root){return;}
    if (target == root){path.push(target); found = true; return;}
    path.push(root);
    DFS(root -> left, target, path, found);
    if (!found){
      
      DFS(root -> right, target, path, found);
      path.pop();
      //if (!found){path.pop();}
    }

  }
};

int main()
{ 
  
  TreeNode* node1_1 = new TreeNode(3);

  TreeNode* node2_1 = new TreeNode(5);
  TreeNode* node2_2 = new TreeNode(1);

  TreeNode* node3_1 = new TreeNode(6);
  TreeNode* node3_2 = new TreeNode(2);
  TreeNode* node3_3 = new TreeNode(0);
  TreeNode* node3_4 = new TreeNode(8);

  TreeNode* node4_1 = new TreeNode(7);
  TreeNode* node4_2 = new TreeNode(4);

  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_1 -> left = node3_1; node2_1 -> right = node3_2;
  node2_2 -> left = node3_3; node2_2 -> right = node3_4;
  node3_2 -> left = node4_1; node3_2 -> right = node4_2;
  Solution* sol;

  TreeNode* out;
  out = sol -> lowestCommonAncestor(node1_1, node4_1, node4_2);
  return 0;
}
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
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
  TreeNode* invertTree(TreeNode*& root) {
    if (!root){ return root;}
    TreeNode* tmp = root -> left ? root -> left : nullptr;
    root -> left = root -> right ? root -> right : nullptr;
    root -> right = tmp;
    invertTree(root -> left);
    invertTree(root -> right);
    return root;
  }

};

int main()
{ 
  Solution* sol;
  TreeNode* node1_1 = new TreeNode(4);
  TreeNode* node2_1 = new TreeNode(2);
  TreeNode* node2_2 = new TreeNode(7);
  TreeNode* node3_1 = new TreeNode(1);
  TreeNode* node3_2 = new TreeNode(3);
  TreeNode* node3_3 = new TreeNode(6);
  TreeNode* node3_4 = new TreeNode(9);

  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_1 -> left = node3_1; node2_1 -> right = node3_2;
  node2_2 -> left = node3_3; node2_2 -> right = node3_4;

  TreeNode* out = sol -> invertTree(node1_1);
  return 0;
}
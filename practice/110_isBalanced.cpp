#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

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
  bool isBalanced(TreeNode* root) {
    if (!root) {
      return true;
    }
    TreeNode* left_child = root -> left ? root -> left : nullptr;
    TreeNode* right_child = root -> right ? root -> right : nullptr;

    return isBalancedHelpper(left_child, right_child) &&
           isBalanced(left_child) &&
           isBalanced(right_child);

  }

  bool isBalancedHelpper(TreeNode* p, TreeNode* q) {
    if (abs(maxDepth(p) - maxDepth(q)) < 2){
      return true;
    }
    else {
      return false;
    }
  }
  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    TreeNode* left = root -> left ? root -> left : nullptr;
    TreeNode* right = root -> right ? root -> right : nullptr;
    return 1 + max(maxDepth(left), maxDepth(right));
  }
};

int main()
{ 
  TreeNode left1 = {3};
  TreeNode right1 = {4};
  TreeNode elem_left = {2, &left1, &right1};

  TreeNode left2 = {4};
  TreeNode right2 = {3};
  TreeNode elem_right = {2, &left2, &right2};

  TreeNode root = {1, &elem_left, &elem_right};
  Solution sol;
  
  cout << sol.isBalanced(&root) << endl;
  TreeNode root2 = {1, &elem_left, nullptr};
  cout << sol.isBalanced(&root2) << endl;

  return 0;
}
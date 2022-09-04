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
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return false;
    }
    int new_sum = targetSum - (root -> val);
    TreeNode* left = root -> left ? root -> left : nullptr;
    TreeNode* right = root -> right ? root -> right : nullptr;
    if (new_sum == 0 && ((!left) && (!right))) {
      return true;
    }
    else {
      return hasPathSum(left, new_sum) || hasPathSum(right, new_sum);
    }
  }
};

int main()
{ 
  TreeNode left3 = {7};
  TreeNode right3 = {2};
  TreeNode elem_left2 = {11, &left3, &right3};
  TreeNode elem_left = {4, &elem_left2, nullptr};

  TreeNode left3_1 = {1};
  TreeNode right2_1 = {4, nullptr, &left3_1};
  TreeNode left2_1 = {13};
  TreeNode elem_right = {8, &left2_1, &right2_1};

  TreeNode root = {5, &elem_left, &elem_right};
  Solution sol;
  
  cout << sol.hasPathSum(&root, 22) << endl;


  return 0;
}
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
  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }
    TreeNode* left_child = root -> left ? root -> left : nullptr;
    TreeNode* right_child = root -> right ? root -> right : nullptr;
    if (!left_child && !right_child){
      return true;
    }
    else if ((!left_child && right_child) || (left_child && !right_child)){
      return false;
    }
    else {
      if (left_child -> val == right_child -> val) {
      TreeNode* l_left_child = left_child -> left ? left_child -> left : nullptr;
      TreeNode* l_right_child = left_child -> right ? left_child -> right : nullptr;

      TreeNode* r_left_child = right_child -> left ? right_child -> left : nullptr;
      TreeNode* r_right_child = right_child -> right ? right_child -> right : nullptr;
      return isSymmetricHelper(l_left_child, r_right_child) && 
              isSymmetricHelper(l_right_child, r_left_child);
      }
      else {return false;}
    }
  }

  bool isSymmetricHelper(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }
    else if ((!p && q) || (p && !q)){
      return false;
    }
    if (p -> val == q -> val) {
      TreeNode* p_left = p -> left ? p -> left : nullptr;
      TreeNode* p_right = p -> right ? p -> right : nullptr;

      TreeNode* q_left = q -> left ? q -> left : nullptr;
      TreeNode* q_right = q -> right ? q -> right : nullptr;
      return isSymmetricHelper(p_left, q_right) && isSymmetricHelper(p_right, q_left);
    }
    else {
      return false;
    }
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
  
  cout << sol.isSymmetric(&root) << endl;


  return 0;
}
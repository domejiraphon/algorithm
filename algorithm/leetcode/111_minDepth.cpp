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
  int minDepth(TreeNode* root) {
  if (!root) {
    return 0;
  }
  TreeNode* left = root -> left ? root -> left : nullptr;
  TreeNode* right = root -> right ? root -> right : nullptr;
  if (minDepth(left) == 0 || minDepth(right) == 0){
    return 1+ max(minDepth(left), minDepth(right));
  }
  return 1 + min(minDepth(left), minDepth(right));
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
  
  cout << sol.minDepth(&root) << endl;


  return 0;
}
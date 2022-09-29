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
  bool isValidBST(TreeNode* root) {
    return helper(root, nullptr, nullptr);
  }
private:
  bool helper(TreeNode* root, TreeNode* low, TreeNode* high){
    if (!root){return true;}
   
    if ((low != nullptr && root->val <= low->val) ||
        (high != nullptr && root->val >= high->val)) {
        return false;
    }
    TreeNode* leftChild = root -> left ? root -> left : nullptr;
    TreeNode* rightChild = root -> right ? root -> right : nullptr;
    return helper(leftChild, low, root) && helper(rightChild, root, high);
   
  }
};

int main()
{ 
  
  Solution* sol;

  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(1);
  
  node1 -> left = node2; //node1 -> right = node3;
  cout << sol -> isValidBST(node1) << endl;

  TreeNode* node1_1 = new TreeNode(5);
  TreeNode* node2_1 = new TreeNode(4);
  TreeNode* node2_2 = new TreeNode(6);
  TreeNode* node3_1 = new TreeNode(3);
  TreeNode* node3_2 = new TreeNode(7);
  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_2 -> left = node3_1; node2_2 -> right = node3_2;

  cout << sol -> isValidBST(node1_1) << endl;
  

  return 0;
}
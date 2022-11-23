class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* prev=nullptr;
    while (root){
      if (p -> val >= root -> val){
        root = root -> right;
      }
      else{
        prev = root;
        root = root -> left;
      }
    }
    return prev;
  }
};

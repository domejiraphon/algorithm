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
  int diameterOfBinaryTree(TreeNode* root) {
    return DFS(root);
  }
private:
  int DFS(TreeNode* root){
    if (!root) {return 0;}
    TreeNode* leftChild = root -> left ? root -> left : nullptr;
    TreeNode* rightChild = root -> right ? root -> right : nullptr;

    int left = DFS(leftChild);
    int right = DFS(rightChild);

    return max(left, right) + 1;
  }
};

int main()
{ 
  
  Solution* sol;
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2_1 = new TreeNode(2);
  TreeNode* node2_2 = new TreeNode(3);
  TreeNode* node3_1 = new TreeNode(4);
  TreeNode* node3_2 = new TreeNode(5);

  node1 -> left = node2_1; node1 -> right = node2_2;
  node2_1 -> left = node3_1; node2_1 -> right = node3_2;
  cout << sol -> diameterOfBinaryTree(node1)<< endl;

  return 0;
}
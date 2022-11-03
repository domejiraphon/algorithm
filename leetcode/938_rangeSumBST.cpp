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
  int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root){return 0;}
    
    int sum = (root -> val >= low && root -> val <= high) ? root -> val : 0;
    if (low <= root -> val){
      sum += rangeSumBST(root -> left, low, high);
    }
    if (high >= root -> val){
      sum += rangeSumBST(root -> right, low, high);
    }
    return sum;
  }
};
int main()
{ 
  
  Solution* sol;

  TreeNode* node1 = new TreeNode(10);
  TreeNode* node2_1 = new TreeNode(5);
  TreeNode* node2_2 = new TreeNode(15);
  TreeNode* node3_1 = new TreeNode(3);
  TreeNode* node3_2 = new TreeNode(7);
  TreeNode* node3_3 = new TreeNode(18);
  
  node1 -> left = node2_1; node1 -> right = node2_2;
  node2_1 -> left = node3_1; node2_1 -> right = node3_2;
  node2_2 -> right = node3_3;

  cout << sol -> rangeSumBST(node1, 7, 15)<< endl;
  return 0;
}
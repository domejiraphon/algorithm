#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p -> val > root -> val && q -> val > root -> val){
      return lowestCommonAncestor(root -> right, p, q);
    } 
    else if (p -> val < root -> val && q -> val < root -> val){
      return lowestCommonAncestor(root -> left, p, q);
    } 
    else {
      return root;
    }
  }

};

int main()
{ 
  TreeNode* node1_1 = new TreeNode(6);

  TreeNode* node2_1 = new TreeNode(2);
  TreeNode* node2_2 = new TreeNode(8);

  TreeNode* node3_1 = new TreeNode(0);
  TreeNode* node3_2 = new TreeNode(4);
  TreeNode* node3_3 = new TreeNode(7);
  TreeNode* node3_4 = new TreeNode(9);

  TreeNode* node4_1 = new TreeNode(3);
  TreeNode* node4_2 = new TreeNode(5);
  
  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_1 -> left = node3_1; node2_1 -> right = node3_2;
  node2_2 -> left = node3_3; node2_2 -> right = node3_4;
  node3_2 -> left = node4_1; node3_2 -> right = node4_2;

  Solution* sol;
  TreeNode* out;
  out = sol -> lowestCommonAncestor(node1_1, node2_1, node2_2);
  return 0;
}
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
void print(vector<int> x){
  for (auto ele: x){
    cout << ele << ", ";
  }
  cout << endl;
}

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> out;
    helper(root, out, 0, 0);
    return out;
  }
private:
  void helper(TreeNode* root, vector<int>& out, int levelL, int levelR){
    if (!root){return;}
    if (levelR >= levelL){out.push_back(root -> val);}
    TreeNode* leftChild = root -> left ? root -> left : nullptr;
    TreeNode* rightChild = root -> right ? root -> right : nullptr;
    if (rightChild){
      helper(rightChild, out, levelL, levelR + 1);
    }
    if (leftChild){
      if (rightChild){
        helper(leftChild, out, levelL + 1, levelR + 1);
      }
      else {helper(leftChild, out, levelL + 1, levelR);}
    }
  }
};

int main()
{ 
  
  Solution* sol;
  vector<int> out;

  TreeNode* node1_1 = new TreeNode(1);
  TreeNode* node2_1 = new TreeNode(2);
  TreeNode* node2_2 = new TreeNode(3);
  TreeNode* node3_1 = new TreeNode(5);
  TreeNode* node3_2 = new TreeNode(4);

  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_1 -> right = node3_1; node2_2 -> right = node3_2;
  out = sol -> rightSideView(node1_1);
  print(out);
  return 0;
}
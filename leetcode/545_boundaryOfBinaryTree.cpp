#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<int> root){
  for (auto ele: root){
    cout << ele << ", ";
  }
  cout << endl;
}
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
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    if (!root){return vector<int> {};}
    vector<int> cur{root -> val};
    leftBoundary(root -> left, cur);
    leavesBoundary(root, cur);
    rightBoundary(root -> right, cur);
    print(cur); exit(0);
    return cur;
  }
private:
  void leftBoundary(TreeNode* root, vector<int>& cur){
    if (!root){return;}

    cur.push_back(root -> val);
    if (root -> left){leftBoundary(root -> left, cur);}
    else if (!(root -> left) && root -> right){
      leftBoundary(root -> right, cur);
    }
  }
  void leavesBoundary(TreeNode* root, vector<int>& cur){
    if (!root){return;}
    if (!(root -> left) && !(root -> right)){cur.push_back(root -> val); return;}
    leavesBoundary(root -> left, cur);
    leavesBoundary(root -> right, cur);
  }
  void rightBoundary(TreeNode* root, vector<int>& cur){
    if (!root){return;}
    
    if (root -> right){rightBoundary(root -> right, cur);}
    else if (!(root -> right) && root -> left){
      rightBoundary(root -> left, cur);
    }
    if (root -> left && root -> right){cur.push_back(root -> val); return;}
    
  }
};

int main()
{ 
  
  Solution* sol;

  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);
  
  node1 -> right = node2; node2 -> left = node3;
  node2 -> right = node4;

  vector<int> out;
  out = sol -> boundaryOfBinaryTree(node1);
  return 0;
}
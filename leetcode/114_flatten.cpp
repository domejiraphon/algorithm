#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void print(queue<TreeNode*> Q){
  while (!Q.empty()){
    cout << Q.front() -> val << ", ";
    Q.pop();
  }
  cout << endl;
}
void print(TreeNode* root){
  while (root){
    cout << root -> val << ", ";
    root = root -> right;
  }
  cout << endl;
}
class Solution {
public:
  void flatten(TreeNode* root) {
    if (!root){return;}
    queue<TreeNode*> Q;
    helper(root, Q);
   
    root = Q.front();
    Q.pop();
    while (!Q.empty()){
      TreeNode* cur = Q.front();
      root -> right = cur;
      root -> left = nullptr;
      root = cur;
      Q.pop();
    }
   
  }
private:
  void helper(TreeNode* root, queue<TreeNode*>& Q){
    if (!root){return;}
    Q.push(root);
    TreeNode* leftChild = root -> left ? root -> left : nullptr;
    TreeNode* rightChild = root -> right ? root -> right : nullptr;
    helper(leftChild, Q);
    helper(rightChild, Q);
  }
};

int main()
{ 
  
  Solution* sol;


  TreeNode* node1_1 = new TreeNode(1);
  TreeNode* node2_1 = new TreeNode(2);
  TreeNode* node2_2 = new TreeNode(5);
  TreeNode* node3_1 = new TreeNode(3);
  TreeNode* node3_2 = new TreeNode(4);
  TreeNode* node3_3 = new TreeNode(6);
  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_1 -> left = node3_1; node2_1 -> right = node3_2;
  node2_2 -> right = node3_3;

  sol -> flatten(node1_1);
  print(node1_1);

  return 0;
}
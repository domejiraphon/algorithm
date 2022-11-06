#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void print(vector<int> x){
  for (auto row: x){
    cout << row <<", ";
    
  }
  cout << endl;
}

class BSTIterator {
  vector<int> bst;
  int idx = 0;
  int size;
private:
  vector<int> inOrder(TreeNode* root){
    vector<int> out;
    if (!root){return out;}
    vector<int> leftSide = inOrder(root -> left);
    leftSide.push_back(root -> val);
    vector<int> rightSide = inOrder(root -> right);
    leftSide.insert(leftSide.end(), rightSide.begin(), rightSide.end());
    return leftSide;
  }
public:
  BSTIterator(TreeNode* root) {
    bst = inOrder(root);
    size = bst.size();
    print(bst);
  }
  
  int next() {
    return bst[idx++];
  }
  
  bool hasNext() {
    return (idx < (size - 1)) ? true : false;
  }
};

int main()
{ 
  TreeNode* root = new TreeNode(7);
  TreeNode* node2_1 = new TreeNode(3);
  TreeNode* node2_2 = new TreeNode(15);
  TreeNode* node3_1 = new TreeNode(9);
  TreeNode* node3_2 = new TreeNode(20);

  root -> left = node2_1; root -> right = node2_2;
  node2_2 -> left = node3_1; node2_2 -> right = node3_2;

  BSTIterator* it = new BSTIterator(root);

  return 0;
}
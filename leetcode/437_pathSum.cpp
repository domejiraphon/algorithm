#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <unordered_set>
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
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

class Solution {
public:
  int pathSum(TreeNode* root, int targetSum) {
    if (!root){return 0;}
    int count(0);
    vector<TreeNode*> cur;
    DFS(root, targetSum, count, 0);
    
    return count;
  }
private:
  void DFS(TreeNode* root, int targetSum, int& count, int sel){
    
    if (!root){return;}
    
    if (sel == 0){
      DFS(root -> left, targetSum, count, 0);
      DFS(root -> right, targetSum, count, 0);
      DFS(root, targetSum, count, 1);
    }
    else {
     
      if (targetSum == root ->val){count++; return;}
      else {
        DFS(root -> left, targetSum - root -> val, count, 1);
        DFS(root -> right, targetSum - root -> val, count, 1);
      }
     
    }
  }
};

int main()
{ 
  
  Solution* sol;
  TreeNode* node1 = new TreeNode(10);

  TreeNode* node2_1 = new TreeNode(5);
  TreeNode* node2_2 = new TreeNode(-3);

  TreeNode* node3_1 = new TreeNode(3);
  TreeNode* node3_2 = new TreeNode(2);
  TreeNode* node3_3 = new TreeNode(11);

  TreeNode* node4_1 = new TreeNode(3);
  TreeNode* node4_2 = new TreeNode(-2);
  TreeNode* node4_3 = new TreeNode(1);

  node1 ->left = node2_1; node1 -> right = node2_2;
  node2_1 -> left = node3_1; node2_1 -> right= node3_2;
  node3_1 -> left = node4_1; node3_1 -> right = node4_2;
  node2_2 -> right = node3_3; node3_2 ->right = node4_3;

  cout << sol ->pathSum(node1, 8)<< endl;
  TreeNode* node11 = new TreeNode(1);

  TreeNode* node21_1 = new TreeNode(2);
  TreeNode* node21_2 = new TreeNode(3);
  //node11 ->left = node21_1; node21_1 -> right = node21_2;
  cout << sol ->pathSum(node1, 0)<< endl;
  return 0;
}
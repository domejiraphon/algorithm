#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void print(vector<vector<int>> path){
  for (auto ele: path){
    for (auto x: ele){
      cout << x << ", ";
    }
    cout << endl;
  }
  cout << endl;
}
void print(vector<int> path){
  for (auto ele: path){
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
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> cur;
    findAll(res, cur, root, targetSum);
    return res;
  }
private:
  void findAll(vector<vector<int>>& res, vector<int>& cur, TreeNode* root, int targetSum){
    if (!root) {return;}
    TreeNode* leftChild = root -> left ? root -> left : nullptr;
    TreeNode* rightChild = root -> right ? root -> right : nullptr;
    cur.push_back(root -> val);
    targetSum -= root -> val;
    if (!leftChild && !rightChild){
      if (targetSum == 0){
        
        res.push_back(cur);
      }
      return;
    }
    
    if (leftChild){
      findAll(res, cur, leftChild, targetSum);
      cur.pop_back();
    }
    if (rightChild){
      
      findAll(res, cur, rightChild, targetSum);
      cur.pop_back();
    }
  }
};

int main()
{
  Solution* sol;
  TreeNode* node1_1 = new TreeNode(5);
  TreeNode* node2_1 = new TreeNode(4);
  TreeNode* node2_2 = new TreeNode(8);

  TreeNode* node3_1 = new TreeNode(11);
  TreeNode* node3_2 = new TreeNode(13);
  TreeNode* node3_3 = new TreeNode(4);

  TreeNode* node4_1 = new TreeNode(7);
  TreeNode* node4_2 = new TreeNode(2);
  TreeNode* node4_3 = new TreeNode(5);
  TreeNode* node4_4 = new TreeNode(1);

  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_1 -> left = node3_1; 
  node2_2 -> left = node3_2; node2_2 -> right = node3_3;

  node3_1 -> left = node4_1; node3_1 -> right = node4_2;
  node3_3 -> left = node4_3; node3_3 -> right = node4_4;

  vector<vector<int>> out = sol -> pathSum(node1_1, 22);
  print(out);
 
  TreeNode* node1_1_1 = new TreeNode(1);
  TreeNode* node2_1_1 = new TreeNode(2);
  node1_1_1 -> left = node2_1_1; 
  out = sol -> pathSum(node1_1_1, 3);
  //print(out);

  return 0;
}
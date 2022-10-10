#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <vector>
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

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> out;
    if (!root) {return out;}
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()){
      vector<int> cur;
      int n = Q.size();
      for (int i=0; i < n; i++){
        TreeNode* head = Q.front();
        cur.push_back(head -> val);
        Q.pop();
        TreeNode* leftChild = head -> left ? head -> left : nullptr;
        TreeNode* rightChild = head -> right ? head -> right : nullptr;
        if (leftChild){
          Q.push(leftChild);
        }
        if (rightChild){
          Q.push(rightChild);
        }
      }
      out.push_back(cur);
    }
    return out;
  }
};

int main()
{ 
  TreeNode* node1 = new TreeNode(3);
  TreeNode* node2_1 = new TreeNode(9);
  TreeNode* node2_2 = new TreeNode(20);
  TreeNode* node3_1 = new TreeNode(15);
  TreeNode* node3_2 = new TreeNode(17);
  Solution* sol;
  
  node1 -> left = node2_1; node1 -> right = node2_2;
  node2_2 -> left = node3_1; node2_2 -> right = node3_2;

  vector<vector<int>> out;
  out = sol -> levelOrder(node1);
  print(out);
  return 0;
}
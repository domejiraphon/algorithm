#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}

void print(vector<int> x){
 
    for (auto elem: x){
      cout << elem <<", ";}
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
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> out;

    vector<int> res;
    //cout <<(!root)<<endl; 
    DFS(root, root, res);
    DFS(root, root, res);
    DFS(root, root, res);
    DFS(root, root, res);
    DFS(root, root, res);
    DFS(root, root, res);
    DFS(root, root, res);
    DFS(root, root, res);
     exit(0);
    cout <<(!root)<<endl; 
    cout <<(!root -> left)<<endl; 
    exit(0);
    out.push_back(res);

    cout <<(!root)<<endl; 
  
    exit(0);
    /*
    while (root){
      vector<int> res;
      DFS(root, res);
      print(res);
      out.push_back(res);
    }*/
    return out;
  }
  

  void DFS(TreeNode* head, TreeNode*& parent, vector<int>& res){
    if (!head) {return;}
    TreeNode* leftChild = head -> left ? head -> left : nullptr;
    TreeNode* rightChild = head -> right ? head -> right : nullptr;
    if (!leftChild && !rightChild){
      res.push_back(head -> val);
      parent -> left = nullptr; parent -> right = nullptr;}
    DFS(leftChild, parent, res); DFS(rightChild, parent, res);
    //cout <<(!head)<< endl;
    if (parent){
      cout << parent -> val << endl;
      cout << !parent -> left<< endl;
    }
  }
};
int main()
{ 
  TreeNode* root = new TreeNode(10);
  TreeNode* node1_0 = new TreeNode(2);
  TreeNode* node1_1 = new TreeNode(3);

  TreeNode* node2_0 = new TreeNode(4);
  TreeNode* node2_1 = new TreeNode(5);

  root -> left = node1_0; root -> right = node1_1;
  node1_0 -> left = node2_0; node1_0 -> right = node2_1;
  Solution sol;
 
  vector<vector<int>> out;
 
  out = sol.findLeaves(root);
  print(out);

  return 0;
}
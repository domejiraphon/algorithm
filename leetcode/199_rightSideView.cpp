#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <cmath>
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
void print(vector<vector<pair<int, int>>> x){
  for (auto ele: x){
    for (auto y: ele){
      cout << "("<<y.first <<", "<<y.second<< ")";
      cout << ", ";
    }
    cout << endl;
  }
  cout << endl;
}
void print(vector<int> x){
  
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
  
}

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    if (!root){return vector<int> {};}
    vector<int> cur;
    BFS(root, cur);
    return cur;
  }
private:
  void BFS(TreeNode* root, vector<int>& val){
    if (!root){return;}
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()){
      int n=Q.size();
      for (int i=0; i<n; i++){
        TreeNode* head = Q.front();
        if (i == (n-1)){val.push_back(head -> val);}
        Q.pop();
        if (head -> left){
          Q.push(head -> left);
        }
        if (head -> right){
          Q.push(head -> right);
        }
      }
    
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
  TreeNode* node3_2 = new TreeNode(6);

  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_1 -> right = node3_1; node2_2 -> left = node3_2;
  out = sol -> rightSideView(node1_1);
  print(out);
  return 0;
}
#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void print(unordered_map<TreeNode*, bool> x){
  for(auto it= x.begin(); it != x.end(); it++){
    cout << it -> first<< ",  "<<it -> second << endl;
  }
}

void print(vector<int> x){
 
    for (auto elem: x){
      cout << elem <<", ";}
    cout << endl;

}
void print(vector<vector<int>> in){
  for (auto x: in){
    for (auto elem: x){
      cout << elem <<", ";}
    cout << endl;
  }
    

}
class Solution {
public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    getHeight(root, res);
    
    return res;
  }
private:
  int getHeight(TreeNode* root, vector<vector<int>>& res){
    if (!root){return -1;}
    int leftHeight = getHeight(root -> left, res);
    int rightHeight = getHeight(root -> right, res);
    int out = 1 + max(leftHeight, rightHeight);
    if (out == res.size()){
      res.push_back({});
    }
    res[out].push_back(root -> val);
    return out;
  }
};

class Solution2 {
public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    map<int, vector<int>> res;
    getHeight(root, res);
    vector<vector<int>> out;
    for (auto it=res.begin(); it != res.end(); it++){
      out.push_back(it -> second);
    }
    return out;
  }
private:
  int getHeight(TreeNode* root, map<int, vector<int>>& res){
    if (!root){return -1;}
    int leftHeight = getHeight(root -> left, res);
    int rightHeight = getHeight(root -> right, res);
    int out = 1 + max(leftHeight, rightHeight);
    res[out].push_back(root -> val);
    return out;
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
 
  //out = sol.findLeaves(root);
  
  print(out);

  TreeNode* r = new TreeNode(1);
  TreeNode* r2 = new TreeNode(2);
  r -> left = r2;
  out = sol.findLeaves(r);
  
  print(out);
  return 0;
}
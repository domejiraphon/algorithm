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
    vector<vector<int>> out;
    if (!root){return out;}
    unordered_map<TreeNode*, bool> seen;
    while (root){
      vector<int> res;
      DFS(root, res, seen);

      exit(0);
      out.push_back(res);
      bool allSeen=true;
      for(auto it= seen.begin(); it != seen.end(); it++){
        if (!it -> first) {continue;}
        allSeen = allSeen && it -> second;
      }
      if (allSeen){break;}
      
    }
    //out.push_back(vector<int> {root -> val});
    return out;
  }
  

  void DFS(TreeNode* head, vector<int>& res, unordered_map<TreeNode*, bool>& seen){
    if (!head) {return;}
    if (head && seen.find(head) == seen.end()){seen[head] = false;}
    if (seen[head]) {return;}
    TreeNode* leftChild = head -> left ? head -> left : nullptr;
    TreeNode* rightChild = head -> right ? head -> right : nullptr;
    if ((seen[leftChild] && seen[rightChild]) 
        || (!leftChild && !rightChild)){
      res.push_back(head -> val);
      seen[head] = true; return;}
    DFS(leftChild, res, seen); 
    DFS(rightChild, res, seen);
    print(seen); exit(0);

  
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
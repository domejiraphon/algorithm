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
void print(deque<TreeNode*> x){
  for (auto row: x){
    cout << row -> val <<", ";
    
  }
  cout << endl;
}

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> out;
    if (!root){return out;}
    queue<TreeNode*> Q;
    Q.push(root);
    int level(0);
    while (!Q.empty()){
      int n=Q.size();
      vector<int> cur(n);
     
      for (int i=0 ; i< n; i++){
        TreeNode* curNode;
       
        curNode = Q.front();
        Q.pop();
      
        if (curNode -> left){Q.push(curNode -> left);}
        if (curNode -> right){Q.push(curNode -> right);}
        if (level %2 != 0){
          cur[n-i-1] = curNode -> val;
        }
        else {
          cur[i] = curNode -> val;
        }
       
      }
      out.push_back(cur);
      level++;
    }
    return out;
  }
};

int main()
{ 
  
  Solution* sol;
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);
  TreeNode* node5 = new TreeNode(5);
  node1 -> left = node2; node1 -> right = node3;
  node2 -> left = node4; node3 -> right = node5;
  vector<vector<int>> out;

  out = sol -> zigzagLevelOrder(node1);
  print(out);

  return 0;
}
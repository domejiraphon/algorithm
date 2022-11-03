#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
template <typename T>
void print(const vector<vector<T>> & vec)
{
    for(auto ele : vec)
    {
      for (auto x: ele){
        cout << x << ", ";
      }
      cout <<endl;
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
class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root){return res;}
    queue<pair<TreeNode*, int>> Q;
    map<int, vector<int>> M;

    Q.push({root, 0});
    
    while (!Q.empty()){
      int n = Q.size();
      for (int i=0; i< n; i++){
        pair<TreeNode*, int> nodeCol = Q.front();
        Q.pop();

        M[nodeCol.second].push_back(nodeCol.first -> val);
        if (nodeCol.first -> left){
          Q.push({nodeCol.first -> left, nodeCol.second - 1});
        }
        if (nodeCol.first -> right){
          Q.push({nodeCol.first -> right, nodeCol.second + 1});
        }
        
      }
    }
    for (auto it = M.begin(); it != M.end(); it++){
      res.push_back(it -> second);
    }
    return res;
  }
};

int main()
{ 
  Solution* sol;
  TreeNode* node1_1 = new TreeNode(3);

  TreeNode* node2_1 = new TreeNode(9);
  TreeNode* node2_2 = new TreeNode(20);

  TreeNode* node3_1 = new TreeNode(15);
  TreeNode* node3_2 = new TreeNode(7);

  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_2 -> left = node3_1; node2_2 -> right = node3_2;


  vector<vector<int>> out;
  out = sol -> verticalOrder(node1_1);
  print(out);
  return 0;
}
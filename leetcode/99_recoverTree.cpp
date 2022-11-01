#include <iostream>
#include <iterator>
#include <map>
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

class Solution {
public:
  void recoverTree(TreeNode* root) {
    vector<pair<int, TreeNode*>> out = inOrder(root);
    int n=out.size();
    for (int i=0; i < n; i++){
      cout << out[i].first << endl;
    }
    exit(0);
    for (int i=0; i < n - 1; i++){
      if (out[i].first > out[i + 1].first){
        int tmp = out[i].first;
        out[i].second -> val = out[i + 1].first;
        out[i + 1].second -> val = tmp;
        break;
      }
    }
  }
private:
  vector<pair<int, TreeNode*>> inOrder(TreeNode* root){
    if (!root){return vector<pair<int, TreeNode*>> {};}
    vector<pair<int, TreeNode*>> left = inOrder(root -> left);
    left.push_back({root -> val, root});
    vector<pair<int, TreeNode*>> right = inOrder(root -> right);
    left.insert(left.end(), right.begin(), right.end());
    return left;
  }
};

int main()
{ 
  
  Solution* sol;

  TreeNode* node1 = new TreeNode(3);
  TreeNode* node2_1 = new TreeNode(1);
  TreeNode* node2_2 = new TreeNode(4);
  TreeNode* node3 = new TreeNode(2);
  
  node1 -> left = node2_1; node1 -> right = node2_2;
  node2_2 -> left = node3;

  sol -> recoverTree(node1);
  cout << node1 -> val << endl;
  cout << node3 -> val << endl;
  return 0;
}
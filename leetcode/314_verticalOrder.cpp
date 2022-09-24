#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
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
    getX(root, res, 0, 0);
  
    map<int, vector<vector<int>>> hash;
    for (int i=0; i < res.size(); i++){
      hash[res[i][0]].push_back(vector<int> {res[i][1], res[i][2]});
    }
    res.clear();
    for (auto it=hash.begin(); it != hash.end(); it++){
      vector<vector<int>> cur = it -> second;
      sort(cur.begin(), cur.end());
      vector<int> x;
      for (auto ele: cur){
        x.push_back(ele[1]);
      }
      res.push_back(x);
    }
    return res;
  }
private:
  void getX(TreeNode* root, vector<vector<int>>& res, int x, int y){
    if (!root) {return;}
    vector<int> cur = {x, y, root -> val};
    res.push_back(cur);
    TreeNode* leftChild = root -> left ? root -> left : nullptr;
    if (leftChild){
      getX(leftChild, res, x - 1, y + 1);
    }
    TreeNode* rightChild = root -> right ? root -> right : nullptr;
    if (rightChild){
      getX(rightChild, res, x + 1, y + 1);
    }
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
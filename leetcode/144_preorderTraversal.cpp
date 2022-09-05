#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
template <typename T>
void print_vector(const std::vector<T> & vec, std::string sep=", ")
{
    for(auto elem : vec)
    {
        std::cout<<elem<< sep;
    }
    std::cout<<std::endl;
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
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root){
      vector<int> out {};
      return out;
    }
    vector<int> out;
    TreeNode* left = root -> left ? root -> left : nullptr;
    TreeNode* right = root -> right ? root -> right : nullptr;
    if (left){
      vector<int> out_left;
      out_left = inorderTraversal(left);
      out.insert(out.end(), out_left.begin(), out_left.end());
    }
    if (right){
      vector<int> out_right;
      out_right = inorderTraversal(right);
      out.insert(out.end(), out_right.begin(), out_right.end());
    }
    out.push_back(root -> val);
    return out;
  }
};

int main()
{ 
  TreeNode left = {1};
  TreeNode right = {3};
  TreeNode elem = {2, &left, &right};
  Solution sol;
  TreeNode* root = &elem;

  vector<int> out;
  out = sol.inorderTraversal(root);
  print_vector(out);
  
  root = {};
  out = sol.inorderTraversal(root);
  print_vector(out);

  return 0;
}
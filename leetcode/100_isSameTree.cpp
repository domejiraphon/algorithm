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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }
    else if ((!p && q) || (p && !q)){
      return false;
    }
    if (p -> val == q -> val) {
      TreeNode* p_left = p -> left ? p -> left : nullptr;
      TreeNode* p_right = p -> right ? p -> right : nullptr;

      TreeNode* q_left = q -> left ? q -> left : nullptr;
      TreeNode* q_right = q -> right ? q -> right : nullptr;
      return isSameTree(p_left, q_left) && isSameTree(p_right, q_right);
    }
    else {
      return false;
    }
  }
};

int main()
{ 
  TreeNode left = {1};
  TreeNode right = {3};
  TreeNode elem = {2, &left, &right};
  Solution sol;
  TreeNode* root = &elem;

  cout << sol.isSameTree(root, root) << endl;
  TreeNode root2 = {1};
  cout << sol.isSameTree(root, &root2) << endl;


  return 0;
}
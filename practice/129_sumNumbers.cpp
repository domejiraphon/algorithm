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
void print(const std::vector<int> & vec, std::string sep=", ")
{
    for(auto elem : vec)
    {
        std::cout<<elem<< sep;
    }
    std::cout<<std::endl;
}

class Solution {
public:
  int sumNumbers(TreeNode* root) {
    int count(0);
    path(root, 0, count);
    return count;
  }
private:
  void path(TreeNode* root, int cur, int & count){
    if (!root){return;}
   
    cur += root -> val;
    
    if (!root -> left && !root -> right){count += cur;}
    else {path(root -> left, 10 * cur, res);
    path(root -> right, 10 * cur, res);}
   
   
  }
};

int main()
{ 
  
  Solution* sol;

  TreeNode* node1 = new TreeNode(4);
  TreeNode* node2_1 = new TreeNode(9);
  TreeNode* node2_2 = new TreeNode(0);
  TreeNode* node3_1 = new TreeNode(5);
  TreeNode* node3_2 = new TreeNode(1);
  
  node1 -> left = node2_1; node1 -> right = node2_2;
  node2_1 -> left = node3_1; node2_1 -> right = node3_2;
  

  cout << sol -> sumNumbers(node1) << endl;
  return 0;
}
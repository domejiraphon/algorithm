#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <sstream>  // for string streams
#include <string> 
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
  string tree2str(TreeNode* head){
    if (!head) {return "";}
    TreeNode* left = head -> left ? head -> left : nullptr;
    TreeNode* right = head -> right ? head -> right : nullptr;
    ostringstream str1; str1 << head -> val;
    string head_val = str1.str();
    if (!left && !right){
      return head_val;
    }
    else if (left && !right){
      return head_val + "(" + tree2str(left) + ")";
    }
    else if (!left && right){
      return head_val + "()" + "(" +tree2str(right)+")";
    }
    else {
      return head_val + "(" + tree2str(left)+")" +"("+tree2str(right)+")";
    }
  }
};

int main()
{ 
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);

  node1 -> left = node2; node1 -> right = node3;
  node2 -> left = node4;

  Solution sol;
 
  cout<< sol.tree2str(node1)<< endl;
  
  return 0;
}
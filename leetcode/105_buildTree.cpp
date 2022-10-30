#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <tuple>

using namespace std;
void print(const std::vector<int> & vec, std::string sep=", ")
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() == 0){return nullptr;}
    TreeNode* head = new TreeNode(preorder[0]);
    if (preorder.size() == 1 && inorder.size() == 1){return head;}
    int n =inorder.size();
    int idx;
    for (int i=0; i< n; i++){
      if (inorder[i] == preorder[0]){
        idx = i; break;
      }
    }
    

    vector<int> leftPreOrder = {preorder.begin() + 1, preorder.begin() + idx + 1};
    vector<int> leftInOrder = {inorder.begin(), inorder.begin() + idx};
   
    TreeNode* leftChild = buildTree(leftPreOrder, leftInOrder);
  
    vector<int> rightPreOrder = {preorder.begin() + idx + 1, preorder.end()};
    vector<int> rightInOrder = {inorder.begin() + idx + 1, inorder.end()};
    TreeNode* rightChild = buildTree(rightPreOrder, rightInOrder);
    head -> left = leftChild; head -> right = rightChild;
    return head;

  }
};
int main()
{ 
  Solution* sol;
  vector<int> preorder = {1,2, 3};
  vector<int> inorder = {3,2,1};
  TreeNode* out = sol -> buildTree(preorder, inorder);
  return 0;
}
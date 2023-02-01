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
  vector<TreeNode*> allPossibleFBT(int n) {
    if (n % 2 == 0){return vector<TreeNode*> {};}
    vector<vector<TreeNode*>> tree;
    tree.push_back(vector<TreeNode*> {nullptr});

    TreeNode* cur = new TreeNode();
    tree.push_back(vector<TreeNode*> {cur});

    for (int i=2; i <= n; i++){
      vector<TreeNode*> cur;
      for (int j=1; j < i; j += 2){
        for (int k=0; k < tree[i - j - 1].size(); k++){
          for (int l=0; l < tree[j].size(); l++){
            TreeNode* head = new TreeNode();
            head -> left = tree[i - j - 1][k];
            head -> right = tree[j][l];
            cur.push_back(head);
          }
        }
      }
      tree.push_back(cur);
    }
    return tree[n];
  }
};

int main()
{ 
 
  Solution* sol;
 

  vector<TreeNode*> out;
  out = sol -> allPossibleFBT(7);

  return 0;
}
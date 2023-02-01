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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
  if (nums.size() == 0){
    TreeNode* out = nullptr;
    return out;
  }
  else if (nums.size() == 1){
    TreeNode* out = new TreeNode(nums[0]);
    return out;
  }
  int median = nums[(int) nums.size() / 2];
  vector<int> left = {nums.begin(), nums.begin()+(int) nums.size() / 2};
  vector<int> right = {nums.begin()+(int) nums.size() / 2+1, nums.end()};
  TreeNode* out = new TreeNode(median, 
                      sortedArrayToBST(left), 
                      sortedArrayToBST(right)); 
  return out ;
  }
};

int main()
{ 
  vector<int> nums={-10,-3,0,5,9};
  Solution sol;
  TreeNode* out;
  out = sol.sortedArrayToBST(nums);


  return 0;
}
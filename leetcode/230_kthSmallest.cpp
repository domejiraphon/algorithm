#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Compare{
public:
  bool operator() (int a, int b){
    return a > b;
  }
};

class Solution2 {
public:
  int kthSmallest(TreeNode* root, int k) {
    priority_queue<int, vector<int>, Compare> minHeap;
    retrieve(root, minHeap);
    int top ;
    
    while (k > 0){
      top = minHeap.top();
      minHeap.pop();
      k--;
    }
    return top;
  }
private:
  void retrieve(TreeNode* root, priority_queue<int, vector<int>, Compare>& minHeap){
    if (!root){return;}
    minHeap.push(root -> val);
    TreeNode* leftChild = root -> left ? root -> left : nullptr;
    TreeNode* rightChild = root -> right ? root -> right : nullptr;
    retrieve(leftChild, minHeap);
    retrieve(rightChild, minHeap);
  }
};

class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    vector<int> element;
    element = retrieve(root);

    return element[k - 1];
  }
private:
  vector<int> retrieve(TreeNode* root){
    if (!root){return vector<int> {};}
    TreeNode* leftChild = root -> left ? root -> left : nullptr;
    TreeNode* rightChild = root -> right ? root -> right : nullptr;
    vector<int> out = retrieve(leftChild);
    out.push_back(root -> val);
    vector<int> right = retrieve(rightChild);
    out.insert(out.end(), right.begin(), right.end());
    return out;
  }
};

int main()
{ 
  Solution* sol;
  TreeNode* node1_1 = new TreeNode(3);
  TreeNode* node2_1 = new TreeNode(1);
  TreeNode* node2_2 = new TreeNode(4);
  TreeNode* node3_1 = new TreeNode(2);
 

  node1_1 -> left = node2_1; node1_1 -> right = node2_2;
  node2_1 -> right = node3_1;
  

  cout << sol -> kthSmallest(node1_1, 2) << endl;
  return 0;
}
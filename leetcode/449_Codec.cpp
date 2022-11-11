/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string out="";
    postOrder(root, out);
    if (out.size() > 0){
      out = out.substr(0, out.size() - 1);
    }
    
    return out;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.size() == 0){return nullptr;}
    
    int pos;
    stringstream ss(data);
    string val;
    vector<int> nums;
    while (getline (ss, val, ',')){
      nums.push_back(stoi(val));
    }
    
    return insert(INT_MIN, INT_MAX, nums);
  }
private:
  void postOrder(TreeNode* root, string& sb){
    if (!root){return ;}
    postOrder(root -> left, sb);
    postOrder(root -> right, sb);
    sb += to_string(root -> val) + ",";
  }
  TreeNode* insert(int low, int high, vector<int> nums){
    if (nums.size() == 0){return nullptr;}
    int cur = nums.back();
    if (cur < low || cur > high){return nullptr;}
    nums.pop_back();
    TreeNode* root = new TreeNode(cur);
    root -> right = insert(cur, high, nums);
    root -> left = insert(low, cur, nums);
    return root;
    
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
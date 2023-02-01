/*
297. Serialize and Deserialize Binary Tree
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
*/
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
    cout << serializeHelper(root); 
    return serializeHelper(root);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    queue<string> val = convert(data);
    int i=0;
    int n=val.size();
    return deserializeHelper(val);
  }

  string serializeHelper(TreeNode* root){
    if (!root)
      return "n";
    string out = to_string(root -> val)+",";
    out += serializeHelper(root -> left)+",";
    out += serializeHelper(root -> right);
    return out;
  }

  TreeNode* deserializeHelper(queue<string>& val){
    if (val.empty())
      return nullptr;
    string cur = val.front();
    val.pop();
    if (cur == "n")
      return nullptr;
    TreeNode* root = new TreeNode(stoi(cur));
    root -> left = deserializeHelper(val);
    root -> right = deserializeHelper(val);
    return root;
  }
  queue<string> convert(string& data){
    queue<string> res;
    int n=data.size();
    string cur="";
    for (int i=0; i<n; i++){
      if (data[i] == ','){
        res.push(cur);
        cur = "";
      }
      else
        cur += data[i];
    }
    return res;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
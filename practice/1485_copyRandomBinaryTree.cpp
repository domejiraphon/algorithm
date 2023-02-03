/*
1485. Clone Binary Tree With Random Pointer
A binary tree is given such that each node contains an additional random pointer which could point to any node in the tree or null.

Return a deep copy of the tree.

The tree is represented in the same input/output way as normal binary trees where each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (in the input) where the random pointer points to, or null if it does not point to any node.
You will be given the tree in class Node and you should return the cloned tree in class NodeCopy. NodeCopy class is just a clone of Node class with the same attributes and constructors.
*/
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
  NodeCopy* copyRandomBinaryTree(Node* root) {
    unordered_map<Node*, NodeCopy*> map;
    unordered_set<Node*> seen;
    dfs(root, map);
    seen.insert(root);
    helper(root, map, seen);
    return map[root];
  }
private:
  void dfs(Node* cur, unordered_map<Node*, NodeCopy*>& map){
    if (!cur || map.count(cur))
      return;
    if (!map.count(cur)){
      NodeCopy* newNode = new NodeCopy(cur -> val);
      map[cur] = newNode;
    }
    
    dfs(cur -> random, map);
    dfs(cur -> right, map);
    dfs(cur -> left, map);
  }
  void helper(Node* cur, unordered_map<Node*, NodeCopy*>& map, unordered_set<Node*>& seen){
    if (!cur)
      return;
    if (cur -> left)
      map[cur] -> left = map[cur -> left];
    if (cur -> right)
      map[cur] -> right = map[cur -> right];
    if (cur -> random)
      map[cur] -> random = map[cur -> random];
    if (!seen.count(cur -> left)){
      seen.insert(cur -> left);
      helper(cur -> left, map, seen);
    }
    if (!seen.count(cur -> right)){
      seen.insert(cur -> right);
      helper(cur -> right, map, seen);
    }
    if (!seen.count(cur -> random)){
      seen.insert(cur -> random);
      helper(cur -> random, map, seen);
    }
  }
};

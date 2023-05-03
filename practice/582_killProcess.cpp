/*
582. Kill Process
You have n processes forming a rooted tree structure. You are given two integer arrays pid and ppid, where pid[i] is the ID of the ith process and ppid[i] is the ID of the ith process's parent process.

Each process has only one parent process but may have multiple children processes. Only one process has ppid[i] = 0, which means this process has no parent process (the root of the tree).

When a process is killed, all of its children processes will also be killed.

Given an integer kill representing the ID of a process you want to kill, return a list of the IDs of the processes that will be killed. You may return the answer in any order.
*/
struct Node {
  int val;
  Node(int p){
    val = p;
  }
  vector<Node *> children;
};

class Solution {
public:
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    unordered_map<int, Node *> cache;
    int n=pid.size();
    Node *root;
    for (int i=0; i<n; i++){
      Node *parent;
     if (ppid[i] != 0){
       if (cache.count(ppid[i]))
        parent = cache[ppid[i]];
      else{
        parent = new Node(ppid[i]);
        cache[ppid[i]] = parent;
      }
     }
      
      
      Node *child;
      if (cache.count(pid[i]))
        child = cache[pid[i]];
      else {
        child = new Node(pid[i]);
        cache[pid[i]] = child;
      }
      if (ppid[i] == 0){
        root = child;
        continue;
      }
      parent -> children.push_back(child);
    }
    unordered_set<int> visited;
    vector<int> res;
    dfs(root, visited, res, kill, false);
    return res;
  }
private:
  void dfs(Node *root, unordered_set<int>& visited, vector<int>& res, int kill, bool found){
    if (!root)
      return;
    if (root -> val == kill)
      found = true;
    if (found)
      res.push_back(root -> val);
    for (auto child: root -> children){
      if (!visited.count(child -> val)){
        visited.insert(child -> val);
        dfs(child, visited, res, kill, found);
      }
    }
  }
};

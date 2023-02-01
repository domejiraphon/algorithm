/* 2246. Longest Path With Different Adjacent Characters
You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 
consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, 
where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.
*/
class Solution {
  int maxLength=0;
public:
  int longestPath(vector<int>& parent, string s) {
    int n=parent.size();
    vector<vector<int>> children(n);
    for (int i=1; i<n; i++){
      children[parent[i]].push_back(i);
    }
    dfs(0, children, s);
    return maxLength;
  }
private:
  int dfs(int cur, vector<vector<int>>& children, string& s){

    int first=0, second=0;
    for (auto child: children[cur]){
      int out = dfs(child, children, s);
      if (s[child] == s[cur])
        continue;
      
      if (out > first){
        second = first;
        first = out;
      }
      else
        second = max(second, out);
    }
    cur = first + second + 1;
    maxLength = max(maxLength, cur);
    return first + 1;
  }
};

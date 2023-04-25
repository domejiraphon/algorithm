/*
721. Accounts Merge

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
*/
class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, vector<string>> adj;
    
    for (auto account: accounts){
      int n=account.size();
      for (int i=2; i<n; i++){
        adj[account[1]].push_back(account[i]);
        adj[account[i]].push_back(account[1]);
      }
    }
    unordered_set<string> visited;
    vector<vector<string>> mergedAccounts;
    for (vector<string>& account : accounts) {
      if (!visited.count(account[1])){
        visited.insert(account[1]);
        vector<string> cur={account[0]};
        dfs(adj, visited, account[1], cur);
        sort(cur.begin() + 1, cur.end());
        mergedAccounts.push_back(cur);
      }
    }
    return mergedAccounts;
  }
private:
  void dfs(unordered_map<string, vector<string>>& adj, unordered_set<string>& visited, string& node, vector<string>& cur){
    cur.push_back(node);
    for (auto neigh: adj[node]){
      if (!visited.count(neigh)){
        visited.insert(neigh);
        dfs(adj, visited, neigh, cur);
      }
    }
  }
};

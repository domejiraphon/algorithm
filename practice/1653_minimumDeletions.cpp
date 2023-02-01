/*
1653. Minimum Deletions to Make String Balanced
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.


*/
class Solution {
public:
  int minimumDeletions(string s) {
    vector<int> aRightMost;
    vector<int> bLeftMost;
    int n=s.size();
    for (int i=0; i<n; i++){
      if (s[i] == 'a')
        aRightMost.push_back(i);
      int k=n-i-1;
      if (s[k] == 'b')
        bLeftMost.push_back(k);
    }
    
    vector<vector<int>> memo(aRightMost.size(), vector<int> (bLeftMost.size(), -1));
    return helper(aRightMost, bLeftMost, aRightMost.size() - 1, bLeftMost.size() - 1, memo);
  }
private:
  int helper(vector<int>& a, vector<int>& b, int i, int j, vector<vector<int>>& memo){
    if (i < 0 || j < 0)
      return 0;
    if (memo[i][j] != -1)
      return memo[i][j];
      
    if (a[i] < b[j])
      return memo[i][j] = 0;
    
    int val=INT_MAX;
   
    val = min({val, 1 + helper(a, b, i - 1, j, memo), 1 + helper(a, b, i, j - 1, memo)});
   
    return  memo[i][j] = val;
  }
};

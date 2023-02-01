/*
140. Word Break II
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/
class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    int n=s.size();
    vector<vector<string>> dp(n+1);
    unordered_set<string> dict = {wordDict.begin(), wordDict.end()};
    for (int i=1; i<=n; i++){
      for (int j=0; j<i; j++){
        
        string suffix = s.substr(j, i - j);
       
        if (j == 0 && dict.count(suffix))
          dp[i].push_back(suffix);
        else if (dict.count(suffix)){
          for (int k=0; k<dp[j].size(); k++){
            dp[i].push_back(dp[j][k] + " "+suffix);
          }
        }
     
      }
    }
   
    return dp[n];
  }
};

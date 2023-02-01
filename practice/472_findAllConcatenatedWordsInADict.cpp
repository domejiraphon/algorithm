/* 472. Concatenated Words
Given an array of strings words (without duplicates), 
return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised 
entirely of at least two shorter words in the given array.
*/
class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> dict = {words.begin(), words.end()};
    int n=words.size();
    vector<string> res;
    for (auto word: words){
      int m=word.size();
      vector<bool> dp(m+1, false);
      dp[0] = true;
      for (int i=1; i<=m; i++){
        for (int j= (i==m) ? 1: 0; j< i && !dp[i]; j++){
          dp[i] = dp[j] && dict.count(word.substr(j, i - j));
        }
      }
      if (dp[m])
        res.push_back(word);
      
    }
    return res;
  }
};
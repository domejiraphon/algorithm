/* 472. Concatenated Words
Given an array of strings words (without duplicates), 
return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised 
entirely of at least two shorter words in the given array.
*/
class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> dict(words.begin(), words.end());
    vector<string> out;
    for (auto word: words){
      int n = word.size();
      vector<bool> check;
      check.resize(n + 1);
      check[0] = true;
      for (int i=1; i<= n; i++){
        
        for (int j= (i == n ? 1 : 0); j< i && !check[i]; j++){
          check[i] = check[j] && dict.count(word.substr(j, i - j));
        }
      }
      if (check[n]){
        out.push_back(word);
      }
    }
    return out;
  }
};


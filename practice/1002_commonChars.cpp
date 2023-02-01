/*
1002. Find Common Characters
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
*/
class Solution {
public:
  vector<string> commonChars(vector<string>& words) {
    int n=words.size();
    vector<vector<int>> freq(n, vector<int>(26, 0));
    for (int i=0; i<n; i++){
      for (auto ch: words[i])
        freq[i][ch - 'a']++;
    }
    vector<string> res;
    for (int i=0; i<26; i++){
      int minF=INT_MAX;
      for (int j=0; j<n; j++)
        minF = min(minF, freq[j][i]);
      for (int j=0; j<minF; j++)
        res.push_back(string(1, i + 'a'));
    }
    return res;
  }
};

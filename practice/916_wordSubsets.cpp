/*
916. Word Subsets

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.
*/
class Solution {
public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    int n=words1.size(), m=words2.size();
    vector<int> freq2 = getFreq(words2[0]);
    for (int i=1; i<m; i++){
      vector<int> cur = getFreq(words2[i]);
      for (int j=0; j<26; j++)
        freq2[j] = max(freq2[j], cur[j]);
    }
    vector<string> res;
    for (int i=0; i<n; i++){
      vector<int> cur = getFreq(words1[i]);
      bool uni = true;
      for (int j=0; j<26 && uni; j++){
        if (cur[j] < freq2[j])
          uni = false;
      }
      if (uni)
        res.push_back(words1[i]);
    }
    return res;

  }
private:
  vector<int> getFreq(string& word){
    int n = word.size();
    vector<int> freq(26, 0);
    for (int i=0; i<n; i++)
      freq[word[i] - 'a']++;
    return freq;
  }
};

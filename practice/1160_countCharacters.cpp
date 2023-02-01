/*
1160. Find Words That Can Be Formed by Characters
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.
*/
class Solution {
public:
  int countCharacters(vector<string>& words, string chars) {
    int freq[26];
    memset(freq, 0, sizeof(freq));
    for (auto ch: chars)
      freq[ch - 'a']++;
    
    int n=words.size();
    int freqWords[26];
    int count=0;
    for (int i=0; i<n; i++){
      memset(freqWords, 0, sizeof(freqWords));
      for (auto ch: words[i]){
        freqWords[ch - 'a']++;
      }
      bool good = true;
      for (int i=0; i<26 && good; i++){
        if (freqWords[i] > freq[i])
          good = false;
      }
      if (good)
        count += words[i].size();
    }
    return count;
  }
};

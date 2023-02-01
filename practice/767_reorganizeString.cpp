/*
767. Reorganize String
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.
*/
class Solution {
public:
  string reorganizeString(string s) {
    vector<int> freq(26, 0);
    int n=s.size();
    for (int i=0; i<n; i++){
      freq[s[i] - 'a']++;
    }
    int maxFreq=0, maxCh;
    for (int i=0; i<26; i++){
      if (freq[i] > maxFreq){
        maxFreq = freq[i];
        maxCh = i;
      }
    }
    if (maxFreq > (n + 1) / 2)
      return "";
    int idx = 0;
    string out = s;
    while (freq[maxCh] > 0){
      out[idx] = maxCh + 'a';
      idx += 2;
      freq[maxCh]--;
    }
    for (int i=0; i<26; i++){
      while (freq[i] > 0){
        if (idx >= n)
          idx = 1;
        out[idx] = i + 'a';
        idx += 2;
        freq[i]--;
      }
    }
    return out;
  }
};
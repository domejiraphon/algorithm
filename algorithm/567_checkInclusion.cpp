/*
567. Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
*/
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    int freq1[26];
    memset(freq1, 0, sizeof(freq1));
    int freq2[26];
    memset(freq2, 0, sizeof(freq2));
    int n=s1.size(), m=s2.size();
    for (int i=0; i<n; i++){
      freq1[s1[i] - 'a']++;
      freq2[s2[i] - 'a']++;
    }
    for (int i=n; i<m; i++){
      if (check(freq1, freq2))
        return true;
      freq2[s2[i] - 'a']++;
      freq2[s2[i-n] - 'a']--;
    }
    return check(freq1, freq2);
  }
private:
  bool check(int freq1[26], int freq2[26]){
    for (int i=0; i<26; i++){
      if (freq1[i] != freq2[i])
        return false;
    }
    return true;
  }
};

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int freq1[26];
    memset(freq1, 0, sizeof(freq1));
    for (auto ch: s1)
      freq1[ch - 'a']++;
    int freq2[26];
    memset(freq2, 0, sizeof(freq2));
    int right=0;
    int n=s2.size();
    while (right<n){
      if (freq1[s2[right] - 'a'] == 0){
        right++; continue;
      }
      else {
        int temp=right;
        while (right < n && freq1[s2[right] - 'a'] != freq2[s2[right] - 'a']){
          freq2[s2[right] - 'a']++;
          right++;
        }
        bool similar=true;
        for (int i=0; i<26 && similar; i++){
          if (freq1[i] != freq2[i])
            similar = false;
        }
        if (similar)
          return true;
        memset(freq2, 0, sizeof(freq2));
        right = temp + 1;
      }
    }
    return false;
  }
};

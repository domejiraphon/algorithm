/*
383. Ransom Note
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int freqM[26];
    int freqR[26];
    memset(freqM, 0, sizeof(freqM));
    memset(freqR, 0, sizeof(freqR));
    for (auto ch: ransomNote)
      freqR[ch - 'a']++;
    for (auto ch: magazine)
      freqM[ch - 'a']++;
    for (int i=0; i<26; i++)
      if (freqM[i] < freqR[i])
        return false;
    return true;
    
  }
};

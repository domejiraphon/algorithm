/*
242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/
class Solution {
public:
  bool isAnagram(string s, string t) {
    int freqS[26] = {};
    int freqT[26] = {};
    for (auto ch: s)
      freqS[ch - 'a']++;
    for (auto ch: t)
      freqT[ch - 'a']++;
    for (int i=0; i<26; i++)
      if (freqS[i] != freqT[i])
        return false;
    return true;
  }
};
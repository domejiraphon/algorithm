/*
1657. Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
*/
class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size())
      return false;
    int freq1[26];
    int freq2[26];
    memset(freq1, 0, sizeof(freq1));
    memset(freq2, 0, sizeof(freq2));
    for (auto ch: word1)
      freq1[ch - 'a']++;
    for (auto ch: word2)
      freq2[ch - 'a']++;
    vector<char> ch1;
    vector<char> ch2;
    for (int i=0; i<26; i++){
      if (freq1[i] != 0)
        ch1.push_back(i + 'a');
      if (freq2[i] != 0)
        ch2.push_back(i + 'a');
    }
    sort(ch1.begin(), ch1.end());
    sort(ch2.begin(), ch2.end());
    if (ch1 != ch2)
      return false;
    sort(freq1, freq1 + 26);
    sort(freq2, freq2 + 26);
    for (int i=0; i<26; i++)
      if (freq1[i] != freq2[i])
        return false;
    return true;
  }
};

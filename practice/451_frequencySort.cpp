/*
451. Sort Characters By Frequency
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
*/
class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> freq;
    int n=s.size();
    for (int i=0; i<n; i++)
      freq[s[i]]++;
    sort(s.begin(), s.end(), [&freq](char & a, char& b){
      return freq[a] == freq[b] ? a < b : freq[a] > freq[b];
    });
    return s;
  }
};

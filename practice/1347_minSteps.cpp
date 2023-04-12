/*
1347. Minimum Number of Steps to Make Two Strings Anagram
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
*/
class Solution {
public:
  int minSteps(string s, string t) {
    int freq[26] = {};
    int n=s.size();
    for (int i=0; i<n; i++){
      freq[s[i] - 'a']++;
      freq[t[i] - 'a']--;
    }
    int count=0;
    for (int i=0; i<26; i++)
      count += max(freq[i], 0);
    return count;
  }
};
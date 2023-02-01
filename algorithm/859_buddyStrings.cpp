/*
859. Buddy Strings
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
*/
class Solution {
public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size())
      return false;
    if (s == goal){
      int freq[26];
      memset(freq, 0, sizeof(freq));
      for (auto ch: s)
        freq[ch - 'a']++;
      for (int i=0; i<26; i++)
        if (freq[i] > 1)
          return true;
      return false;
    }
    int n=s.size();
    int prev = -1, cur = -1;
    for (int i=0; i<n && cur == -1; i++){
      if (s[i] != goal[i]){
        if (cur == -1 && prev != -1)
          cur = i;
        if (prev == -1)
          prev = i;
        
      }
    }
    if (prev == -1 || cur == -1)
      return false;
    swap(s[prev], s[cur]);
    
    return s == goal;
  }
};

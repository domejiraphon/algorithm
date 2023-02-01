/*
1119. Remove Vowels from a String
Given a string s, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.
*/
class Solution {
public:
  string removeVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int i=0;
    while (i<s.size()){
      if (vowels.count(s[i]))
        s.erase(i, 1);
      else
        i++;
    }
    
    return s;
  }
};

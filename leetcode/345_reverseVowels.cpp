/*
345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/
class Solution {
public:
  string reverseVowels(string s) {
    vector<int> res;
    int n=s.size();
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i=0; i<n; i++){
      if (vowels.count(s[i]))
        res.push_back(i);
    }
    int left=0, right = res.size() - 1;
    while (left < right){
      swap(s[res[left++]], s[res[right--]]);
    }
    return s;
  }
};

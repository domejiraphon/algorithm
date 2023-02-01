/*
345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/
class Solution {
public:
  string reverseVowels(string s) {
    int n=s.size();
    int left=0;
    int right = n - 1;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    while (left <= right){
      while (left <= right && !vowels.count(s[left]))
        left++;
      while (left <= right && !vowels.count(s[right]))
        right--;
      if (left > right)
        break;
    
      swap(s[left++], s[right--]);
      
    }
    return s;
    
  }
};
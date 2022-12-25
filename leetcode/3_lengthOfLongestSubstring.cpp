/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest 
substring without repeating characters.
*/
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int left(0), right(0), n(s.size());
    unordered_map<char, int> hash;
    int out(0);
    while (right < n){
      char cur = s[right];
      hash[cur]++;
      while (hash[cur] > 1){
        char l = s[left];
        hash[l]--;
        left++;
      }
      out = max(right - left + 1, out);
      right++;
    }
    return out;
  }
};
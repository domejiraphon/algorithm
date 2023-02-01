/*
340. Longest Substring with At Most K Distinct Characters

Given a string s and an integer k, return the length of the longest 
substring
 of s that contains at most k distinct characters.
*/
class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int left=0, right=0;
    int n=s.size();
    unordered_map<char, int> freq;
    
    int length = 0;
    while (right < n){
      freq[s[right++]]++;
      while (left < right && freq.size() > k){
        freq[s[left]]--;
        if (freq[s[left]] == 0)
          freq.erase(s[left]);
        left++;
      }
      length = max(length, right - left);
    }
    return length;
  }
};

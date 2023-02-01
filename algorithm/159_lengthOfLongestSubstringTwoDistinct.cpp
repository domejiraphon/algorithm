/*
159. Longest Substring with At Most Two Distinct Characters
Given a string s, return the length of the longest 
substring
 that contains at most two distinct characters.
*/
class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int left=0, right=0;
    int n=s.size();
    unordered_map<char, int> map;
    int maxVal = INT_MIN;
    while (right < n){
      map[s[right]] = right;
      while (map.size() == 3){
        if (map[s[left]] == left)
          map.erase(s[left++]);
        else
          left++;
       
      }
      maxVal = max(maxVal, right - left + 1);
      right++;
    }
    return maxVal;
  }
};

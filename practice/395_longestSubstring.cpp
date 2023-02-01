/*
395. Longest Substring with At Least K Repeating Characters
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
*/
class Solution {
public:
  int longestSubstring(string s, int k) {
    int n=s.size();
    int freq[26];
    int maxVal = 0;
    for (int i=0; i<n; i++){
      memset(freq, 0, sizeof(freq));
      for (int j=i; j<n; j++){
        freq[s[j] - 'a']++;
        if (moreThan(freq, k))
          maxVal = max(maxVal, j - i+1);
      }
    }
    return maxVal;
  }
private:
  bool moreThan(int freq[26], int k){
    for (int i=0; i<26; i++){
      if (freq[i] ==0)
        continue;
      if (freq[i] < k)
        return false;
    }
    return true;
  }
};
class Solution {
public:
  int longestSubstring(string s, int k) {
    unordered_set<char> u = {s.begin(), s.end()};
    int unique = u.size();
    int freq[26];
    int maxVal=0;
    for (int i=1; i<=unique; i++){
      memset(freq, 0, sizeof(freq));
      int left = 0, right = 0;
      int n=s.size(), cur = 0;
      int countAtLeastK=0;
    
      while (left <= right && right < n){
        if (cur <= i){
          int idx = s[right] - 'a';
          if (freq[idx] == 0)
            cur++;
          freq[idx]++;
          if (freq[idx] == k)
            countAtLeastK++;
          right++;
        }
        else {
          int idx = s[left] - 'a';
          if (freq[idx] == k)
            countAtLeastK--;
          freq[idx]--;
          if (freq[idx] == 0)
            cur--;
          
          left++;
        }
        if (countAtLeastK == cur && cur == i)
          maxVal = max(maxVal, right - left);
        
      }
    }
    return maxVal;
  }
};
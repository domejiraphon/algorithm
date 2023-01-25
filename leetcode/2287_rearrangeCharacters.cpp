/*
2287. Rearrange Characters to Make Target String
You are given two 0-indexed strings s and target. You can take some letters from s and rearrange them to form new strings.

Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.
*/
class Solution {
public:
  int rearrangeCharacters(string s, string target) {
    int freqS[26], freqT[26];
    memset(freqS, 0, sizeof(freqS));
    memset(freqT, 0, sizeof(freqT));
    for (auto ch: s)
      freqS[ch - 'a']++;
    for (auto ch: target)
      freqT[ch - 'a']++;
    int times=INT_MAX;
    for (int i=0; i<26; i++){
      if (freqT[i] != 0)
        times = min(times, freqS[i] / freqT[i]);
    }
    return times;
  }
};

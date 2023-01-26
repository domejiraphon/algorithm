/*
763. Partition Labels
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.
*/
class Solution {
public:
  vector<int> partitionLabels(string s) {
    int freq[26];
    memset(freq, 0, sizeof(freq));
    for (auto ch: s)
      freq[ch - 'a']++;
    vector<int> res;
    int left=0, right = 0;
    int n=s.size();
    int cur[26];
    while (right < n){
      memset(cur, 0, sizeof(cur));
      
      cur[s[right++] - 'a']++;
      while (right < n && !checkPartition(freq, cur)){
        cur[s[right++] - 'a']++;
      }
      
      res.push_back(right - left);
      left = right;
    }
    return res;
  }
private:
  bool checkPartition(int freq[26], int cur[26]){
    for (int i=0; i<26; i++){
      if (cur[i] == 0)
        continue;
      if (freq[i] != cur[i])
        return false;
    }
    return true;
  }
};
/*
2405. Optimal Partition of String
Given a string s, partition the string into one or more substrings 
such that the characters in each substring are unique. 
That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.
*/
class Solution {
public:
  int partitionString(string s) {
    int n=s.size();
    int freq[26];
    int res=1;
    memset(freq, 0, sizeof(freq));
    for (int i=0; i<n; i++){
      int cur = s[i] - 'a';
      if (freq[cur] == 1){
        memset(freq, 0, sizeof(freq));
        freq[cur]++;
        res++;
      }
      else if (freq[cur] == 0)
        freq[cur]++;
    }
    return res;
  }
};

/*
791. Custom Sort String
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
*/
class Solution {
public:
  string customSortString(string order, string s) {
    string res="";
    int freq[26];
    memset(freq, 0, sizeof(freq));
    int n=s.size();
    for (int i=0; i<n; i++)
      freq[s[i] - 'a']++;
    int m=order.size();
    for (int i=0; i<m; i++){
      int num = freq[order[i] - 'a'];
      if (num > 0){
        res += string(num, order[i]);
        freq[order[i] - 'a'] = 0;
      } 
    }
    
    for (int i=0; i<26; i++){
      if (freq[i] > 0)
        res += string(freq[i], i + 'a');
    }
    //cout << res << endl; exit(0);
    return res;
  }
};

class Solution {
public:
  string customSortString(string order, string s) {
    vector<int> rank(26, INT_MAX);
    int n=order.size();
    for (int i=0; i<n; i++)
      rank[order[i] - 'a'] = i;
    sort(s.begin(), s.end(), [&rank](char& a, char& b){
      return rank[a - 'a'] < rank[b - 'a'];
    });
    return s;
  }
};
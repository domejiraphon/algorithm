/*
267. Palindrome Permutation II
Given a string s, return all the palindromic permutations (without duplicates) of it.

You may return the answer in any order. If s has no palindromic permutation, return an empty list.
*/
class Solution {
public:
  vector<string> generatePalindromes(string s) {
    int freq[26];
    memset(freq, 0, sizeof(freq));
    int n=s.size();
    for (int i=0; i<n; i++)
      freq[s[i] - 'a']++;
    int odd=0;
    for (int i=0; i<26 && odd < 2; i++)
      odd += freq[i] % 2;
    if (odd == 2)
      return vector<string> {};
    vector<string> res;
    string cur=s;
    if (n % 2 == 1){
      for (int i=0; i<26; i++){
        if (freq[i] % 2 == 1){
          cur[n/2] = i + 'a';
          freq[i] -= 1;
          break;
        }
      }
    }
    
    helper(freq, cur, 0, n, res);
    return res;
  }
private:
  void helper(int freq[26], string& cur, int idx, int& n, vector<string>& res){
    if (idx == n /2){
      res.push_back(cur);
      return;
    }
    
    for (int i=0; i<26; i++){
      if (freq[i] > 1){
        cur[idx] = i + 'a'; cur[n-idx-1] = i + 'a';
        freq[i] -= 2;
        helper(freq, cur, idx + 1, n, res);
        freq[i] += 2;
      }
      
    }
    return;
  }
};

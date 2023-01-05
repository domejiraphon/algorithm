/* 409. Longest Palindrome
Given a string s which consists of lowercase or uppercase letters, 
return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

*/
class Solution {
public:
  int longestPalindrome(string s) {
    int freq[52];
    memset(freq, 0, sizeof(freq));
    
    for (auto ch: s){
      int hash = ch - 'a';
      if (hash < 0){
        hash += 32 + 26;
      }
      freq[hash]++;
    }
      
    int res=0;
    bool firstOdd=true;
    for (int i=0; i<52; i++){
      if (freq[i] % 2 == 0)
        res += freq[i];
      else{
        res += freq[i] - 1;
        if (firstOdd){
          res += 1;
          firstOdd = false;
        }
      } 
    }
    return res;
  }
};
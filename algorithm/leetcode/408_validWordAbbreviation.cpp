/*
408. Valid Word Abbreviation
A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)
The following are not valid abbreviations:

"s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
"s010n" (has leading zeros)
"s0ubstitution" (replaces an empty substring)
Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.
*/
class Solution {
  int n, m;
public:
  bool validWordAbbreviation(string word, string abbr) {
    n=word.size();
    m=abbr.size();
    int i=0, k=0;
    while (i < n && k < m){
      if (!isdigit(abbr[k])){
        if (word[i] == abbr[k]){
          i++; k++;
          continue;
        }
        else 
          return false;
      }
      else {
        int num = getNumber(abbr, k);
        i += num; 
      }
    }
    //cout << i << "::"<< k;
    return (i == n && k == m) ? true : false;
  }
private:
  int getNumber(string& abbr, int& k){
    int cur=0;
    if (abbr[k] == '0')
      return 10;
    while (k <m && isdigit(abbr[k])){
      cur = 10 * cur + (abbr[k++] - '0');
    }
  
    return cur;
  }
};
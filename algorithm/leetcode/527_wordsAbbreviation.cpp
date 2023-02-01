/*
527. Word Abbreviation
Given an array of distinct strings words, return the minimal possible abbreviations for every word.

The following are the rules for a string abbreviation:

The initial abbreviation for each word is: the first character, then the number of characters in between, followed by the last character.
If more than one word shares the same abbreviation, then perform the following operation:
Increase the prefix (characters in the first part) of each of their abbreviations by 1.
For example, say you start with the words ["abcdef","abndef"] both initially abbreviated as "a4f". Then, a sequence of operations would be ["a4f","a4f"] -> ["ab3f","ab3f"] -> ["abc2f","abn2f"].
This operation is repeated until every abbreviation is unique.
At the end, if an abbreviation did not make a word shorter, then keep it as the original word.
*/
class Solution {
public:
  vector<string> wordsAbbreviation(vector<string>& words) {
    int n = words.size();
    vector<string> res(n);
    int prefix[n];
    memset(prefix, 0, sizeof(prefix));
    for (int i=0; i<n; i++)
      res[i] = abbrev(words[i], 0);
    for (int i=0; i<n; i++){
      unordered_set<int> dupes;
      while (true){
        dupes.clear();
        for (int j=i+1; j<n; j++){
          if (res[i] == res[j])
            dupes.insert(j);
        }
        
        if (dupes.empty()){
          break;
        }
          
        dupes.insert(i);
        for (auto it=dupes.begin(); it != dupes.end(); it++){
          res[*it] = abbrev(words[*it], ++prefix[*it]);
        }
        
      }
    }
    return res;
  }
private:
  string abbrev(string& word, int i){
    int n=word.size();
    if (n - i <= 3)
      return word;
    return word.substr(0, i+1) + to_string(n-i-2) + word.back();
  }
};

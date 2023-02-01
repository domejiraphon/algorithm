/*
819. Most Common Word
Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.
*/
class Solution {
public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> ban = {banned.begin(), banned.end()};
    unordered_map<string, int> freq;
    unordered_set<char> remove = {' ', ',', '!', '?', '\'', ';', '.'};
    string cur="";
    int n=paragraph.size();
    for (int i=0; i<=n; i++){
      if (i == n || remove.count(paragraph[i])){
        //cout << cur <<", "<<cur.size()<<endl;
        if (!ban.count(cur) && cur.size() > 0)
          freq[cur]++;
        cur="";
      }
      else{
        cur += convert(paragraph[i]);
       
      }
        
    }
    string out;
    int minF = 0;
    for (auto it: freq){
      //cout << it.first << ", "<<it.second<<endl;
      if (it.second > minF){
        out = it.first;
        minF = it.second;
      }
    }
    return out;
    
  }
private:
  char convert(char ch){
    if (ch - 'A' >= 0 && ch - 'A' < 26) 
      return ch - 'A' + 'a';
    else if (ch - 'a' >= 0 && ch - 'a'<26)
      return ch;
    else
      return '!';
  }
};

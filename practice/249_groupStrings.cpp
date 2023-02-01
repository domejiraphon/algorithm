/*
249. Group Shifted Strings
We can shift a string by shifting each of its letters to its successive letter.

For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.

For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.
*/
class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    string cur;
    unordered_map<string, vector<string>> groups;
    for(auto word: strings){
      cur.clear();
      hash(word, cur);
      //getDiff(word, cur);
      groups[cur].push_back(word);
    }
    vector<vector<string>> res;
    for (auto it=groups.begin(); it != groups.end(); it++)
      res.push_back(it -> second);
    return res;
  }
private:
  void getDiff(string& word, vector<int>& res){
    int n=word.size();
    int val;
    for (int i=1; i<n; i++){
      val = word[i] - word[i - 1];
      if (val < 0)
        val += 26;
      res.push_back(val);
    }
  }
  void hash(string& word, string& res){
    int n=word.size();
    for (int i=1; i<n; i++){
      res += (word[i] - word[i - 1] + 26) % 26 + 'a';
    }
  }
};

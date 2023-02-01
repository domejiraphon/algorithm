/*
49. Group Anagrams

Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n=strs.size();
    vector<vector<string>> res;
    unordered_map<string, vector<string>> groups;
    for (int i=0; i<n; i++){
      string tmp = strs[i];
      sort(tmp.begin(), tmp.end());
      groups[tmp].push_back(strs[i]);
    }
    for (auto it=groups.begin(); it!=groups.end(); it++){
      res.push_back(it -> second);
    }
    return res;
  }
};
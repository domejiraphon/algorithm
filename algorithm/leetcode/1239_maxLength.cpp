/* 1239. Maximum Length of a Concatenated String with Unique Characters
You are given an array of strings arr.
A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
*/
class Solution {
public:
  int maxLength(vector<string>& arr) {
    vector<string> tmp = {""};
    int length=0;
    for (string word: arr){
      int n=tmp.size();
      for (int i=0; i<n; i++){
        string cur = tmp[i] + word;
        unordered_set<char> dup = {cur.begin(), cur.end()};
        if (cur.size() == dup.size()){
          tmp.push_back(cur);
          length = max(length, (int) cur.size());
        }
      }
    }
    return length;
  }
};

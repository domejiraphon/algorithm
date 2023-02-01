/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string res="";
    int n=strs.size();
    int k=0;
    while (true){
      bool same=true;
      char first = strs[0][k];
      for (auto str: strs){
        if (k < str.size()) {same = same && (first == str[k]);}
        else {same = false; break;}
        if (!same){break;}
      }
      if (same){res += first;}
      else {break;}
      k++;
    }
    return res;
  }
};
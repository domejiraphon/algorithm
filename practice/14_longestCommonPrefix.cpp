/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int n=strs.size();
    string prefix = strs[0];
    for (int i=1; i<n && prefix.size() > 0; i++){
      int idx = findPrefix(prefix, strs[i]);
      prefix = prefix.substr(0, idx);
    }
    return prefix;
  }
private:
  int findPrefix(string& str1, string& str2){
    int left=0;
    int right=0;
    int n=str1.size(), m=str2.size();
    for (; left < n && right < m && str1[left] == str2[right]; left++, right++)
      ;
    return left;
  }
};
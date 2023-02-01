/*
151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters.
 The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.
*/
class Solution {
public:
  string reverseWords(string s) {
    int n=s.size();
    vector<string> split;
    string cur="";
    for (int i=0; i<=n; i++){
      if (i == n || s[i] == ' '){
        if (cur != "")
          split.push_back(cur);
        cur = "";
        continue;}
      cur += s[i];
    }
    n = split.size();
    int left=0, right = n - 1;
    while (left < right){
      swap(split[left++], split[right--]);
    }
    string out="";
    for (int i=0; i<n; i++){out += split[i] + " ";}
    return out.substr(0, out.size() - 1);
  }
};